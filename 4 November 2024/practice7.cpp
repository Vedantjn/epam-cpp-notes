#include <iostream>
using namespace std;

class A {
    public:
        A() {
            cout << "Constructor of A called" << endl;
        }
        ~A() {
            cout << "Destructor of A called" << endl;
        }
};

class B : public A {
    public:
        B() {
            cout << "Constructor of B called" << endl;
        }
        ~B() {
            cout << "Destructor of B called" << endl;
        }
};

class C : public B {
    public:
        C() {
            cout << "Constructor of C called" << endl;
        }
        ~C() {
            cout << "Destructor of C called" << endl;
        }
};

int main() {
    C obj;
    return 0;
}

// Constructor of A called
// Constructor of B called
// Constructor of C called
// Destructor of C called
// Destructor of B called
// Destructor of A called