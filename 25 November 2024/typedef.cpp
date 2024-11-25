#include <iostream>
#include <vector>
using namespace std;

// Typedef for basic types
typedef unsigned int uint;

// Typedef for a complex type
typedef int* intPointer;

// Typedef for struct
struct Point {
    int x, y;
};
typedef struct Point PointAlias;

// Typedef for array
typedef int Matrix[3][3];

// Typedef for function pointer
typedef void (*FuncPtr)(int);

// Function for function pointer example
void printNumber(int n) {
    cout << "Number: " << n << endl;
}

int main() {
    // Basic typedef usage
    uint a = 100;
    cout << "Unsigned int: " << a << endl;

    // Pointer typedef usage
    int num = 42;
    intPointer p = &num;
    cout << "Pointer value: " << *p << endl;

    // Struct typedef usage
    PointAlias pt = {10, 20};
    cout << "Point: (" << pt.x << ", " << pt.y << ")\n";

    // Array typedef usage
    Matrix mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Matrix:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    // Function pointer typedef usage
    FuncPtr f = printNumber;
    f(99);

    return 0;
}

// Unsigned int: 100
// Pointer value: 42
// Point: (10, 20)
// Matrix:
// 1 2 3
// 4 5 6
// 7 8 9
// Number: 99



// Modern Alternative: using
// C++11 introduced the using keyword as a more readable and flexible alternative to typedef. The using syntax is more consistent with template usage.

// Example Comparison:
// Using typedef:
// typedef unsigned int uint;

// Using using:
// using uint = unsigned int;


// template <typename T>
// using Vec = std::vector<T>;

// Vec<int> myVec; // Equivalent to std::vector<int>
