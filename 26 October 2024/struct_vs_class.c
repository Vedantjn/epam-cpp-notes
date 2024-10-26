/*
Key differences between struct and class:

1. Access Control:
   - struct: Members are public by default
   - class: Members are private by default

2. Inheritance:
   - struct: Public inheritance by default
   - class: Private inheritance by default

3. Usage Convention:
   - struct: Typically used for passive data structures
   - class: Used for active objects with methods/behavior

C doesn't support classes
*/

#include <string.h>
#include <stdio.h>

// Structure - Data focused, public by default
struct StudentStruct {
    char name[50];    // public by default
    int age;          // public by default
    float gpa;        // public by default
};

// Class - Behavior focused, private by default
// class StudentClass {
// private:              // private by default even without this
//     char name[50];
//     int age;
//     float gpa;
    
// public:              // needs explicit public declaration
//     void setName(char* n) {
//         strcpy(name, n);
//     }
//     void setAge(int a) {
//         age = a;
//     }
//     void setGPA(float g) {
//         gpa = g;
//     }
//     void display() {
//         printf("Name: %s\n", name);
//         printf("Age: %d\n", age);
//         printf("GPA: %.2f\n", gpa);
//     }
// };

int main() {
    // Using struct - direct access to members
    struct StudentStruct s1;
    strcpy(s1.name, "Vedant");    // Direct access allowed
    s1.age = 20;                // Direct access allowed
    s1.gpa = 3.8;               // Direct access allowed
    
    // // Using class - access through methods
    // StudentClass s2;
    // s2.setName("John");         // Must use methods
    // s2.setAge(20);              // Must use methods
    // s2.setGPA(3.8);             // Must use methods
    // s2.display();
    
    return 0;
}