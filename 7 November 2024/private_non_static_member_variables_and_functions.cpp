// Private Non-Static Member Variables and Functions in C++

// 1. Definition:
//    - These are class members declared with the private access specifier
//    - They are instance-specific (non-static) members

// 2. Key Characteristics:
//    a) Access Control:
//       - Only accessible within the class itself
//       - Not directly accessible from outside the class

//    b) Instance Binding:
//       - Associated with individual class instances
//       - Each object has its own copy of these members
//       - Not shared across class instances

#include <iostream>
using namespace std;

class Person
{
private:
    string name; // Private non-static member variable
    int age;     // Private non-static member variable

public:
    // Constructor to initialize private member variables
    Person(const string &name, int age) : name(name), age(age) {}

    string getName() const { return name; }

    void setName(const string &newName) { name = newName; }

    int getAge() const { return age; }

    void setAge(int newAge) { age = newAge; }
};

int main()
{
    Person p("Alice", 25);

    // Accessing private member variables through public getters and setters
    cout << "Name: " << p.getName() << ", Age: " << p.getAge() << endl;

    p.setName("Bob");
    p.setAge(30);

    cout << "Updated Name: " << p.getName() << ", Updated Age: " << p.getAge() << endl;

    return 0;
}

// Name: Alice, Age: 25
// Updated Name: Bob, Updated Age: 30
