#include <iostream>
using namespace std;

class A {
    int x;
public:
    A(int a = 0) {  // default argument constructor
        x = a;
        cout << "A's constructor called" << endl;
    }
};

class B {
    A obj;  // object of class A as member
    int y;
public:
    // Using constructor initialization list to initialize A's object
    B(int a, int b) : obj(a) {
        y = b;
        cout << "B's constructor called" << endl;
    }
};

int main() {
    B objB(10, 20);  // creates object of class B
    return 0;
}

// A's constructor called
// B's constructor called