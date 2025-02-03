#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// A function that simulates a time-consuming task
int longTask(int x)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return x * x;
}

int main()
{
    // Using std::launch::async to run the task in a new thread
    std::future<int> asyncResult = std::async(std::launch::async, longTask, 5);

    // Using std::launch::deferred to defer the task execution
    std::future<int> deferredResult = std::async(std::launch::deferred, longTask, 5);

    // Do other work while the async task is running
    std::cout << "Doing other work...\n";

    // Get the result from the async task (this will block until the task is complete)
    int asyncValue = asyncResult.get();
    std::cout << "Async Result: " << asyncValue << "\n";

    // Get the result from the deferred task (this will execute the task and block until it completes)
    int deferredValue = deferredResult.get();
    std::cout << "Deferred Result: " << deferredValue << "\n";

    return 0;
}
