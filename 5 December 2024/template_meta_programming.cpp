// Template metaprogramming (TMP) is a programming technique in C++ where templates are used to perform computations at compile-time rather than runtime. 
// This enables developers to write code that is more efficient and highly optimized, as certain computations are resolved before the program executes. 
// TMP is widely used in areas like type manipulation, code generation, and optimizing performance-sensitive applications.

// Key Concepts
// Compile-Time Programming: TMP involves generating code at compile-time, which avoids runtime overhead.
// Recursion: Template recursion is used to perform iterations since loops are not available at compile-time.
// Static Polymorphism: It allows compile-time decisions rather than runtime polymorphism.
// Traits and Type Manipulation: TMP is often used for type inspection and manipulation.

#include <iostream>

// Template to compute factorial at compile-time
template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

// Specialization for the base case
template<>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    constexpr int fact5 = Factorial<5>::value; // Compute factorial of 5
    cout << "Factorial of 5 is: " << fact5 << endl;

    return 0;
}


// Factorial of 5 is : 120

// Here, Factorial<5>::value is resolved at compile-time by recursively unrolling the templates.

// --------------------------------------

#include <iostream>
using namespace std;

// Template to compute Fibonacci numbers
template<int N>
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// Specializations for base cases
template<>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template<>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

int main() {
    constexpr int fib10 = Fibonacci<10>::value; // Compute 10th Fibonacci number
    cout << "10th Fibonacci number is: " << fib10 << endl;

    return 0;
}

// 10th Fibonacci number is: 55

