#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

class WorkerThreadFunctor
{
public:
    void operator()()     
    {
        std::cout<<"Worker Thread "<<std::this_thread::get_id()<<" is Executing"<<std::endl;
    }
};

int main()  
{
    // Create a Vector of Thread
    std::vector<std::thread> threadList;
    // Add 10 thread objects in vector
    for(int i = 0; i < 10; i++)
    {
        threadList.push_back( std::thread( WorkerThreadFunctor() ) );
    }
    std::cout<<"wait for all the worker thread to finish"<<std::endl;
    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
    for (auto& th: threadList)
    {
        th.join();
    }
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;
}