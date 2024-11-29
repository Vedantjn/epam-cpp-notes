// It enables the creation, management, and synchronization of threads.

// Thread Creation:

// Threads in C++ are represented by the std::thread class.
// A thread is started by passing a callable (like a function, lambda, or functor) to its constructor.
// Thread Synchronization:

// Mutex (std::mutex): Protects shared resources from simultaneous access.
// Lock (std::lock_guard, std::unique_lock): Simplifies locking and unlocking of mutexes.
// Condition Variable (std::condition_variable): Allows threads to wait for certain conditions.
// Thread Management:

// Threads can be joined (.join()) or detached (.detach()).
// Joining ensures the main thread waits for the spawned thread to finish.
// Detaching runs the thread independently.
// Thread Safety:

// Use synchronization mechanisms to avoid data races and undefined behavior.
// Atomic operations (std::atomic) allow lock-free thread-safe programming.


// In multithreading, mutexes (short for "mutual exclusion") are synchronization 
// primitives used to protect shared resources from simultaneous access by multiple 
// threads. The lock and unlock mechanisms are fundamental to mutex usage, ensuring 
// that only one thread can access a critical section at a time.


// Basic multithreading

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;

void threadfun()
{
	cout << "this is thread fun\n";
	for (int i = 1; i <= 10000; i++)
	{
	    mtx.lock();
		cout << "thread " << i << endl;
	    mtx.unlock();
	}
}
 
int main()
{
    thread thrd1(threadfun);
    thread thrd2(threadfun);

    thrd1.join();
    thrd2.join();

	return 0;
}

// A mutex is a lock that allows only one thread to acquire it at a time. 
// If another thread tries to acquire the same mutex while it's locked, it 
// is forced to wait until the mutex is unlocked.

