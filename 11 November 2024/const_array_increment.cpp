
#include <iostream>
using namespace std;

int main() {
    // Case 1: Constant pointer to non-constant data
    int value1 = 10, value2 = 20;
    int* const ptr1 = &value1;
    *ptr1 = 30;  // Valid: can modify the value
    // ptr1 = &value2;  // Invalid: cannot modify pointer

    // Case 2: Non-constant pointer to constant data
    const int val1 = 100, val2 = 200;
    const int* ptr2 = &val1;
    ptr2 = &val2;  // Valid: can modify pointer
    // *ptr2 = 300;  // Invalid: cannot modify the value

    // Case 3: Constant pointer to constant data
    const int num1 = 1000, num2 = 2000;
    const int* const ptr3 = &num1;
    // ptr3 = &num2;  // Invalid: cannot modify pointer
    // *ptr3 = 3000;  // Invalid: cannot modify the value

    // Array increment examples
    int arr[] = {1, 2, 3, 4, 5};
    int* arrPtr = arr;

    cout << "Array values using pointer increment:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << *arrPtr << " ";
        arrPtr++;  // Incrementing pointer address
    }
    cout << endl;

    // Constant array example
    const int constArr[] = {10, 20, 30, 40, 50};
    const int* constArrPtr = constArr;

    cout << "Constant array values using pointer increment:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << *constArrPtr << " ";
        constArrPtr++;  // Can increment pointer address even for const array
    }
    cout << endl;

    return 0;
}

// Array values using pointer increment:
// 1 2 3 4 5
// Constant array values using pointer increment:
// 10 20 30 40 50