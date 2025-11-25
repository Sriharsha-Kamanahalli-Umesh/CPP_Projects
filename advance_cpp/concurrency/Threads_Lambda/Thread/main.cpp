#include "condition_variable.h"

int main() {
    StateHandler mStateMachine;
    mStateMachine.setORState(ORState::ORSTR);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mStateMachine.setORState(ORState::ORAP);
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    mStateMachine.setORState(ORState::ORBP);
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    mStateMachine.setIGState(IGState::OFF);
    std::this_thread::sleep_for(std::chrono::seconds(2));


    return 0;
}