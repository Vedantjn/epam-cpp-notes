#include <iostream>
using namespace std;

#define SQUARE(x) ((x) * (x))

#define MAX(a,b) ((a) > (b) ? (a) : (b))

inline int cube(int x) {
    return x * x * x;
}

inline bool isEven(int num) {
    return (num % 2 == 0);
}

int main() {
    int num1 = 5, num2 = 7;
    
    // Using macros
    cout << "Square of " << num1 << " is: " << SQUARE(num1) << endl;
    cout << "Maximum between " << num1 << " and " << num2 << " is: " << MAX(num1, num2) << endl;
    
    // Using inline functions
    cout << "Cube of " << num1 << " is: " << cube(num1) << endl;
    cout << num1 << " is " << (isEven(num1) ? "even" : "odd") << endl;
    
    return 0;
}

// Square of 5 is: 25
// Maximum between 5 and 7 is: 7
// Cube of 5 is: 125
// 5 is odd