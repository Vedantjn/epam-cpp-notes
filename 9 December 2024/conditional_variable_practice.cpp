#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
 
using namespace std;
 
mutex mtx;
condition_variable cv;
bool ready = false;
 
void print_cv(int id) {
    cout << "Thread ID " << id << endl;
    unique_lock<mutex> lck(mtx);
 
    cv.wait(lck, [] {
        return ready;
    });
 
    cout << "Thread " << id << " is released\n";
}
 
int main() {
    thread t1(print_cv, 1);
    thread t2(print_cv, 2);
 
    ready = true;
    cv.notify_all();
 
    this_thread::sleep_for(chrono::seconds(4));
    cout << "Main thread\n";
 
    t1.join();
    t2.join();
 
 
    return 0;
}

// Main thread
// Thread ID 1
// Thread 1Thread ID 2
//  is released
// Thread 2 is released