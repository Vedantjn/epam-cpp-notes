// The = default specifier is used to explicitly request the 
// compiler to generate a default implementation of a special
// member function (e.g., default constructor, copy constructor, 
// move constructor, etc.).

// When to Use = default:
// When you want to explicitly state that the default behavior of a special member function (constructor, destructor, etc.) is acceptable.
// When you need to define a constructor as default in a class that already defines other constructors.



#include<iostream>
#include<string>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Default constructor
    Person() = default;

    // Parameterized constructor
    Person(string n, int a) : name(n), age(a) {}

    // Defaulted destructor
    ~Person() = default;
};

int main() {
    Person p1; // Uses default constructor
    Person p2("Vedant", 22); // Uses parameterized constructor

    cout << "Name: " << p2.name << ", Age: " << p2.age << endl;
    return 0;
}

// -------------------------------------------

// The = delete specifier is used to explicitly disallow a special 
// member function. If someone tries to use a deleted function, the 
// compiler will generate an error.

// When to Use = delete:
// To prevent certain operations (e.g., copying, moving) on objects that are not intended to be copied or moved.
// To avoid unintended implicit conversions.
// To block usage of specific constructors or functions.

#include <iostream>
using namespace std;

class NonCopyable {
public:
    NonCopyable() = default;

    // Disable copy and move operations
    NonCopyable(const NonCopyable&) = delete; // Copy constructor
    NonCopyable& operator=(const NonCopyable&) = delete; // Copy assignment
    NonCopyable(NonCopyable&&) = delete; // Move constructor
    NonCopyable& operator=(NonCopyable&&) = delete; // Move assignment
};

int main() {
    NonCopyable obj1;
    NonCopyable obj2 = obj1; // Error: Copy constructor is deleted
    NonCopyable obj3 = std::move(obj1); // Error: Move constructor is deleted

    return 0;
}
