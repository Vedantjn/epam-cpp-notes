// Size of structure is determined by its members
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];     // 50 bytes
    int rollNumber;    // 4 bytes
    float marks;       // 4 bytes
};  // Total: 58 bytes (may include padding)

struct Point {
    int x;            // 4 bytes
    int y;            // 4 bytes
};  // Total: 8 bytes

struct Address {
    char street[50];   // 50 bytes
    char city[30];     // 30 bytes
    char state[20];    // 20 bytes
    int pincode;       // 4 bytes
};  // Total: 104 bytes (may include padding)

struct Employee {
    char name[50];     // 50 bytes
    int id;            // 4 bytes
    struct Address addr;  // nested structure (104 bytes)
    float salary;      // 4 bytes
};  // Total: 162 bytes (may include padding)

int main() {
    // Print sizes of each structure
    printf("Size of Student structure: %zu bytes\n", sizeof(struct Student));
    printf("Size of Point structure: %zu bytes\n", sizeof(struct Point));
    printf("Size of Address structure: %zu bytes\n", sizeof(struct Address));
    printf("Size of Employee structure: %zu bytes\n\n", sizeof(struct Employee));

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

// Size of Student structure: 60 bytes
// Size of Point structure: 8 bytes    
// Size of Address structure: 104 bytes
// Size of Employee structure: 164 bytes

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