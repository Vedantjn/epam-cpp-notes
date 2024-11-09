// why the base class destructor should be virtual when dealing with inheritance.

#include <iostream>
using namespace std;

class Base {
public:
    // Virtual destructor to ensure derived destructors are called
    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived1 : virtual public Base {
public:
    // Virtual destructor for proper cleanup of Derived1
    virtual ~Derived1() {
        cout << "Derived1 destructor called" << endl;
    }
};

class Derived2 : virtual public Base {
public:
    // Virtual destructor for proper cleanup of Derived2
    virtual ~Derived2() {
        cout << "Derived2 destructor called" << endl;
    }
};

class Diamond : public Derived1, public Derived2 {
public:
    // Virtual destructor for proper cleanup of Diamond
    virtual ~Diamond() {
        cout << "Diamond destructor called" << endl;
    }
};

int main() {
    // Creating a pointer to Base, but pointing to a Diamond object
    Base* ptr = new Diamond();

    // Deleting ptr, triggers destructors from Diamond down to Base
    delete ptr;

    return 0;
}

// Diamond destructor called
// Derived2 destructor called
// Derived1 destructor called
// Base destructor called

// Without a virtual destructor in Base, calling delete ptr; on a Base* pointer
// to a Diamond object would lead to undefined behavior. Only the destructor of 
// Base would be called, resulting in a memory leak, as destructors for the derived
// classes wouldn’t be executed.

// -------------------------------------------------------------

// why the base class destructor should be virtual when dealing with inheritance.

#include <iostream>
using namespace std;

class Base {
public:
    // Without Virtual destructor 
    ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived1 : virtual public Base {
public:
    // Virtual destructor for proper cleanup of Derived1
    virtual ~Derived1() {
        cout << "Derived1 destructor called" << endl;
    }
};

class Derived2 : virtual public Base {
public:
    // Virtual destructor for proper cleanup of Derived2
    virtual ~Derived2() {
        cout << "Derived2 destructor called" << endl;
    }
};

class Diamond : public Derived1, public Derived2 {
public:
    // Virtual destructor for proper cleanup of Diamond
    virtual ~Diamond() {
        cout << "Diamond destructor called" << endl;
    }
};

int main() {
    // Creating a pointer to Base, but pointing to a Diamond object
    Base* ptr = new Diamond();

    delete ptr;

    return 0;
}

// Base destructor called

