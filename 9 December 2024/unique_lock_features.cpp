// Unlike std::lock_guard, which locks a mutex upon construction 
// and releases it upon destruction, std::unique_lock offers more 
// control, such as deferred locking, timed locking, and unlocking 
// before destruction.

// Key Features of std::unique_lock
// Deferred Locking: You can construct the std::unique_lock without immediately locking the mutex.
// Timed Locking: It supports timed operations like try_lock_for or try_lock_until.
// Ownership Transfer: Ownership of the lock can be transferred to another std::unique_lock.
// Explicit Unlocking: You can manually unlock the mutex before the lock is destroyed.

// Common Member Functions
// lock(): Locks the associated mutex.
// unlock(): Unlocks the associated mutex.
// try_lock(): Attempts to lock the mutex without blocking.
// owns_lock(): Returns true if the lock owns the mutex.
// release(): Releases ownership of the mutex without unlocking it.

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void thread_function(int id) {
    std::unique_lock<std::mutex> lock(mtx); // Locks the mutex
    std::cout << "Thread " << id << " is running.\n";
    // Mutex is automatically unlocked when `lock` goes out of scope
}

int main() {
    std::thread t1(thread_function, 1);
    std::thread t2(thread_function, 2);

    t1.join();
    t2.join();

    return 0;
}

// Thread 1 is running.
// Thread 2 is running.

// Use std::unique_lock when:
// You need more flexibility (e.g., deferred or timed locking).
// You want to unlock and re-lock a mutex explicitly.
// Use std::lock_guard for simpler scenarios where the mutex should lock immediately and release automatically.