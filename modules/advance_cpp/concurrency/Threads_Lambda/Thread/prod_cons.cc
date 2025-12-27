#include <iostream>
#include <deque>
#include <thread>
#include <condition_variable>
using namespace std;

condition_variable cond;
mutex mu;
deque<int> buffer;
const unsigned int maxBufferSize = 50;
bool done = false; // Done flag to signal the end of production

void producer(int val)
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        // Wait if the buffer is full
        cond.wait(locker, []()
                  { 
            cout<< " from producer " << buffer.size() << endl;
            return buffer.size() < maxBufferSize; });
        buffer.push_back(val);
        cout << "Produced: " << val << endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
    // Signal that the producer is done
    // {
    //     std::lock_guard<std::mutex> locker(mu);
    //     done = true;
    // }
    cond.notify_all(); // Notify consumer that production is done
}
void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        // Wait if the buffer is empty and the producer is not done yet
        cond.wait(locker, []()
                  { return !buffer.empty(); });
        // If buffer is empty and producer is done, exit the loop
        if (buffer.empty())
        {
            break;
        }
        if (!buffer.empty())
        {
            int val = buffer.back();
            buffer.pop_back();
            cout << "Consumed: " << val << endl;
        }
        locker.unlock();
        cond.notify_one();
    }
}
int main()
{
    thread t1(producer, 50);
    thread t2(consumer);
    t1.join();
    t2.join();
}