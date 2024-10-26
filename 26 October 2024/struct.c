#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

struct Point {
    int x;
    int y;
};

struct Address {
    char street[50];
    char city[30];
    char state[20];
    int pincode;
};

struct Employee {
    char name[50];
    int id;
    struct Address addr;  // nested structure
    float salary;
};

int main() {
    // Basic structure usage
    struct Student student1;
    strcpy(student1.name, "Vedant Jain");
    student1.rollNumber = 101;
    student1.marks = 85.5;
    
    printf("Student Details:\n");
    printf("Name: %s\n", student1.name);
    printf("Roll Number: %d\n", student1.rollNumber);
    printf("Marks: %.2f\n\n", student1.marks);

    // Structure initialization
    struct Point p1 = {10, 20};
    printf("Point Coordinates: (%d, %d)\n\n", p1.x, p1.y);

    // Nested structure
    struct Employee emp1;
    strcpy(emp1.name, "Akshay Kumar");
    emp1.id = 1001;
    strcpy(emp1.addr.street, "131 B Vaibhav nagar ext.");
    strcpy(emp1.addr.city, "Indore");
    strcpy(emp1.addr.state, "MP");
    emp1.addr.pincode = 10001;
    emp1.salary = 66666.0;

    printf("Employee Details:\n");
    printf("Name: %s\n", emp1.name);
    printf("ID: %d\n", emp1.id);
    printf("Address: %s, %s, %s - %d\n", 
           emp1.addr.street, 
           emp1.addr.city, 
           emp1.addr.state, 
           emp1.addr.pincode);
    printf("Salary: %.2f\n", emp1.salary);

    return 0;
}

// Output:
// Student Details:
// Name: Vedant Jain
// Roll Number: 101
// Marks: 85.50

// Point Coordinates: (10, 20)

// Employee Details:
// Name: Akshay Kumar
// ID: 1001
// Address: 131 B Vaibhav nagar ext., Indore, MP - 10001
// Salary: 66666.00