#include <iostream>
using namespace std;

class Parent {
    public:
        Parent() {
            cout << "Parent constructor called" << endl;
        }
        ~Parent() {
            cout << "Parent destructor called" << endl;
        }
};

class Child : public Parent {
    public:
        Child() {
            cout << "Child constructor called" << endl;
        }
        ~Child() {
            cout << "Child destructor called" << endl;
        }
};

int main() {
    Child c;
    return 0;
}
/*
Parent constructor called
Child constructor called
Child destructor called
Parent destructor called

The output is in this order because:

1. When creating a Child object:
   - The Parent constructor is called first (because base class is constructed before derived)
   - Then the Child constructor is called

2. When the Child object is destroyed (goes out of scope):
   - The Child destructor is called first (derived class destroyed before base)
   - Then the Parent destructor is called

This is the standard order in C++ inheritance:
- Constructors: Base -> Derived
- Destructors: Derived -> Base
*/