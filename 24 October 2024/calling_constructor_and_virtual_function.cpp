// if you have both constructor and virtual function, what will be called first?

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor\n";
        show();  // Calls Base::show(), not Derived::show()
    }

    virtual void show() {
        cout << "Base show\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor\n";
    }

    void show() override {
        cout << "Derived show\n";
    }
};

int main() {
    Derived d;
    return 0;
}

// Base Constructor
// Base show
// Derived Constructor



// The Base constructor runs first.
// When show() is called within Base's constructor, it does not invoke Derived::show()
// but rather Base::show() because the Derived part of the object hasn’t been fully constructed.
// After Base's constructor completes, the Derived constructor runs, and at this point, the vtable
//  for Derived is fully established.