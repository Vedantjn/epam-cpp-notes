// When we've already defined constructor, then default constructor won't be called

#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;
public:
    Student(int r, string n) {
        roll = r;
        name = n;
        cout << "Parameterized constructor called" << endl;
    }
    
    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};

int main() {
    // This will call parameterized constructor
    Student s1(101, "John");
    s1.display();
    
    // This will give error as default constructor is not available
    // Student s2; // Uncommenting this line will cause compilation error
    
    return 0;
}

// Parameterized constructor called
// Roll: 101, Name: John

// -----------------------------------------------------------------------------------------

// When we've already defined constructor, then default constructor won't be called

#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;
public:

    Student(int r = 0, string n = "Unknown") {
        roll = r;
        name = n;
        cout << "Parameterized constructor called" << endl;
    }
    
    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};

int main() {
    // This will call parameterized constructor
    Student s1(101, "John");
    s1.display();
    

    // Now this will work with default values
    Student s2;
    s2.display();
    
    return 0;
}

// Parameterized constructor called
// Roll: 101, Name: John
// Parameterized constructor called
// Roll: 0, Name: Unknown