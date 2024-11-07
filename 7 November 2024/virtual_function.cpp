#include <iostream>
using namespace std;

class Base {
public:
    // Virtual function
    virtual void show() {
        cout << "Base show" << endl;
    }
    
    // Non-virtual function
    void display() {
        cout << "Base display" << endl;
    }
    
    // Virtual destructor
    virtual ~Base() {}
};

// Derived class inheriting from Base
class Derived : public Base {
public:
    // Override virtual function
    void show() override {
        cout << "Derived show" << endl;
    }
    
    // Hide base class display
    void display() {
        cout << "Derived display" << endl;
    }
};

int main() {
    // Create base pointer to derived object
    Base *b = new Derived;
    
    b->show();    // Calls Derived's show() due to virtual function
    b->display(); // Calls Base's display() as it's non-virtual

    // Clean up
    delete b;
    return 0;
}

// Output:
// Derived show
// Base display



// 1. Virtual Functions in C++:
//     - Functions in base class that can be overridden in derived classes
//     - Used for runtime polymorphism
//     - Defined using 'virtual' keyword

// 2. Purpose:
//     - Enables dynamic binding/runtime polymorphism
//     - Allows function overriding in derived classes
//     - Function call depends on actual object type, not pointer type

// 3. Working Mechanism:
//     - Compiler creates virtual table (vtable) for classes with virtual functions
//     - Objects contain virtual pointer (vptr) to vtable
//     - Dynamic dispatch occurs at runtime through vtable

// 4. Key Features:
//     - Virtual keyword used in base class
//     - Override keyword used in derived class
//     - Supports polymorphic behavior
//     - Base class destructor should be virtual

// 5. Implementation Benefits:
//     - Runtime polymorphism through base class pointers
//     - Flexible and maintainable code
//     - Common interface with specific implementations

// 6. Considerations:
//     - Memory overhead due to vtable and vptr
//     - Slightly slower execution than non-virtual functions
//     - Pure virtual functions create abstract classes
//     - Proper cleanup requires virtual destructors