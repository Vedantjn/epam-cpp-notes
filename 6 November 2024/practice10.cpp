#include <iostream>
using namespace std;

int main() {
    // Implicit type casting (automatic)
    int num1 = 10;
    double num2 = num1;    // int to double
    cout << "Implicit casting int to double: " << num2 << endl;
    
    // Explicit type casting (manual)
    double pi = 3.14159;
    int roundedPi = (int)pi;    // C-style casting
    cout << "Explicit casting double to int: " << roundedPi << endl;
    
    // Static cast
    float floatNum = 25.75;
    // static_cast is a C++ casting operator that performs compile-time type checking
    // and converts one data type to another in a type-safe way
    int intNum = static_cast<int>(floatNum);    // Converts 25.75 to 25 by truncating decimal part
    cout << "Static cast float to int: " << intNum << endl;    
    return 0;
}

// Implicit casting int to double: 10
// Explicit casting double to int: 3
// Static cast float to int: 25