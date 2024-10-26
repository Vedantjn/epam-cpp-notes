// Size of structure is determined by its members and padding rules
#include <stdio.h>
#include <string.h>

// Padding is added based on:
// 1. CPU architecture (32-bit vs 64-bit)
// 2. Compiler alignment requirements
// 3. Structure member data types and their natural alignment
// 4. The largest member's alignment requirement
// 5. Rule of thumb: members are aligned to their own size boundaries
// 6. Padding is added between members and at the end to satisfy alignment

// Let's calculate padding for each structure:
struct Student {
    char name[50];     // 50 bytes
    // 2 bytes padding here to align int to 4-byte boundary (50 % 4 = 2 padding needed)
    int rollNumber;    // 4 bytes
    float marks;       // 4 bytes
};  // Total: 50 + 2(padding) + 4 + 4 = 60 bytes

struct Point {
    int x;            // 4 bytes (starts at offset 0)
    int y;            // 4 bytes (starts at offset 4)
};  // Total: 4 + 4 = 8 bytes (perfectly aligned, no padding needed)

struct Address {
    char street[50];   // 50 bytes
    char city[30];     // 30 bytes (starts at offset 50)
    char state[20];    // 20 bytes (starts at offset 80)
    // 0 bytes padding here because 100 % 4 = 0 (already aligned)
    int pincode;       // 4 bytes (starts at offset 100)
};  // Total: 50 + 30 + 20 + 4 = 104 bytes

struct Employee {
    char name[50];     // 50 bytes
    // 2 bytes padding here to align int to 4-byte boundary (50 % 4 = 2 padding needed)
    int id;            // 4 bytes
    struct Address addr;  // 104 bytes (starts at offset 56, already aligned)
    float salary;      // 4 bytes (starts at offset 160)
};  // Total: 50 + 2(padding) + 4 + 104 + 4 = 164 bytes

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