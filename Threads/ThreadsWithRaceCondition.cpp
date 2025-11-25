#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
// #include <lock_guard>

// Thread is the process of executing a sequence of instructions independently from other threads.
// Threads within the same process share the same memory space, which allows them to communicate 
// with each other more easily than if they were separate processes.
// threads can be used to perform multiple tasks concurrently, improving the performance of applications
// that require parallel processing.
// Thread can have separate stack and registers, but they share the same heap memory.
// Threads can be created using the std::thread class in C++.

// std::mutex is used to protect shared data from being accessed by multiple threads simultaneously, preventing data races.
// std::mutex is a mutual exclusion object that allows only one thread to access a resource at a time.
// std::mutex provides a lock mechanism to ensure that only one thread can access the shared resource at a time.

// std::lock_guard is a RAII-style mechanism that locks a mutex when it is created and unlocks it when it goes out of scope.
// std::lock_guard is used to simplify the locking and unlocking of mutexes, ensuring that the mutex is always unlocked when it goes out of scope.
// std::lock_guard is a safer alternative to manually locking and unlocking mutexes, as it automatically handles the locking and unlocking of the mutex.


class RaceConditionExample {
private:
    std::mutex mtx;

public:
    void increment(int& counter) {
        std::cout << "Thread " << std::this_thread::get_id() << " is incrementing the counter.\n";
        for (int i = 0; i < 1000; ++i) {
            mtx.lock();
            ++counter; // This line can cause a race condition  
            mtx.unlock();
        }
    }

    void incrementWithLockGuard(int& counter) {
        std::cout << "Thread " << std::this_thread::get_id() << " is incrementing the counter with lock_guard.\n";
        for (int i = 0; i < 2000; ++i) {
            std::lock_guard<std::mutex> lock(mtx); // lock_guard automatically locks and unlocks the mutex
            ++counter; // This line is now thread-safe
        }
    }   

    void run() {
        int counter = 0;
        std::thread t1(&RaceConditionExample::increment, this, std::ref(counter));
        std::thread t2(&RaceConditionExample::increment, this, std::ref(counter));

        std::cout << "Thread id t1 in main: " << t1.get_id() << "\n";
        std::cout << "Thread id t2 in main: " << t2.get_id() << "\n";
        std::cout << "Main thread is: " << std::this_thread::get_id() << "\n";

        t1.join();
        t2.join();

        std::cout << "Final counter value: " << counter << std::endl;


        std::thread t3(&RaceConditionExample::incrementWithLockGuard, this, std::ref(counter));
        std::thread t4(&RaceConditionExample::incrementWithLockGuard, this, std::ref(counter));

        t3.join();
        t4.join();

        std::cout << "Final counter value: " << counter << std::endl;

        // No of threads can CPU run concurrently
        // This is a platform-dependent value, it may return 0 if the value is not defined
        // in the implementation or if the implementation does not support concurrency.
        // It is recommended to use this value to determine the number of threads to create
        unsigned int cores = std::thread::hardware_concurrency();
        std::cout << "Hardware concurrency: " << cores << std::endl;

    }

};

int main() {
    RaceConditionExample example;
    example.run();

    return 0;
}