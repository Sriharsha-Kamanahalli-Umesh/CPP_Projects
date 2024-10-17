#include <iostream>
#include <thread>

auto lambda = [] () {
    for(int i = 0; i < 5; ++i) {
        std::cout << "Display Thread Executing" << std::endl;
        std::cout<< "thread id within the thread function:"<< std::this_thread::get_id()<<"\n";
    }
};

int main()
{
    // Create a Thread from Lambda function
    std::thread threadObj(lambda);
    for (int i = 0; i < 5; i++)
        std::cout << "Display From Main Thread" << std::endl;
    // Wait for the thread to finish
    std::cout<< "thread id within the thread function:"<< threadObj.get_id()<<"\n";
    threadObj.join();
    std::cout << "Exiting from Main Thread" << std::endl;
    return 0;
}