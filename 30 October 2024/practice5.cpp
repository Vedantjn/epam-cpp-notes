#include <iostream>
using namespace std;

class Student {
    int id;
    string name;
public:
    Student() {
        id = 0;
        name = "";
    }
    
    Student(int i, string n) {
        id = i;
        name = n;
    }
    
    // Copy constructor
    Student(const Student &obj) {
        id = obj.id;
        name = obj.name;
        cout << "Copy constructor called" << endl;
    }
    
    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    
    // Function demonstrating pass by value
    void passByValue(Student obj) {
        obj.id = 999;  // Changes won't affect original object
        obj.name = "Changed";
    }
    
    // Function demonstrating pass by reference
    void passByReference(Student &obj) {
        obj.id = 999;  // Changes will affect original object
        obj.name = "Changed";
    }
};

int main() {
    Student s1(1, "Vedant");
    cout << "Original object s1: ";
    s1.display();
    
    // Pass by value example
    s1.passByValue(s1);
    cout << "After pass by value: ";
    s1.display();
    
    // Pass by reference example
    s1.passByReference(s1);
    cout << "After pass by reference: ";
    s1.display();
    
    // Copy constructor example
    Student s2 = s1;  // Copy constructor called
    cout << "Copied object s2: ";
    s2.display();
    
    return 0;
}

// Original object s1: ID: 1, Name: Vedant
// Copy constructor called
// After pass by value: ID: 1, Name: Vedant
// After pass by reference: ID: 999, Name: Changed
// Copy constructor called
// Copied object s2: ID: 999, Name: Changed