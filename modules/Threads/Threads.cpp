#include <iostream>
#include <thread>


void function (int id) {
    std::cout << "Thread " << id << " is running.\n";
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " has finished.\n";
}

void function2(int& id) {
    std::cout << "Thread " << id << " is running.\n";
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " has finished.\n";
}

auto lambda_function = [] () {
    std::cout << "Lambda function is running.\n";
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Lambda function has finished.\n";
};

void print1to10() {
    for(int i=1; i<=10; ++i) {
        std::cout << i << " ";
    }
}

class SimpleThread {
private:
    int id;
public:
    SimpleThread(int id) : id(id) {}
    void operator()() const {
        std::cout << "SimpleThread " << id << " is running.\n";
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void run() const {
        std::cout << "SimpleThread " << id << " has finished.\n";
    }
};

int main() {
    std::thread t(function , 1);
    std::thread t2(function, 2);

    for(int i = 0; i < 5; ++i) {
        std::cout << "Main thread is running.\n";
        std::cout << "Main thread iteration: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    int id = 3;
    std::thread t3(function2, std::ref(id));

    std::thread t4(lambda_function);

    std::thread t5(SimpleThread(5));

    std::thread t6(&SimpleThread::run, SimpleThread(6));

    std::thread t7([] (int id) {
        std::cout << "Lambda thread " << id << " is running.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Lambda thread " << id << " has finished.\n";
    }, 7);

    std::thread t8(print1to10);

    t.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();


    return 0;
}