// Function-like Macros in C++
/*
Definition:
- Preprocessor directives that define reusable instructions
- Function-like behavior without being actual functions
- Defined using #define directive

Characteristics:
- No type checking
- Code substitution at preprocessing
- Helps reduce code repetition

Example:
#define SQUARE(x) ((x) * (x))
*/

#include <iostream>
using namespace std;

// Define a macro for adding two numbers
#define ADD(x, y) ((x) + (y))

int main() {
    int a = 5, b = 10;
    int sum = ADD(a, b);  // Using the macro
    cout << "Sum: " << sum << endl;  //  15

    return 0;
}

// -----------------------------------------------

#include <iostream>
using namespace std;

// Macro to swap two numbers
#define SWAP(a, b) { \
    int temp = a; \
    a = b; \
    b = temp; \
}

int main() {
    int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;

    SWAP(x, y);  // Using the macro to swap

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
