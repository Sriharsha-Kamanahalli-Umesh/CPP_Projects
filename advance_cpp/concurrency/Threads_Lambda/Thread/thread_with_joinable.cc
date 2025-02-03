#include <iostream>
#include <thread>

void task()
{
    std::cout << "Thread task is executing.\n";
}

int main()
{
    std::thread t1(task);
    // Always check if the thread is joinable before joining or detaching.
    if (t1.joinable())
    {
        // Ensure that the thread finishes before the main thread proceeds
        t1.join();
        std::cout << "Thread joined. \n";
    }
    std::cout << "Main thread continues after the task thread has finished.\n";
    return 0;
}
