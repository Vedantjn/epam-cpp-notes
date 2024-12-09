// A way to run functions asynchronously and retrieve their results once the computation is complete.

// std::async:
// Used to launch a function asynchronously in a separate thread.
// Can be used with std::launch policies to specify whether the function should run asynchronously or lazily.


// std::future:
// Represents the result of an asynchronous operation.
// Provides a get() method to access the result once it's ready (blocking if necessary).


// std::promise (optional):
// Allows manual setting of a result for a std::future.

#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

// A function to be executed asynchronously
int long_computation(int x) {
    this_thread::sleep_for(chrono::seconds(2)); // Simulate a long task
    return x * x; // Return the square of x
}

int main() {
    // Launch the function asynchronously
    future<int> result = async(launch::async, long_computation, 10);


    cout << "Doing something else while computation is in progress...\n";
    // Get the result (blocks if not yet ready)
    cout << "Result: " << result.get() << "\n";
    cout << "Doing something else while computation is in progress...\n";

    return 0;
}

// Doing something else while computation is in progress...
// Result: 100
// Doing something else while computation is in progress... 



// Comparison: std::async vs std::thread
// Feature                 std::async                               std::thread
// Result management       Automatically provides a std::future.    Requires manual synchronization.
// Thread management       Automatically manages thread lifecycle.  User must manage thread joins/detach.
// Laziness                Supports deferred execution.             Executes immediately.



// While this code might appear to work the same way without explicitly using std::async and std::future, 
// these tools provide several advantages in specific scenarios, particularly when dealing with concurrency 
// and asynchronous execution. Here's why they are useful:

// 1. Simplified Asynchronous Programming
// Without std::async, if you want to execute a function asynchronously, you’d have to:
// Manually create a std::thread.
// Manage the thread lifecycle (e.g., call join() or detach()).
// Handle result passing via shared variables or other synchronization primitives (like mutexes).

// Using std::async abstracts all this complexity:
// It automatically manages the thread lifecycle.
// It provides a std::future to access the result directly, handling synchronization for you.



// Without std::async:

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int result;

void compute(int x) {
    this_thread::sleep_for(chrono::seconds(2));
    lock_guard<mutex> lock(mtx);
    result = x * x;
}

int main() {
    thread t(compute, 10);

    // Wait for the thread to finish
    t.join();

    // Access result
    cout << "Result: " << result << "\n";
    return 0;
}

// With std::async:

#include <iostream>
#include <future>

using namespace std;

int compute(int x) {
    this_thread::sleep_for(chrono::seconds(2));
    return x * x;
}

int main() {
    auto future = async(launch::async, compute, 10);
    cout << "Result: " << future.get() << "\n";
    return 0;
}

// 2. Result Handling
// std::async provides a std::future, which is a robust mechanism for retrieving results:

// Ensures thread safety while accessing results.
// Automatically blocks when calling get() if the computation is not finished.
// Allows handling exceptions thrown in asynchronous tasks (propagates them to the caller).
// Without std::future, managing results safely requires extra effort with mutexes or condition variables.

// 3. Deferred Execution
// With std::launch::deferred, you can choose to delay execution until the result is explicitly needed. This is not possible with std::thread.

future<int> result = async(launch::deferred, compute, 10);
// Function `compute` will not run until `result.get()` is called.
cout << "Now calling get...\n";
cout << "Result: " << result.get() << "\n";

// 4. Exception Handling
// When using std::thread, you must catch exceptions inside the thread manually. With std::future from std::async, exceptions are automatically captured and rethrown when you call get().

#include <iostream>
#include <future>
#include <stdexcept>

using namespace std;

int compute(int x) {
    if (x < 0) throw runtime_error("Negative input not allowed!");
    return x * x;
}

int main() {
    auto future = async(launch::async, compute, -10);

    try {
        int result = future.get(); // Exception rethrown here
        cout << "Result: " << result << "\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
