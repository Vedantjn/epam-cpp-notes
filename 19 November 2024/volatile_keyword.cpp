#include <iostream>
using namespace std;

class MyClass {
public:
    void memFunc() {
        // Non-const member function implementation
        cout << "Non-const member function called" << std::endl;
    }

    void memFunc() const {
        // Const member function implementation
        cout << "Const member function called" << std::endl;
    }

    void memFunc() const volatile {
        // Const volatile member function implementation
        cout << "Const volatile member function called" << std::endl;
    }

    void memFunc() volatile {
        // Volatile member function implementation
        cout << "Volatile member function called" << std::endl;
    }
};

int main() {
    MyClass obj;              // Non-const, non-volatile object
    const MyClass constObj;   // Const object
    volatile MyClass volObj;  // Volatile object
    const volatile MyClass constVolObj; // Const volatile object

    cout << "Calling memFunc() on non-const, non-volatile object:" << endl;
    obj.memFunc(); // Calls the non-const, non-volatile version

    cout << "\nCalling memFunc() on const object:" << endl;
    constObj.memFunc(); // Calls the const version

    cout << "\nCalling memFunc() on volatile object:" << endl;
    volObj.memFunc(); // Calls the volatile version

    cout << "\nCalling memFunc() on const volatile object:" << endl;
    constVolObj.memFunc(); // Calls the const volatile version

    return 0;
}

// Calling memFunc() on non-const, non-volatile object:
// Non-const member function called

// Calling memFunc() on const object:
// Const member function called

// Calling memFunc() on volatile object:
// Volatile member function called

// Calling memFunc() on const volatile object:
// Const volatile member function called


// The volatile keyword in C++ is used to indicate that a variable can be changed in ways not explicitly specified by the program, such as through hardware or other threads. It prevents the compiler from optimizing code in ways that assume the variable's value won't change unexpectedly.

// The volatile keyword tells the compiler that a variable's value may change at any time 
// without any action from the code the compiler can see. It prevents compiler optimizations 
// that might cache the variable's value in a register, ensuring each access reads from memory.
// This is used for:
// 1. Memory-mapped hardware registers
// 2. Variables shared between interrupt routines and main code
// 3. Variables shared between multiple threads