#include <stdio.h>

struct Point {
    int x;
    int y;
} point = {0}; // All members initialized to 0

union Data {
    int i;
    float f;
    char str[20];
} data = {0}; // First member initialized to 0

struct Complex {
    double real;
    double imag;
    char description[50];
} complex = {.real = 0.0, .imag = 0.0, .description = ""}; // Named member initialization

typedef struct {
    int id;
    char name[30];
    float salary;
} Employee;

int main() {
    // Default initialization of struct
    struct Point p1 = {0};
    
    // Default initialization of union
    union Data d1 = {0};
    
    // Zero initialization of array of structs
    Employee employees[10] = {0};
    
    // Partial initialization
    struct Complex c1 = {.real = 1.0}; // Other members get default values
    
    printf("Point: x=%d, y=%d\n", p1.x, p1.y);
    printf("Union Data (as int): %d\n", d1.i);
    printf("First employee ID: %d\n", employees[0].id);
    printf("Complex: real=%.2f, imag=%.2f\n", c1.real, c1.imag);
    
    return 0;
}

// Output:

// Point: x=0, y=0
// Union Data (as int): 0
// First employee ID: 0
// Complex: real=1.00, imag=0.00
