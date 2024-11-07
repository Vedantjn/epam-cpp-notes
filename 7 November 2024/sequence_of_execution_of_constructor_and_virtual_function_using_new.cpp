/*
Sequence of Operations with new and Virtual Functions:
-------------------------------------------------------
1. Memory Allocation:
   - new first allocates memory for the object.

2. Base Constructor (if applicable):
   - If the class has base classes, the base class constructors are called first
   - Sets up their members and initializes any virtual pointers

3. Setting the vptr for the Current Class:
   - The virtual pointer (vptr) for the current class is set up
   - Occurs after base constructor completes
   - Happens before derived constructor starts executing

4. Derived Class Constructor:
   - The derived class constructor executes
   - Finishes the setup of the object
   - Initializes additional members/attributes specific to derived class
*/

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor\n";
        display();  // Calls Base::display() as vptr is set to Base vtable here
    }
    virtual void display() {
        cout << "Base display\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor\n";
    }
    void display() override {
        cout << "Derived display\n";
    }
};

int main() {
    Base* obj = new Derived();  // Calls Base constructor, then Derived constructor
    obj->display();             // Calls Derived display due to virtual dispatch
    delete obj;
    return 0;
}

// Base Constructor
// Base display
// Derived Constructor
// Derived display
