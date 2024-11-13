#include <iostream>
using namespace std;

int main() {
    // C-style casting 
    int num = 10;
    float decimal = (float)num;  // C-style cast from int to float

    double pi = 3.14159;
    int rounded = (int)pi;  // C-style cast from double to int

    char ch = 'A';
    int ascii = (int)ch;  // C-style cast from char to int

    // Pointer casting
    int* ptr = &num;
    long long addr = (long long)ptr;  // C-style cast from pointer to long long

    // Display results
    cout << "Original int: " << num << endl;
    cout << "Converted to float: " << decimal << endl;
    cout << "Original double: " << pi << endl;
    cout << "Converted to int: " << rounded << endl;
    cout << "Character: " << ch << endl;
    cout << "ASCII value: " << ascii << endl;
    cout << "Pointer address as long long: " << addr << endl;

    return 0;
}

// Original int: 10
// Converted to float: 10
// Original double: 3.14159
// Converted to int: 3
// Character: A
// ASCII value: 65
// Pointer address as long: 603960900620

// -------------------------------------------------------------

#include <iostream>
using namespace std;

int main() {
    // C-style casting 
    int num = 10;
    float decimal = static_cast<float>(num);  // C++-style cast from int to float
    
    double pi = 3.14159;
    int rounded = static_cast<int>(pi);  // C++-style cast from double to int
    
    char ch = 'A';
    int ascii = static_cast<int>(ch);  // C++-style cast from char to int
    
    // Pointer casting
    int* ptr = &num;  // Initialize pointer to the address of num
    long long addr = reinterpret_cast<long long>(ptr);  // C++-style cast from pointer to long
    // reinterpret_cast is used to cast between pointer types and integer types, providing clarity and type safety.

    // Display results
    cout << "Original int: " << num << endl;
    cout << "Converted to float: " << decimal << endl;
    cout << "Original double: " << pi << endl;
    cout << "Converted to int: " << rounded << endl;
    cout << "Character: " << ch << endl;
    cout << "ASCII value: " << ascii << endl;
    cout << "Pointer address as long long: " << addr << endl;
    
    return 0;
}

// Original int: 10
// Converted to float: 10
// Original double: 3.14159
// Converted to int: 3
// Character: A
// ASCII value: 65
// Pointer address as long: 682788650380
