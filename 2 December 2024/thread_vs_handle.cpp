// Threads vs Handles: A Conceptual Overview
// a thread is a unit of execution in a process, while a handle is an identifier used to track an open file

// 1. Threads
//      - Definition: A thread is the actual unit of execution within a process. It is a path of execution, including its own stack, program counter, and local variables, but it shares the memory and resources of the parent process with other threads.

//      - Characteristics:
//        - Represents the actual execution context.
//        - Runs independently but shares memory with other threads in the same process.
//        - When a thread completes, it ceases to exist.
//      - Example (Using C++ std::thread):
       #include <iostream>
       #include <thread>
       using namespace std;
       void work() { cout << "Working in thread!\n"; }

       int main() {
           thread t(work);  // Creates a thread
           t.join();             // Waits for the thread to finish
           return 0;
       }

// 2. Handles
//      - Definition: A handle is a reference or an identifier for a system resource, such as a thread. In multithreading, a thread handle allows you to interact with and manage the thread (e.g., join it, wait for it, or terminate it).

//      - Characteristics:
//        - It's a proxy for accessing or controlling a thread, not the thread itself.
//        - It persists even after the thread has finished execution (until explicitly released).
//        - Useful for thread management (e.g., join, detach, or OS-specific operations).
//      - Example (Using C++ std::thread as a handle):
//        - HANDLE hThread is the thread handle.
//        - It is used to wait for the thread's completion and release the system resource.

// Conclusion
// - A thread is the actual execution entity.
// - A handle is a tool or reference for managing that thread. Understanding the difference is critical when working with low-level threading APIs or debugging multithreaded applications.