#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
    virtual void calculate() {
        cout << "Base class calculate function" << endl;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    virtual void display() override {
        cout << "Derived class display function" << endl;
    }
    virtual void calculate() override {
        cout << "Derived class calculate function" << endl;
    }
};
int main() {
    Base* ptr;
    Derived derivedObj;
    ptr = &derivedObj;
    
    ptr->display();
    ptr->calculate();
    
    return 0;
}

// Derived class display function
// Derived class calculate function