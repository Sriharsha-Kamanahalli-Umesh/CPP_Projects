#include <iostream>
#include <thread>

// A function that will print a message 5 times
void thread_function()
{
    for (int i = 0; i < 200; i++)
    {
        std::cout << "thread function Executing" << std::endl;
    }
}

int main()
{
    // Create a Thread object
    std::thread threadObj(thread_function);
    for (int i = 0; i < 200; i++)
    {
        std::cout << "Display From MainThread" << std::endl;
    }    
    // Wait for the thread to finish
    threadObj.join();
    // threadObj.join();
    std::cout << "Exit of Main function" << std::endl;
    return 0;
}