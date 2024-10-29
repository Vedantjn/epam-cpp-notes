#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    // Member variables (attributes)
    string name;
    int age;
    double gpa;

public:
    // Constructor
    Student(string n, int a, double g) {
        name = n;
        age = a;
        gpa = g;
    }

    // Member functions (methods)
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        if (a > 0) {
            age = a;
        }
    }

    int getAge() {
        return age;
    }

    void setGPA(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        }
    }

    double getGPA() {
        return gpa;
    }

    void displayInfo() {
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    // Creating an object of Student class
    Student student1("John Doe", 20, 3.8);
    
    // Using member functions
    student1.displayInfo();
    
    // Modifying values using setter functions
    student1.setName("Jane Doe");
    student1.setAge(21);
    student1.setGPA(3.9);
    
    cout << "\nAfter modification:" << endl;
    student1.displayInfo();
    
    // Accessing values using getter functions
    cout << "\nAccessing individual values:" << endl;
    cout << "Name: " << student1.getName() << endl;
    cout << "Age: " << student1.getAge() << endl;
    cout << "GPA: " << student1.getGPA() << endl;
    
    return 0;
}

// Student Information:
// Name: John Doe
// Age: 20
// GPA: 3.8

// After modification:
// Student Information:
// Name: Jane Doe
// Age: 21
// GPA: 3.9

// Accessing individual values:
// Name: Jane Doe
// Age: 21
// GPA: 3.9