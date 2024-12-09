#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

timed_mutex mtx; // Use std::timed_mutex instead of std::mutex

void thread_function() {
    unique_lock<std::timed_mutex> lock(mtx, defer_lock); // Defer locking
    if (lock.try_lock_for(chrono::seconds(2))) {  // Try to lock within 2 seconds
        cout << "Lock acquired by thread.\n";
    } else {
        cout << "Failed to acquire lock within the timeout.\n";
    }
}

int main() {
    thread t1(thread_function);
    thread t2(thread_function);

    t1.join();
    t2.join();

    return 0;
}

// Lock acquired by thread.
// Lock acquired by thread.