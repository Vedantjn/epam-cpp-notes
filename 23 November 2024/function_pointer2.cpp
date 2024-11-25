#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main() {
    // Array of function pointers
    int (*operations[3])(int, int) = {add, subtract, multiply};

    int x = 10, y = 5;

    for (int i = 0; i < 3; ++i) {
        cout << "Operation " << i + 1 << ": " << operations[i](x, y) << endl;
    }

    return 0;
}

// Operation 1: 15
// Operation 2: 5
// Operation 3: 50