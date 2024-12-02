// In C++, the std::thread class provides two ways to handle the lifetime of threads after they have been started: join and detach. Both serve different purposes, and understanding their behavior is crucial for correct multithreaded programming.

// 1. join
//      - The join function is used to wait for a thread to complete execution. The main thread (or the thread that calls join) will block until the joined thread finishes.
//      - Key Points:
//        - Ensures the thread has completed before proceeding.
//        - After joining, the thread object is no longer joinable.
//        - Useful when the main thread or other threads depend on the completion of this thread.
//        - Prevents resource leaks by ensuring the thread finishes properly.
//      - Syntax:
//        - thread_obj.join();
//      - Example:
       #include <iostream>
        #include <thread>
       using namespace std;
       void work() {
           cout << "Thread is working...\n";
       }
       int main() {
           thread th(work);
           th.join();  // Wait for the thread to finish
           cout << "Main thread continues after join.\n";
           return 0;
       }
//      - Output:
//        - Thread is working...
//        - Main thread continues after join.

// 2. detach
//      - The detach function is used to separate the thread's execution from the thread object. The thread will run independently (in the background), and the program will not wait for it to finish.
//      - Key Points:
//        - The detached thread becomes a daemon thread, meaning it will continue execution even if the main thread finishes.
//        - After detaching, the thread object is no longer associated with the thread.
//        - You cannot rejoin or check the status of a detached thread.
//        - Useful for fire-and-forget tasks, but requires caution to avoid accessing shared resources improperly.
//      - Syntax:
//        - thread_obj.detach();
//      - Example:
       #include <iostream>
       #include <thread>
       #include <chrono>
       void backgroundWork() {
           this_thread::sleep_for(std::chrono::seconds(2));
           cout << "Background thread finished work.\n";
       }
       int main() {
           thread th(backgroundWork);
           th.detach();  // Run thread independently
           cout << "Main thread continues immediately.\n";
           this_thread::sleep_for(std::chrono::seconds(3)); // Allow background thread to finish
           return 0;
       }
//      - Output:
//        - Main thread continues immediately.
//        - Background thread finished work.

// Key Differences Between join and detach
// - Aspect:                | join                                  | detach
// - Behavior:              | Blocks until the thread completes.    | Allows the thread to run independently.
// - Thread Association:    | Thread object remains associated.     | Thread object is disassociated.
// - Use Case:              | When thread completion is required.   | For background tasks (fire-and-forget).
// - Rejoin:                | Cannot rejoin once joined.            | Cannot rejoin after detaching.
// - Thread Lifetime:       | Thread ends when it completes.        | Thread continues even if main thread exits.// Common Pitfalls:

// - Double Join or Detach:
//     - You cannot call join or detach more than once on the same thread object. This will throw an exception or result in undefined behavior.
// - Forget to Join or Detach:
//     - If you don't call either join or detach, the destructor of the std::thread object will terminate the program.
//     - Example:
//       - #include <thread>
//       - void work() {}
//       - int main() {
//           std::thread th(work);
//           // Forgot to join or detach
//           return 0;  // std::terminate will be called
//       }
// - Detached Thread Accessing Invalid Resources:
//     - If a detached thread tries to access a resource (e.g., a variable) that has already been destroyed, it can cause undefined behavior.

// When to Use Which?
// - Use join:
//     - When you need to ensure the thread completes before proceeding.
//     - If the thread is performing critical tasks that must finish before program termination.
// - Use detach:
//     - When the thread is performing independent background work.
//     - For tasks that do not require synchronization or when completion is not critical to the main program.

// Choosing the right approach between join and detach depends on the task's importance and its relationship to the rest of the program.