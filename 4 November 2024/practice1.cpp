#include <iostream>
using namespace std;

class Base {
    int baseX;

    public:
    Base() {
        cout << "Base constructor called" << endl;
    }

    void baseMemFunc1() {
        cout << "Inside base memFunc1" << endl;
    }

    ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived1: public Base {
    int baseY;
    public:
    Derived1() {
        cout << "Derived1 constructor called" << endl;
    }

    void derived1MemFunc1() {
        cout << "Inside derived1 memFunc1" << endl;
    }

    ~Derived1() {
        cout << "Derived1 destructor called" << endl;
    }
};

class Derived2: public Base {
    int baseZ;
    public:
    Derived2() {
        cout << "Derived2 constructor called" << endl;
    }

    void derived2MemFunc1() {
        cout << "Inside derived2 memFunc1" << endl;
    }

    ~Derived2() {
        cout << "Derived2 destructor called" << endl;
    }
};

class Derived3: public Derived1 {
    int baseW;
    public:
    Derived3() {
        cout << "Derived3 constructor called" << endl;
    }

    void derived3MemFunc1() {
        cout << "Inside derived3 memFunc1" << endl;
    }

    ~Derived3() {
        cout << "Derived3 destructor called" << endl;
    }
};

int main() {
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;
    // d1.baseMemFunc1();
    // d1.derived1MemFunc1();
    // d2.baseMemFunc1();
    // d2.derived2MemFunc1();
    // d3.derived3MemFunc1();
    return 0;
}

// Base constructor called
// Derived1 constructor called
// Base constructor called
// Derived2 constructor called
// Base constructor called
// Derived1 constructor called
// Derived3 constructor called
// Derived3 destructor called
// Derived1 destructor called
// Base destructor called
// Derived2 destructor called
// Base destructor called
// Derived1 destructor called
// Base destructor called




/*
Base Subobject:
- A base subobject is the portion of a derived class that represents its base class
- When a class inherits from a base class:
    * A base subobject is created within the derived class
    * One subobject per base class
    * Contains inherited attributes and behaviors
    * Enables derived class to access base class members

Example:
class Base {};
class Derived : public Base {}; 
// Derived contains a Base subobject
*/