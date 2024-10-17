#include<iostream>
#include<thread>
#include<condition_variable>
#include<chrono>
using namespace std;

mutex mlock;
condition_variable CV;


int main() {
    int result = 0;
    bool notified = false;
    cout<<"Execution begin "<<endl;
    thread reporter([&](){
        unique_lock<mutex> ulock(mlock);
        if(notified==false){
            CV.wait(ulock);
        }
        cout<<"Reporter Result: "<<result<<endl;
    });

    //Worker theard
    thread worker([&](){
        unique_lock<mutex> ulock(mlock); // it automatically attains the lock
        // Do your work , because we have the lock
        result = 23+2;
        //work is done
        notified = true;
        this_thread::sleep_for(chrono::seconds(5));
        cout<<"Work complete "<<endl;
        //wake up a thread that is waiting for some condition to be true
        CV.notify_one(); // Now notify one thread

    });
    reporter.join();
    worker.join();

}