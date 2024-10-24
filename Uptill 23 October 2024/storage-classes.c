1. Automatic Storage Class (auto)
// Variables declared inside functions are automatically 'auto'
// They are created when function starts and destroyed when function ends
// Memory is allocated from stack
#include <stdio.h>

void func() {
    auto int x = 10;  // Optional use of `auto`; default is local
    printf("x = %d\n", x);
}

int main() {
    func();
    return 0;
}
Output:
x = 10

// -------------------------------------------------------------

2. Register Storage Class (register)
// Requests compiler to store variable in CPU register instead of memory
// Faster access but limited availability
#include <stdio.h>

void func() {
    register int i;
    for (i = 0; i < 5; i++) {
        printf("%d ", i);
    }
}

int main() {
    func();
    return 0;
}
Output:
0 1 2 3 4

// -------------------------------------------------------------

3. Static Storage Class (static)
// Preserves variable value between function calls
// Memory allocated for entire program runtime
// Only initialized once
#include <stdio.h>

void func() {
    static int count = 0;  // Retains its value between function calls
    count++;
    printf("Count = %d\n", count);
}

int main() {
    func();
    func();
    func();
    return 0;
}
Output:
Count = 1
Count = 2
Count = 3

// -------------------------------------------------------------

4. External Storage Class (extern)
// Used to share variables between multiple files
// Variable is defined in one file and declared in others
// Global scope throughout program
// File: file1.c
#include <stdio.h>

int globalVar = 100;  // Definition of the global variable

void display() {
    printf("globalVar = %d\n", globalVar);
}

// File: file2.c
extern int globalVar;  // Declaration of the global variable

int main() {
    printf("globalVar = %d\n", globalVar);
    return 0;
}

Output (when both files are properly linked):
globalVar = 100