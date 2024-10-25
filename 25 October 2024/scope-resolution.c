#include <stdio.h>

int x = 10;  // global variable

void test() {
    int x = 20;  // local variable
    {
        int x = 30;  // block-level variable
        printf("Block-level x: %d\n", x);
    }
    printf("Local x: %d\n", x);
}

int main() {
    printf("Global x: %d\n", x);
    test();
    printf("Global x after test: %d\n", x);
    return 0;
}

// Output:
// Global x: 10
// Block-level x: 30
// Local x: 20
// Global x after test: 10

// --------------------------------------------------------

// In C, there is no direct scope resolution operator like '::' in C++
// However, we can use the 'extern' keyword to explicitly access global variables

#include <stdio.h>

int x = 10;  // global variable

void test() {
    int x = 20;  // local variable
    {
        int x = 30;  // block-level variable
        printf("Block-level x: %d\n", x);
    }
    printf("Local x: %d\n", x);
    {
        extern int x;  // This is how we can refer to global x in C
        printf("Global x from function: %d\n", x);
    }
}

int main() {
    printf("Global x: %d\n", x);
    test();
    printf("Global x after test: %d\n", x);
    return 0;
}

// Output:
// Global x: 10
// Block-level x: 30
// Local x: 20
// Global x from function: 10
// Global x after test: 10

// Note: True scope resolution operator '::' only exists in C++
// In C, variable shadowing cannot be overcome directly
// The extern keyword can be used to access global variables