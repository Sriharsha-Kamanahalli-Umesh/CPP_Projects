



#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <map>
#include <atomic>

using namespace std;

constexpr uint8_t th_num_of_upload = 6U;
constexpr uint8_t upper_limit = 1U;
constexpr float STRBPOR_TH = 0.5;
double eps = std::numeric_limits<double>::epsilon();

enum class State { OFF, ON, WAIT, ACTION };

enum class ORState { NO_OCCURENCE, ORSTR, ORBP, ORAP };

enum class IGState { OFF, ON };

std::ostream& operator<<(std::ostream& os, ORState const& ors) {
    switch(ors) {
        case ORState::ORSTR: return os << "ORSTR";
        case ORState::ORBP: return os << "ORBP";
        case ORState::ORAP: return os << "ORAP";
    }
    return os;
}

struct UploadDataManagementTable {
    uint32_t nNumOfStrOr;
    uint32_t nNumOfBpOr;
    uint32_t nNumOfSApOr;
};

struct UFS
{
    uint32_t numOfStrOR = 5;
    uint32_t numOfBpOR = 4;
    uint32_t numOfApOR = 10;
};

class RAM
{
public:
    uint32_t num_of_str_or;
    uint32_t num_of_bp_or;
    uint32_t num_of_ap_or;
    uint32_t num_of_high_priority_trigger;
};

struct trigger_msg
{
    uint8_t trigger_id;
    uint64_t sec;
    uint64_t nsec;
};


class TriggerLogic
{
public:
    UFS ufsObj;
    RAM ramObj;
    trigger_msg trigger_msgObj;
    bool FunctionA()
    {
        cout << "Inside Function A "<<endl;
        ramObj.num_of_str_or = ufsObj.numOfStrOR;
        ramObj.num_of_bp_or = ufsObj.numOfBpOR;
        ramObj.num_of_ap_or = ufsObj.numOfApOR;

        return true;
    }
    bool FunctionB()
    {
        cout << "Inside Function B "<<endl;
        cout<< ramObj.num_of_high_priority_trigger <<endl;
        cout<< ramObj.num_of_str_or <<endl;
        cout<< ramObj.num_of_bp_or <<endl;
        cout<< ramObj.num_of_ap_or <<endl;

        if ((ramObj.num_of_high_priority_trigger < th_num_of_upload) && (ramObj.num_of_str_or > upper_limit) && (ramObj.num_of_bp_or > upper_limit) && (ramObj.num_of_ap_or > upper_limit))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void FunctionC(ORState orState)
    {
        cout << "Inside Function C "<<endl;
        float result1 = 0;
        float result2 = 0;
        float result3 = 0.0f;
        cout<< ufsObj.numOfStrOR <<endl;
        cout<< ufsObj.numOfBpOR <<endl;
        cout<< ufsObj.numOfApOR <<endl;
        if ((orState == ORState::ORSTR) || (orState == ORState::ORBP))
        {
            cout << "Inside 103 "<<endl;
            result1 = ufsObj.numOfStrOR + ufsObj.numOfBpOR;
            cout<<"result1 "<<result1<<endl;
        }
        else if (orState == ORState::ORAP)
        {
            result1 = ufsObj.numOfApOR;
        }

        result2 = ufsObj.numOfStrOR + ufsObj.numOfBpOR + ufsObj.numOfApOR;
         cout<<"result2 "<<result2<<endl;
        if (result2 != 0)
        {
            result3 = (result1/result2);
            cout << "result3 "<<result3<<endl;
        }
        else
        {
            result3 = result1 / eps; // eps is a small value to prevent division by zero
        }
        if ((orState == ORState::ORSTR) || (orState == ORState::ORBP))
        {
             cout << "Inside 127 "<<endl;
            if (result3 <= STRBPOR_TH)
            {
                trigger_msgObj.trigger_id = 2U;
                cout << "trigger_id  " << static_cast<int>(trigger_msgObj.trigger_id) <<"   line "<< __LINE__<< endl;
            }
            else
            {
                cout << "trigger_id  " << static_cast<int>(trigger_msgObj.trigger_id) <<"   line "<< __LINE__<< endl;
                ramObj.num_of_high_priority_trigger += 1;
                trigger_msgObj.trigger_id = 1;
                if (orState == ORState::ORSTR)
                {
                    ufsObj.numOfStrOR += 1;
                    ramObj.num_of_str_or += 1;
                }
                else
                {
                     cout << "Inside numOfBpOR "<<endl;
                    ufsObj.numOfBpOR += 1;
                    ramObj.num_of_bp_or += 1;
                }
            }
        }
        else
        {
            if (result3 <= (1 - STRBPOR_TH))
            {
                trigger_msgObj.trigger_id = 4;
            }
            else
            {
                ramObj.num_of_high_priority_trigger += 1;
                trigger_msgObj.trigger_id = 3;

                ufsObj.numOfApOR += 1;
                ramObj.num_of_ap_or += 1;
            }
        }
        cout << "trigger_id  " << static_cast<int>(trigger_msgObj.trigger_id) <<"   line "<< __LINE__<< endl;
    }

    void FunctionD(uint64_t nSec, uint64_t nNanoSec)
    {
        trigger_msgObj.sec = nSec;
        trigger_msgObj.nsec = nNanoSec;
    }

    ~TriggerLogic()
    {
    }
};

class StateHandler {
    public:
        StateHandler() : IG_STATE(static_cast<int>(IGState::ON)), OR_STATE(0), currentState(State::OFF), currentORState(ORState::NO_OCCURENCE) {
            currentState = State::ON;
            m_pTriggerLogic->FunctionA();
            setStatethread = std::thread(&StateHandler::StateTransition, this);
        }

        void setIGState(const IGState ig_state) {
            lock_guard<mutex> lock(mlock);
            IG_STATE = static_cast<int>(ig_state);
            CV.notify_one();
        }
        
        void setORState(const ORState &or_state) {
            lock_guard<mutex> lock(mlock);
            OR_STATE = static_cast<int>(or_state);
            CV.notify_one();
        }

        State getCurrentState() const {
            return currentState;
        }

        ORState getCurrentORState() const {
            return currentORState;
        }

        ~StateHandler() {
            cout << "Destructor called" << endl;
            lock_guard<mutex> lock(mlock);
            IG_STATE = static_cast<int>(IGState::OFF);
            CV.notify_all();
            if(setStatethread.joinable()) {
                cout << "setStatethread.joinable()" << endl;
                setStatethread.join();
            }
        }

    private:
        void StateTransition() {
            while (true) {
                std::unique_lock<std::mutex> ulock(mlock);
                if (IG_STATE == 1) {                                                                                                                
                    std::cout << "State: WAIT" << std::endl;
                    CV.wait(ulock, [&] { return OR_STATE != 0 || IG_STATE == 0; });
                    if (IG_STATE == 0) {
                        currentState = State::OFF;
                        std::cout << "State: OFF" <<" " << __LINE__ << std::endl;
                        break;
                    } else if (OR_STATE != 0) {
                        currentState = State::ACTION;
                        std::cout << "OR_STATE Has Notified " << static_cast<ORState>(OR_STATE) << std::endl;
                        std::cout << "Call to function B1 and B2" << std::endl;
                        auto res1 = m_pTriggerLogic->FunctionB();
                        std::cout << "Done with B1 and B2" << std::endl;
                        if (res1) {
                            std::cout << "Call to function C" << std::endl;
                            m_pTriggerLogic->FunctionC(static_cast<ORState>(OR_STATE));
                            m_pTriggerLogic->FunctionD(m_nSec, m_nNanoSec);
                        }
                        OR_STATE = static_cast<int>(ORState::NO_OCCURENCE);
                        currentState = State::WAIT;
                    }
                } else {
                    currentState = State::OFF;
                    std::cout << "State: OFF" << std::endl;
                    break;
                }
            }
        }

        std::thread setStatethread;
        std::shared_ptr<TriggerLogic> m_pTriggerLogic = std::make_shared<TriggerLogic>();
        int IG_STATE;
        int OR_STATE;
        State currentState;
        ORState currentORState;
        mutex mlock;
        condition_variable CV;
        uint8_t nNoOfHighPriorityTrigger{0U};
        int countThread{0U};
        uint64_t m_nSec;
        uint64_t m_nNanoSec;
};
































// class StateHandler {
//     public:
//         StateHandler() : IG_STATE(static_cast<int>(IGState::ON)), OR_STATE(0), currentState(State::OFF), currentORState(ORState::NO_OCCURENCE) {
//             currentState = State::ON;
//             m_pTriggerLogic->FunctionA();
//             setStatethread = std::thread(&StateHandler::StateTransition, this);
            
//         }

//         void CheckIGState() {
//             std::cout << "CheckIGState: CheckIGState" <<" " << __LINE__ << std::endl;
//             while(true) {
//                 std::cout << "CheckIGState: CheckIGState" <<" " << __LINE__ << std::endl;
//                 std::unique_lock<std::mutex> ulock(mlock);
//                 CV.wait(ulock, [&] { return IG_STATE == 0; });
//                 currentState = State::OFF;
//                 std::cout << "State: OFF" <<" " << __LINE__ << std::endl;
//                 break;
//             }
            
//         }

//         void setIGState(const IGState ig_state) {
//             lock_guard<mutex> lock(mlock);
//             IG_STATE = static_cast<int>(ig_state);
//             CV.notify_one();

//         }
        
//         void setORState(const ORState &or_state) {
//             lock_guard<mutex> lock(mlock);
//             OR_STATE = static_cast<int>(or_state);
//             CV.notify_one();
//                 // countThread++;
//         }

//         State getCurrentState() const {
//             return currentState;
//         }

//         ORState getCurrentORState() const {
//             return currentORState;
//         }

//         ~StateHandler() {
//             cout << "Destructor called" << endl;
//             lock_guard<mutex> lock(mlock);
//             IG_STATE = static_cast<int>(IGState::OFF);
//             CV.notify_all();
//             if(setStatethread.joinable()) {
//                 cout << "setStatethread.joinable()" << endl;
//                 setIGStateThread.join();
//                 setStatethread.join();
//             }
//         }

//     private:
//         void StateTransition() {
//             setIGStateThread = std::thread(&StateHandler::CheckIGState, this);
//             while (true) {
//                 std::unique_lock<std::mutex> ulock(mlock);
//                 if (IG_STATE == 1) {                                                                                                                
//                     std::cout << "State: WAIT" << std::endl;
//                     CV.wait(ulock, [&] { return OR_STATE != 0 || IG_STATE == 0; });
//                     if (IG_STATE == 0) {
//                         currentState = State::OFF;
//                         std::cout << "State: OFF" <<" " << __LINE__ << std::endl;
//                         break;
//                     } else if (OR_STATE != 0) {
//                         currentState = State::ACTION;
//                         std::cout << "OR_STATE Has Notified " << static_cast<ORState>(OR_STATE) << std::endl;
//                         std::cout << "Call to function B1 and B2" << std::endl;
//                         auto res1 = m_pTriggerLogic->FunctionB();
//                         std::cout << "Done with B1 and B2" << std::endl;
//                         if (res1) {
//                             std::cout << "Call to function C" << std::endl;
//                             m_pTriggerLogic->FunctionC(static_cast<ORState>(OR_STATE));
//                             m_pTriggerLogic->FunctionD(m_nSec, m_nNanoSec);
//                         }
//                         OR_STATE = static_cast<int>(ORState::NO_OCCURENCE);
//                         currentState = State::WAIT;
//                     }
//                 } else {
//                     currentState = State::OFF;
//                     std::cout << "State: OFF" << std::endl;
//                     break;
//                 }
//             }
//         }
//         std::thread setStatethread;
//         std::thread setORStateThread;
//         std::thread setIGStateThread;
//         std::shared_ptr<TriggerLogic> m_pTriggerLogic = std::make_shared<TriggerLogic>();
//         int IG_STATE;
//         int OR_STATE;
//         State currentState;
//         ORState currentORState;
//         mutex mlock;
//         condition_variable CV;
//         uint8_t nNoOfHighPriorityTrigger{0U};
//         int countThread{0U};
//         uint64_t m_nSec;
//         uint64_t m_nNanoSec;
//         // condition_variable CV;
// };































// // int main()
// // {
// //     int result = 0;
// //     bool notified = false;
// //     cout << "Execution begin " << endl;

// //     thread reporter([&]()
// //     {
// //         while (true) {
// //             unique_lock<mutex> ulock(mlock);
// //             if (IG_STATE == 1) {
// //                 currentState = State::WAIT;
// //                 //Go to wait state
// //                 cout << "State: WAIT" << endl;
// //                 CV.wait(ulock, [] { return OR_STATE != 0 || IG_STATE == 0; });
// //                 if (IG_STATE == 0) {
// //                     currentState = State::OFF;
// //                     cout << "State: OFF" << endl;
// //                     // go to OFF state
// //                     break;
// //                 } else if (OR_STATE != 0) {
// //                     currentState = State::ACTION;
// //                     // go to B1 And B2 state
// //                     // if resturn of B1 and B2 is true then go to C state
// //                     // Else return to wait state
// //                     cout << "State: ACTION" << " " << static_cast<ORState>(OR_STATE) << endl;
// //                     // Perform action
// //                 }
// //             } else {
// //                 currentState = State::OFF;
// //                 cout << "State: OFF" << endl;
// //                 break;
// //             }
// //         }
// //     });

// //     // Worker thread
// //     thread worker([&]()
// //     {
// //         this_thread::sleep_for(chrono::seconds(1)); // Simulate some work
// //         {
// //             lock_guard<mutex> lock(mlock);
// //             for(int i=0; i<3; i++){
// //                 cout << "Worker thread: " << i << endl;
// //                 OR_STATE = i;
// //                 CV.notify_all();
// //                 this_thread::sleep_for(chrono::seconds(5));
// //             }
// //              // Change OR_STATE to trigger ACTION state
// //         }
        
// //     });

// //     reporter.join();
// //     worker.join();

// //     cout << "Execution end " << endl;
//     // return 0;
// // }




   




// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>
// #include <memory>

// enum class State { OFF, ON, WAIT, ACTION };
// enum class IGState { OFF = 0, ON = 1 };
// enum class ORState { NO_OCCURENCE, ORSTR, ORBP, ORAP };

// class UploadDataManagementTable {
// public:
//     int nNumOfStrOr;
//     int nNumOfBpOr;
//     int nNumOfSApOr;
// };

// class StateMachine {
// public:
//     StateMachine() : IG_STATE(static_cast<int>(IGState::ON)), OR_STATE(0), currentState(State::OFF), currentORState(ORState::NO_OCCURENCE) {
//         setStatethread = std::thread(&StateMachine::stateHandler, this);
//     }

//     ~StateMachine() {
//         {
//             std::lock_guard<std::mutex> lock(mlock);
//             IG_STATE = static_cast<int>(IGState::OFF);
//             CV.notify_all();
//         }
//         if (setStatethread.joinable()) {
//             setStatethread.join();
//         }
//     }

//     void setIGState(const IGState ig_state) {
//         std::lock_guard<std::mutex> lock(mlock);
//         IG_STATE = static_cast<int>(ig_state);
//         CV.notify_one();
//     }

//     void setORState(const ORState &or_state) {
//         std::lock_guard<std::mutex> lock(mlock);
//         OR_STATE = static_cast<int>(or_state);
//         CV.notify_one();
//     }

// private:
//     void stateHandler() {
//         while (true) {
//             std::unique_lock<std::mutex> ulock(mlock);
//             if (IG_STATE == 1) {
//                 currentState = State::ON;
//                 auto mUploadDmtObj = GetUploadDataManagementTable();
//                 std::cout << "State: WAIT" << std::endl;
//                 CV.wait(ulock, [&] { return OR_STATE != 0 || IG_STATE == 0; });
//                 if (IG_STATE == 0) {
//                     currentState = State::OFF;
//                     std::cout << "State: OFF" << std::endl;
//                     break;
//                 } else if (OR_STATE != 0) {
//                     currentState = State::ACTION;
//                     // std::cout << "OR_STATE Has Notified " << static_cast<ORState>(OR_STATE) << std::endl;
//                     std::cout << "Call to function B1 and B2" << std::endl;
//                     auto res1 = functionB1();
//                     auto res2 = functionB2();
//                     if (res1 && res2) {
//                         std::cout << "Call to function C" << std::endl;
//                         functionC();
//                     }
//                     OR_STATE = static_cast<int>(ORState::NO_OCCURENCE);
//                     std::cout << "Done with B1 and B2" << std::endl;
//                     currentState = State::WAIT;
//                 }
//             } else {
//                 currentState = State::OFF;
//                 std::cout << "State: OFF" << std::endl;
//                 break;
//             }
//         }
//     }

//     std::unique_ptr<UploadDataManagementTable> GetUploadDataManagementTable() {
//         auto mUploadDmtObj = std::make_unique<UploadDataManagementTable>();
//         mUploadDmtObj->nNumOfStrOr = 2;
//         mUploadDmtObj->nNumOfBpOr = 4;
//         mUploadDmtObj->nNumOfSApOr = 6;
//         return mUploadDmtObj;
//     }

//     int functionB1() {
//         std::cout << "Function B1" << std::endl;
//         return 1;
//     }

//     int functionB2() {
//         std::cout << "Function B2" << std::endl;
//         return 1;
//     }

//     void functionC() {
//         std::cout << "Function C" << std::endl;
//         // Implement the logic for function C
//     }

//     std::thread setStatethread;
//     int IG_STATE;
//     int OR_STATE;
//     State currentState;
//     ORState currentORState;
//     std::mutex mlock;
//     std::condition_variable CV;
//     std::unique_ptr<UploadDataManagementTable> mUploadDmtObj{nullptr};
// }; 