#include<iostream>
#include<vector>
using namespace std;

// Basic example of noexcept functions
void mayThrow() {
    throw runtime_error("This function throws an exception");
}

void noThrow() noexcept {
    cout << "This function does not throw an exception.\n";
}

// Class demonstrating noexcept move operations
class NoExceptExample {
public:
    int* data;

    NoExceptExample(int value) : data(new int(value)) {}

    // Move constructor marked noexcept
    NoExceptExample(NoExceptExample&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Destructor
    ~NoExceptExample() {
        delete data;
    }
};

int main() {
    // Testing basic noexcept functions
    try {
        noThrow();     // Safe; noexcept guarantees no exceptions
        mayThrow();    // Will throw
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << '\n';
    }

    // Check if functions are noexcept
    cout << "noThrow is noexcept: " << noexcept(noThrow()) << '\n';
    cout << "mayThrow is noexcept: " << noexcept(mayThrow()) << '\n';

    // Testing noexcept move operations
    vector<NoExceptExample> vec;
    vec.reserve(2);
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(3);  // Move operations will be noexcept

    return 0;
}

// This function does not throw an exception.
// Caught exception: This function throws an exception
// noThrow is noexcept: 1
// mayThrow is noexcept: 0


// In this example:

// noThrow is marked with noexcept, so the compiler knows it will not throw an exception.
// mayThrow is a regular function that can throw an exception, and we see noexcept(mayThrow()) returns false since it’s not guaranteed to be exception-free.

// In this example:

// The move constructor of NoExceptExample is marked noexcept, meaning it won’t throw an exception during a move.
// std::vector can thus use this noexcept move constructor to reallocate elements without having to worry about exceptions.
// This noexcept guarantee can significantly improve performance in operations where large containers reallocate, as it avoids costly fallback to copying elements in case of exceptions.

// • noexcept specifier in C++ declares functions that don't throw exceptions

// • Key benefits:
//   - Enables performance optimization
//   - Helps standard library functions optimize operations
//   - Results in faster code execution
//   - Allows better compiler optimization
//   - Removes need for exception handling preparation

// • Two ways to use noexcept:
//   1. Declaration mode:
//      - Declares function won't throw exceptions
//      - Provides guarantee for compiler and program

//   2. Conditional mode:
//      - Uses format: noexcept(expr)
//      - expr evaluates to true/false
//      - Allows conditional noexcept based on function/argument properties