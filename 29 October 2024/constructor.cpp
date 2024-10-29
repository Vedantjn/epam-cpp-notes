#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float *gpa;

public:
    // Default Constructor
    Student() {
        rollNo = 0;
        name = "Unknown";
        gpa = new float(0.0);
        cout << "Default Constructor called" << endl;
    }
    
    // Constructor with initialization list
    Student(int r) : rollNo(r), name("Default"), gpa(new float(2.0)) {
        cout << "Constructor with initialization list called" << endl;
    }

    // Parameterized constructor
    Student(int r, string n, float g) {
        rollNo = r;
        name = n;
        gpa = new float(g);
        cout << "Parameterized Constructor called" << endl;
    }

    // Copy Constructor
    Student(const Student &obj) {
        rollNo = obj.rollNo;
        name = obj.name;
        gpa = new float(*obj.gpa);  // Deep copy
        cout << "Copy Constructor called" << endl;
    }

    // Assignment Operator
    Student& operator=(const Student &obj) {
        if (this != &obj) {  // Self-assignment check
            rollNo = obj.rollNo;
            name = obj.name;
            delete gpa;  // Free existing memory
            gpa = new float(*obj.gpa);  // Deep copy
        }
        cout << "Assignment Operator called" << endl;
        return *this;
    }

    // Destructor
    ~Student() {
        delete gpa;
        cout << "Destructor called" << endl;
    }

    // Display method
    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "GPA: " << *gpa << endl;
    }
    
};

int main() {
    // Default constructor usage
    Student s1;
    s1.display();

    // Parameterized constructor usage
    Student s2(101, "John", 3.8);
    s2.display();

    // Copy constructor usage
    Student s3(s2); // preferred
    // Student s3 = s2; 
    s3.display();

    // Assignment operator usage -> not preferred
    Student s4;
    s4 = s2;
    s4.display();

    return 0;
}

// Default Constructor called
// Roll No: 0
// Name: Unknown
// GPA: 0
// Parameterized Constructor called
// Roll No: 101
// Name: John
// GPA: 3.8
// Copy Constructor called
// Roll No: 101
// Name: John
// GPA: 3.8
// Default Constructor called
// Assignment Operator called
// Roll No: 101
// Name: John
// GPA: 3.8
// Destructor called
// Destructor called
// Destructor called
// Destructor called