#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    union {
        struct {
            float physics;
            float chemistry;
            float math;
        } science;
        struct {
            float economics;
            float accounting;
            float business;
        } commerce;
    } marks;
};

int main() {
    struct Student student1;
    
    // Initialize science student
    student1.id = 101;
    strcpy(student1.name, "Vedant");
    student1.marks.science.physics = 85.5;
    student1.marks.science.chemistry = 92.0;
    student1.marks.science.math = 88.5;
    
    printf("Student ID: %d\n", student1.id);
    printf("Name: %s\n", student1.name);
    printf("Physics: %.2f\n", student1.marks.science.physics);
    printf("Chemistry: %.2f\n", student1.marks.science.chemistry);
    printf("Math: %.2f\n", student1.marks.science.math);
    
    // Initialize commerce student using same memory space
    struct Student student2;
    student2.id = 102;
    strcpy(student2.name, "Samyak");
    student2.marks.commerce.economics = 91.0;
    student2.marks.commerce.accounting = 89.5;
    student2.marks.commerce.business = 94.0;
    
    printf("\nStudent ID: %d\n", student2.id);
    printf("Name: %s\n", student2.name);
    printf("Economics: %.2f\n", student2.marks.commerce.economics);
    printf("Accounting: %.2f\n", student2.marks.commerce.accounting);
    printf("Business: %.2f\n", student2.marks.commerce.business);
    
    return 0;
}

// Output:

// Student ID: 101
// Name: Vedant
// Physics: 85.50
// Chemistry: 92.00
// Math: 88.50

// Student ID: 102
// Name: Samyak
// Economics: 91.00
// Accounting: 89.50
// Business: 94.00