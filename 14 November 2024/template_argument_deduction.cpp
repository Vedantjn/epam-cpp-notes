#include <iostream>
#include <type_traits>
#include <string>

// Basic template function
template<typename T>
T max(T a, T b) {
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
Container(const char*) -> Container<std::string>;

int main() {
    // Automatic type deduction
    std::cout << max(10, 20) << std::endl;        // T is int
    std::cout << max(10.5, 20.7) << std::endl;    // T is double
    std::cout << max('a', 'b') << std::endl;      // T is char

    // Mixed type deduction
    auto result = add(10, 20.5);                  // result type is double
    std::cout << "Mixed type result: " << result << std::endl;

    // Class template deduction
    Container c1(42);                             // Container<int>
    Container c2("Hello");                        // Container<std::string>

    std::cout << "Container values: " << c1.getValue() << ", " << c2.getValue() << std::endl;

    return 0;
}
