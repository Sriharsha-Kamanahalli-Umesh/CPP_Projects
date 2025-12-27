
#include <iostream>
#include <atomic>
#include <thread>


std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter++;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;
    std::cout << "the value is:" << counter.load() << "\n";

    std::cout << "the exhange value value is:" << counter.exchange(200) << "\n";
    std::cout << "the value is:" << counter.load() << "\n";

    int expected=200;
    // Here expected value is 200 and desired value is 20, if expected value is the counter stored value == expected value,
    // then it will store the desired value and return true., otherwise return false.
    // This mechanism allows threads to safely update shared data only if it hasn’t been changed by another thread, 
    // making it a key building block for lock-free programming.
    std::cout << "the value is:" << counter.compare_exchange_strong(expected, 20) << "\n";
    std::cout << "the value is:" << counter.load() << "\n";
    return 0;
}


#include <atomic>
#include <iostream>
#include <thread>

template<typename T>
class LockFreeStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    std::atomic<Node*> head;

public:
    LockFreeStack() : head(nullptr) {}

    void push(T value) {
        Node* new_node = new Node(value);
        new_node->next = head.load(std::memory_order_relaxed);

        // CAS loop
        while (!head.compare_exchange_weak(new_node->next, new_node,
                                           std::memory_order_release,
                                           std::memory_order_relaxed)) {
            // Retry until successful
        }
    }

    bool pop(T& result) {
        Node* old_head = head.load(std::memory_order_relaxed);

        // CAS loop
        while (old_head &&
               !head.compare_exchange_weak(old_head, old_head->next,
                                           std::memory_order_acquire,
                                           std::memory_order_relaxed)) {
            // Retry until successful
        }

        if (!old_head) return false;

        result = old_head->data;
        delete old_head;
        return true;
    }
};

LockFreeStack<int> stack;

void push_items() {
    for (int i = 0; i < 1000; ++i) {
        stack.push(i);
    }
}

void pop_items() {
    int value;
    for (int i = 0; i < 1000; ++i) {
        if (stack.pop(value)) {
            // Optionally print or process value
        }
    }
}

int main() {
    std::thread t1(push_items);
    std::thread t2(pop_items);

    t1.join();
    t2.join();

    std::cout << "Lock-free stack operations completed." << std::endl;
    return 0;
}

// Drawbacks of the CAS
// Effect	                Description
// Retries	            Threads repeatedly fail CAS and retry.
// CPU Usage	        More spinning = more CPU cycles wasted.
// Performance  Drop	Throughput decreases under heavy contention.
// Starvation Risk	    Some threads may keep failing and never succeed quickly.

