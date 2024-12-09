// Conditional variable is used for synchronization in multithreaded programs. 
// It allows threads to communicate with each other by waiting for certain conditions 
// to be met. A conditional variable is used in conjunction with a mutex to coordinate
//  access to shared resources.

// C++ provides conditional variables through the <condition_variable> header. There are two main types:

// std::condition_variable: For use with std::unique_lock<std::mutex>.
// std::condition_variable_any: For use with any lock type that meets the BasicLockable requirements.

// Key Methods in std::condition_variable
// wait: Blocks the thread until the condition is satisfied or notified.
// notify_one: Wakes up one waiting thread.
// notify_all: Wakes up all waiting threads.

#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = true;

void print_message(int id) {
    unique_lock<mutex> lock(mtx); // Lock the mutex
    cv.wait(lock, [] { return ready; }); // Wait until ready is true
    cout << "Thread " << id << " is running.\n";
}

void set_ready() {
    {
        lock_guard<mutex> lock(mtx); // Lock the mutex
        ready = true; // Set the condition
    }
    cv.notify_all(); // Notify all waiting threads
}


int main(){
    thread t1(print_message, 1);
    thread t2(print_message, 2);

    this_thread::sleep_for(chrono::seconds(1));
    set_ready(); // Signals threads to proceed

    t1.join();
    t2.join();
    
    return 0;
}

// Thread 1 is running.
// Thread 2 is running.