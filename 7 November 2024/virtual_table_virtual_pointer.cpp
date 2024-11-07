// Virtual Tables (vtables) and Virtual Pointers (vptrs) in C++

// 1. Virtual Table (vtable):
// - A vtable is a static table created for each class that contains virtual functions
// - It stores function pointers to virtual methods
// - Each class with virtual functions has exactly one vtable
// - The vtable contains addresses of the most derived virtual function implementations

// 2. Virtual Pointer (vptr):
// - Each object of a class with virtual functions contains a hidden vptr
// - The vptr points to the vtable of that object's class
// - Added automatically by the compiler
// - Helps in runtime method resolution


#include <iostream>
using namespace std;

class Base {
public:
      virtual void display() { cout << "Base display\n"; }
      virtual void show() { cout << "Base show\n"; }
};

class Derived : public Base {
public:
      void display() override { cout << "Derived display\n"; }
      void show() override { cout << "Derived show\n"; }
};

int main() {
     Base* ptr = new Derived();
     ptr->display();  // Will call Derived::display()
     ptr->show();     // Will call Derived::show()
    
     Base baseObj;
     baseObj.display();  // Will call Base::display()
     baseObj.show();     // Will call Base::show()
    
     delete ptr;
     return 0;
}

// Derived display
// Derived show
// Base display
// Base show


// Memory Layout:

// Base class object:
// [vptr][other members]
// ↓
// Base vtable:
// - Base::display()
// - Base::show()

// Derived class object:
// [vptr][other members]
// ↓
// Derived vtable:
// - Derived::display()
// - Derived::show()

// How it works:
// 1. When a virtual function is called through a pointer/reference:
//     Base* ptr = new Derived();
//     ptr->display();  // Calls Derived::display()

// 2. Runtime resolution:
//     - Program looks at object's vptr
//     - Follows vptr to class vtable
//     - Finds correct function address
//     - Executes that function

// Benefits:
// 1. Enables runtime polymorphism
// 2. Allows correct function calls based on actual object type
// 3. Supports dynamic dispatch of methods

// Memory considerations:
// - Each object with virtual functions has extra memory for vptr (usually 4 or 8 bytes)
// - Each class with virtual functions has one vtable in memory
// - Small overhead for virtual function calls due to extra indirection