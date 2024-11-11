#include <iostream>
using namespace std;

// // Declaring a constant integer 'a' with value 5
// const int a = 5;

// // Creating a pointer to a constant integer - can't modify value through pointer
// const int* ptr = &a;

// // Error: Cannot initialize int* const with const int*
// // This line is invalid because we cannot assign address of const int to a non-const pointer
// // Even though the pointer itself is const, it would allow modifying a const value
// int* const ptr = &a;

int main() {
    // Case 1: Attempting to create a constant pointer to a constant integer
    // const int a = 10;
    // int* const ptr = &a;  // Error: Cannot initialize int* const with const int*
    // This would not compile since ptr would allow modifying `a` through the pointer,
    // but `a` is declared `const`.

    const int a = 10;  // Const integer

    // Case 2: Constant pointer to non-const integer (cannot change address, but can modify value)
    int b = 20;
    int* const ptr2 = &b;  // Valid: const pointer to non-const integer
    // ptr2 = &a;          // Error: Cannot reassign a const pointer to point to another address
    *ptr2 = 30;           // Valid: Can modify the value through the pointer
    cout << "Case 2 - ptr2 points to b with new value: " << *ptr2 << endl;

    // Case 3: Can't modify const integer directly
    // a = 20;              // Error: Cannot modify a const integer

    // Case 4: Constant pointer to constant integer (cannot change address or modify value)
    const int* const ptr3 = &a;  // Valid: const pointer to const integer
    // *ptr3 = 40;          // Error: Cannot modify value through pointer to const
    // ptr3 = &b;           // Error: Cannot change where const pointer points to
    cout << "Case 4 - ptr3 points to a with value: " << *ptr3 << endl;

    // Case 5: Non-constant pointer to constant integer (can change address, but cannot modify value)
    const int* ptr4 = &a;  // Valid: non-const pointer to const integer
    ptr4 = &b;             // Valid: Can change pointer to point to another const int
    // *ptr4 = 50;         // Error: Cannot modify value through pointer to const
    cout << "Case 5 - ptr4 now points to b with value: " << *ptr4 << endl;

    // Summary of behaviors:
    cout << "\nSummary:" << endl;
    cout << "a (const int): " << a << endl;
    cout << "b (modifiable int through ptr2): " << b << endl;
    cout << "ptr2 (int* const) points to b: " << *ptr2 << endl;
    cout << "ptr3 (const int* const) points to a: " << *ptr3 << endl;
    cout << "ptr4 (const int*) can point to a or b, current value: " << *ptr4 << endl;

    return 0;
}
