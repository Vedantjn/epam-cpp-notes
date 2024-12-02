// lock_guard is a utility in C++ that provides a convenient way to manage locks. 
// It ensures that a mutex is properly acquired and released, which helps to avoid 
// common errors like forgetting to unlock a mutex or double-locking.

// Key Features of std::lock_guard

// Automatic Locking: The mutex is locked when the std::lock_guard object is created.
// Automatic Unlocking: The mutex is unlocked when the std::lock_guard object goes out of scope, ensuring proper release even in the presence of exceptions.
// RAII (Resource Acquisition Is Initialization): It manages the lifetime of the lock in the scope, ensuring safe resource handling.

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;

void print_numbers(int id) {
    mtx.lock();
    cout << "Thread " << id << " is working.\n";
    mtx.unlock();
}

int main(){
    thread t1(print_numbers, 1);
    thread t2(print_numbers, 2);

    t1.join();
    t2.join();

    return 0;
}

// Thread 1 is working.
// Thread 2 is working.

// or

// Thread 2 is working.
// Thread 1 is working.


// ------------------------------------------

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void print_numbers(int id) {
    lock_guard<mutex> guard(mtx);  // Automatically locks and unlocks
    cout << "Thread " << id << " is working.\n";
}

int main() {
    thread t1(print_numbers, 1);
    thread t2(print_numbers, 2);

    t1.join();
    t2.join();

    return 0;
}

// Thread 1 is working.
// Thread 2 is working.

// or

// Thread 2 is working.
// Thread 1 is working.

// Without std::lock_guard, you have to manually lock and unlock the mutex, which can lead to errors.
// With std::lock_guard, the mutex is automatically unlocked even if an exception occurs, ensuring safe execution.

// When to Use std::lock_guard
// Critical Sections: To protect shared resources (like variables, files, etc.) in multithreaded programs.
// Exception Safety: When there’s a chance of exceptions disrupting flow.
// Simplified Code: Reduces the burden of manual lock management.

