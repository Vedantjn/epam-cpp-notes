#include<iostream>
using namespace std;

// Base case for recursion
void print() {
    cout << endl;
}

// Variadic template for printing multiple arguments
template<typename T, typename... Args>
void print(T first, Args... args) {
    cout << first << " ";
    print(args...);
}

// Sum function - base case
template<typename T>
T sum(T value) {
    return value;
}

// Variadic template for summing multiple arguments
template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...);
}

// Type-safe printf-like function
template<typename... Args>
void printf(const char* format, Args... args) {
    printf(format, args...);
}

int main() {
    // Print function
    print("Hello", 42, 3.14, "World");
    
    // Sum function
    int result1 = sum(1, 2, 3, 4, 5);
    double result2 = sum(1.5, 2.5, 3.5);
    
    cout << "Sum of integers: " << result1 << endl;
    cout << "Sum of doubles: " << result2 << endl;
    
    // Printf-like function
    printf("Integer: %d, String: %s\n", 42, "test");
    
    return 0;
}