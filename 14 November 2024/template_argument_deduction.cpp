#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <type_traits>
#include <string>

// Basic template function
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple parameters
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Template with deduction guides
template<typename T>
class Container {
    T value;
public:
    Container(T val) : value(val) {}
    T getValue() const { return value; }
};

// CTAD (Class Template Argument Deduction) - C++17 feature
Container(const char*) -> Container<string>;

int main() {
    // Automatic type deduction
    cout << maximum(10, 20) << endl;        // T is int
    cout << maximum(10.5, 20.7) << endl;    // T is double
    cout << maximum('a', 'b') << endl;      // T is char

    // Mixed type deduction
    auto result = add(10, 20.5);                  // result type is double
    cout << "Mixed type result: " << result << endl;

    // Class template deduction
    Container c1(42);                             // Container<int>
    Container c2("Hello");                        // Container<string>

    cout << "Container values: " << c1.getValue() << ", " << c2.getValue() << endl;

    return 0;
}

// 20
// 20.7
// b
// Mixed type result: 30.5
// Container values: 42, Hello

// -----------------------------------------------------------

// • Template argument deduction in C++ automatically determines template arguments from function/class usage

// • Key aspects of template argument deduction:
//   - Compiler analyzes function call arguments
//   - Matches parameter types with template parameters
//   - Deduces appropriate template type T
//   - No explicit type specification needed

// • Common deduction scenarios:
//   - Function parameters
//   - Return types 
//   - Class template arguments
//   - Auto keyword

// • Benefits:
//   - Reduces code verbosity
//   - Type-safe generic programming
//   - Improved code maintainability
//   - Compile-time type checking
  
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void printValue(const T& value) {
    scout << "Value: " << value << std::endl;
}

int main() {
    printValue(42);        // Deduces T as int
    printValue(3.14);      // Deduces T as double
    printValue("Hello");    // Deduces T as const char*
    string str = "World";
    printValue(str);       // Deduces T as std::string
    return 0;
}


// • Class template argument deduction works similarly to function templates

// • Pre-C++17:
//   - Could not deduce template parameters directly from constructor arguments
//   - Required explicit template parameter specification
  
// • C++17 introduced Class Template Argument Deduction (CTAD):
//   - Compiler can automatically deduce class template arguments
//   - Based on constructor arguments
//   - No need for explicit template parameter specification
//   - Simplifies template class usage

#include <iostream>
#include <utility>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 a, T2 b) : first(a), second(b) {}
};

int main() {
    Pair<int, double> p1(10, 3.14);  // Explicit template arguments
    Pair p2(10, 3.14);               // Deduction: T1 is int, T2 is double
    cout << "p2.first: " << p2.first << ", p2.second: " << p2.second << std::endl;
    return 0;
}
