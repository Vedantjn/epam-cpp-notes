#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx;
int shared_counter = 0;

void increment_counter(int id) {
    for (int i = 0; i < 1000; i++) {
        lock_guard<mutex> guard(mtx);  // Lock the mutex for the scope
        shared_counter++;
    }
    cout << "Thread " << id << " finished.\n";
}

int main() {
    vector<thread> threads;

    // Create 10 threads
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(increment_counter, i);
    }

    // Join threads
    for (auto &t : threads) {
        t.join();
    }

    cout << "Final Counter: " << shared_counter << endl;
    return 0;
}

// Thread 1Thread 3 finished.
// Thread 5 finished.
// Thread  finished.
// Thread 4Thread Thread 7 finished.
// Thread 9 finished.
// Thread 6 finished.
//  finished.
// 0 finished.
// 8 finished.
// Thread 2 finished.
// Final Counter: 10000

// ---------------------------------------

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx; // Mutex for shared data and output
int shared_counter = 0;

void increment_counter(int id) {
    for (int i = 0; i < 1000; i++) {
        lock_guard<mutex> guard(mtx); // Lock the mutex for shared_counter
        shared_counter++;
    }

    {
        lock_guard<mutex> guard(mtx); // Lock the mutex for std::cout
        cout << "Thread " << id << " finished.\n";
    }
}

int main() {
    vector<thread> threads;

    // Create 10 threads
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(increment_counter, i);
    }

    // Join threads
    for (auto &t : threads) {
        t.join();
    }

    cout << "Final Counter: " << shared_counter << endl;
    return 0;
}

// Thread 2 finished.
// Thread 0 finished.
// Thread 4 finished.
// Thread 7 finished.
// Thread 9 finished.
// Thread 8 finished.
// Thread 5 finished.
// Thread 3 finished.
// Thread 1 finished.
// Thread 6 finished.
// Final Counter: 10000