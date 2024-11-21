// // std::list::push_back vs std::list::emplace_back

// // Both push_back and emplace_back are used to add elements to a std::list. However, they differ in how they construct the elements:

// // push_back:
// // - Takes an already-constructed object as an argument.
// // - This means:
// //   - If you pass an lvalue, the copy constructor is called.
// //   - If you pass an rvalue, the move constructor is called.

// // emplace_back:
// // - Constructs the object in-place at the back of the list using the provided arguments.
// // - It avoids a separate construction and move/copy step.
// // - No move or copy constructor is called unless required internally (e.g., if the list resizes or rebalances, which rarely happens for std::list).

// #include <iostream>
// #include <list>
// #include <string>

// using namespace std;

// class MyClass {
// public:
//     MyClass(const string& name) : name(name) {
//         cout << "Constructor called for " << name << endl;
//     }

//     MyClass(const MyClass& other) : name(other.name) {
//         cout << "Copy constructor called for " << name << endl;
//     }

//     MyClass(MyClass&& other) noexcept : name(std::move(other.name)) {
//         cout << "Move constructor called for " << name << endl;
//     }

// private:
//     string name;
// };

// int main() {
//     list<MyClass> l1;
//     l1.push_back(MyClass("object1")); // Move constructor is called here
//     l1.emplace_back("object2"); // Direct construction, no copy or move constructor is called

//     return 0;
// }

// // Constructor called for object1
// // Move constructor called for object1
// // Constructor called for object2

// ---------------------------------

#include <iostream>
#include <list>
#include <string>

using namespace std;

class MyClass {
private:
    string name;

public:
    // Constructor
    MyClass(const string& n) : name(n) {
        cout << "Constructor called for: " << name << endl;
    }

    // Copy Constructor
    MyClass(const MyClass& other) : name(other.name) {
        cout << "Copy Constructor called for: " << name << endl;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept : name(move(other.name)) {
        cout << "Move Constructor called for: " << name << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called for: " << name << endl;
    }
};

int main() {
    list<MyClass> l1;

    cout << "\nUsing push_back with an rvalue:\n";
    l1.push_back(MyClass("Object1")); // Constructor + Move Constructor

    cout << "\nUsing emplace_back:\n";
    l1.emplace_back("Object2"); // Constructor only (in-place construction)

    cout << "\nUsing push_back with an lvalue:\n";
    MyClass obj("Object3");
    l1.push_back(obj); // Copy Constructor

    cout << "\nEnd of main, destructors will be called:\n";
    return 0;
}

// Using push_back with an rvalue:
// Constructor called for: Object1
// Move Constructor called for: Object1
// Destructor called for:

// Using emplace_back:
// Constructor called for: Object2

// Using push_back with an lvalue:
// Constructor called for: Object3
// Copy Constructor called for: Object3

// End of main, destructors will be called:
// Destructor called for: Object3
// Destructor called for: Object1
// Destructor called for: Object2
// Destructor called for: Object3

// ---------------------------------------
// Step-by-Step Analysis
// l1.push_back(MyClass("Object1"));
// MyClass("Object1") creates a temporary object using the constructor.
// Move constructor is called to transfer ownership of this temporary object to the list.
// The temporary object is then destroyed.


// l1.emplace_back("Object2");
// Constructs the object in-place at the back of the list using the provided string argument "Object2".
// No move or copy constructor is called.


// l1.push_back(obj);
// The lvalue obj is passed to push_back, which calls the copy constructor to create a copy of obj and adds it to the list.


// Comparison
// Feature                push_back                             emplace_back
// Parameters             Requires a fully constructed object.  Accepts arguments to construct the object in-place.
// Constructor Calls      May call copy or move constructors.    Constructs directly in-place, avoiding unnecessary moves/copies.
// Efficiency             Slightly less efficient due to additional construction.  More efficient for complex objects.
// Use Case               Use when the object is already constructed.  Use when you need to construct the object in-place.// Key Takeaways
// push_back may invoke either the copy or move constructor based on whether you pass an lvalue or rvalue.
// emplace_back directly constructs the object in the container, avoiding unnecessary moves or copies.
// Prefer emplace_back for performance when constructing objects directly in the container.