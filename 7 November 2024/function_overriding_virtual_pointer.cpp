// Function Overriding with Virtual Pointers in C++

// 1. Introduction
// ---------------
// Function overriding in C++ is a feature of runtime polymorphism implemented through virtual functions. The mechanism relies on virtual tables (vtables) and virtual pointers (vptrs) for dynamic binding.

// 2. Key Components
// ----------------
// 2.1 Virtual Table (vtable)
// - A compiler-maintained lookup table for classes with virtual functions
// - Stores pointers to virtual functions for the class

// 2.2 Virtual Pointer (vptr)
// - Hidden pointer within objects of classes with virtual functions
// - Points to the class's vtable
// - Used at runtime for function resolution

// 3. Runtime Mechanism
// -------------------
// 3.1 Function Overriding Process
// - Derived class functions replace base class entries in vtable
// - Dynamic binding occurs through vptr lookup

// 3.2 Execution Flow
// - Base class pointer/reference points to derived object
// - Compiler uses vptr to access vtable
// - Correct function version is determined and called at runtime

#include <iostream>
using namespace std;

class Base {
public:
    // Virtual function to be overridden
    virtual void show() {
        cout << "Base class show() function called\n";
    }

    // Non-virtual function
    void display() {
        cout << "Base class display() function called\n";
    }
};

class Derived : public Base {
public:
    // Override the virtual function
    void show() override {
        cout << "Derived class show() function called\n";
    }

    // Non-virtual function
    void display() {
        cout << "Derived class display() function called\n";
    }
};

int main() {
    // Create a base class pointer
    Base* basePtr;        
    
    // Create a derived class object
    Derived derivedObj;   

    // Point base class pointer to derived class object - demonstrates polymorphism
    basePtr = &derivedObj;

    // Virtual function call - will call Derived::show() through vtable lookup
    // This demonstrates dynamic/late binding
    basePtr->show();

    // Non-virtual function call - will call Base::display() 
    // This demonstrates static/early binding
    basePtr->display();

    // Direct call to show() through derived object - calls Derived::show()
    derivedObj.show();

    // Direct call to display() through derived object - calls Derived::display()
    derivedObj.display();
    return 0;
}

// Derived class show() function called
// Base class display() function called
// Derived class show() function called
// Derived class display() function called