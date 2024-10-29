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

// -----------------------------------------------------------------------------

  #include <iostream>
  #include <cstring>
  using namespace std;

  class Student {
      int rollNo;
      char* name;
      float* gpa;
  public:
      // Default constructor
      Student() {
          cout << "Default Constructor called" << endl;
          rollNo = 0;
          name = new char[8];
          strcpy(name, "Unknown");
          gpa = new float;
          *gpa = 0.0;
      }
    
      // Parameterized constructor
      Student(int r, const char* n, float g) {
          cout << "Parameterized Constructor called" << endl;
          rollNo = r;
          name = new char[strlen(n) + 1];
          strcpy(name, n);
          gpa = new float;
          *gpa = g;
      }
    
      // Copy constructor without reference (&)
      Student(Student s) {  // This creates infinite recursion!
          cout << "Copy Constructor called" << endl;
          rollNo = s.rollNo;
          name = new char[strlen(s.name) + 1];
          strcpy(name, s.name);
          gpa = new float;
          *gpa = *s.gpa;
      }
    
      // Assignment operator
      Student& operator=(const Student& s) {
          cout << "Assignment Operator called" << endl;
          if(this != &s) {
              rollNo = s.rollNo;
              delete[] name;
              name = new char[strlen(s.name) + 1];
              strcpy(name, s.name);
              *gpa = *s.gpa;
          }
          return *this;
      }
    
      // Destructor
      ~Student() {
          cout << "Destructor called" << endl;
          delete[] name;
          delete gpa;
      }
    
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

// constructor.cpp:143:7: error: invalid constructor; you probably meant 'Student (const Student&)'
//   143 |       Student(Student s) {  // This creates infinite recursion!

/*
The 'const' keyword in copy constructor (Student(const Student& s)) serves several important purposes:

1. Prevents Modification: 
   - It ensures that the source object cannot be modified during copying
   - Protects against accidental changes to the original object

2. Avoids Infinite Recursion:
   - Without const, passing by value would create infinite copies
   - The signature Student(Student s) would keep creating new copies recursively

3. Efficiency:
   - Allows passing both const and non-const objects to the copy constructor
   - Compiler can optimize better with const guarantee

4. Best Practice:
   - It's a standard practice to make copy constructor parameter const
   - Makes code safer and more maintainable

Proper copy constructor:
Student(const Student& s) {
    // Copy implementation here
}
*/
