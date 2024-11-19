// Downcasting in C++
// - Downcasting is converting a base class pointer/reference to a derived class pointer/reference
// - It's used when we need to access derived class specific members through a base class pointer
// - dynamic_cast is used for safe downcasting and returns nullptr if cast fails
// - Only works with polymorphic classes (classes with at least one virtual function)
// - Upcasting is implicit and always safe, while downcasting needs explicit casting

#include <iostream>
using namespace std;

class Parent {
public:
    virtual void display() {  // Virtual function makes the class polymorphic
        cout << "Parent class" << endl;
    }
};

class Child : public Parent {
public:
    void display() override {  // Override keyword for better code clarity
        cout << "Child class" << endl;
    }

    void childSpecific() {
        cout << "Child specific method" << endl;
    }
};

int main() {
    Parent* parentPtr = new Child();  // Upcasting: Implicit conversion
    parentPtr->display();  // Calls Child's display() due to virtual function

    // Downcasting: Explicit conversion using dynamic_cast
    Child* childPtr = dynamic_cast<Child*>(parentPtr);

    if (childPtr != nullptr) {
        childPtr->childSpecific();  // Access Child specific method
    } else {
        cout << "Downcasting failed" << endl;
    }

    delete parentPtr;  // Clean up memory
    return 0;
}
