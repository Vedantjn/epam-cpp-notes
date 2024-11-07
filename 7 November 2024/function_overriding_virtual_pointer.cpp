// Point base class pointer to derived class object

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
    // Case 1: Base pointer to Derived object
    Base* basePtr;        
    Derived derivedObj;   
    basePtr = &derivedObj;
    basePtr->show();      // Calls Derived::show() - Virtual
    basePtr->display();   // Calls Base::display() - Non-virtual

    // Case 2: Direct Derived object calls
    derivedObj.show();    // Calls Derived::show()
    derivedObj.display(); // Calls Derived::display()

    // Case 3: Base pointer to Base object
    Base baseObj;
    Base* basePtr2 = &baseObj;
    basePtr2->show();     // Calls Base::show()
    basePtr2->display();  // Calls Base::display()

    // Case 4: Base reference to Derived object
    Base& baseRef = derivedObj;
    baseRef.show();       // Calls Derived::show() - Virtual
    baseRef.display();    // Calls Base::display() - Non-virtual

    // Case 5: Direct Base object calls
    baseObj.show();       // Calls Base::show()
    baseObj.display();    // Calls Base::display()    return 0;
}

// Derived class show() function called
// Base class display() function called
// Derived class show() function called
// Derived class display() function called
// Base class show() function called
// Base class display() function called
// Derived class show() function called
// Base class display() function called
// Base class show() function called
// Base class display() function called