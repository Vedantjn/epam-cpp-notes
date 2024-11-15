// auto usage limitations

#include<iostream>
#include<vector>
using namespace std;

class MyClass {
    // auto x = 10;         // Error: auto not allowed for non-static member variables
    static const auto y = 20; // OK: auto allowed for static members with constant initializer
};

// auto parameter(auto x) {} // Error: auto not allowed in function parameters (before C++20)

// In C++20, auto is allowed in function parameters:
void parameter(auto x) {
    cout << x << endl;
}

// Lambda functions can use auto in parameters
auto lambda = [](auto x, auto y) {
    return x + y;
};

int main() {
    // Basic auto usage with primitive types
    auto number = 42;        // int
    auto pi = 3.14159;      // double
    auto letter = 'A';       // char
    auto text = "Hello";     // const char*
    
    // Auto with STL containers
    vector<int> numbers = {1, 2, 3, 4, 5};
    auto it = numbers.begin();  // vector<int>::iterator
    
    // Auto in range-based for loop
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Using the C++20 function with auto parameter
    parameter(42);
    
    // Using lambda with auto parameters
    cout << "Sum: " << lambda(5, 3.14) << endl;
    
    return 0;
}