// Deferred locking in C++ refers to the ability to create a mutex 
// lock object without immediately acquiring the lock.

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void thread_function() {
    unique_lock<std::mutex> lock(mtx, defer_lock); // Defer locking
    cout << "Lock deferred.\n";
    lock.lock(); // Manually lock when needed
    cout << "Thread is running with lock acquired.\n";
}

int main() {
    thread t1(thread_function);
    t1.join();
    return 0;
}

// Lock deferred.
// Thread is running with lock acquired.