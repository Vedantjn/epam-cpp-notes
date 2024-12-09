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
