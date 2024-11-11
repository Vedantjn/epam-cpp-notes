#include <iostream>
using namespace std;

int main() {
    // Constant pointer to constant data
    const int value1 = 10;
    const int value2 = 20;
    const int* const ptr1 = &value1;  // Cannot modify pointer or data
    cout << "Constant pointer to constant data (ptr1): " << *ptr1 << endl;
    // ptr1 = &value2;  // Error: cannot modify pointer
    // *ptr1 = 30;      // Error: cannot modify data
    cout << "Constant pointer to constant data remains: " << *ptr1 << endl;

    // Constant pointer to non-constant data
    int data1 = 100;
    int data2 = 200;
    int* const ptr2 = &data1;  // Cannot modify pointer but can modify data
    *ptr2 += 50;               // Modifying data via pointer (100 + 50 = 150)
    cout << "Constant pointer to non-constant data after increment (ptr2): " << *ptr2 << endl;
    // ptr2 = &data2;          // Error: cannot modify pointer
    *ptr2 = 300;               // OK: can modify data directly
    cout << "Updated value in data1 via ptr2: " << *ptr2 << endl;

    // Non-constant pointer to constant data
    const int val1 = 1000;
    const int val2 = 2000;
    const int* ptr3 = &val1;  // Can change the address it points to but cannot modify data
    cout << "Non-constant pointer to constant data (ptr3): " << *ptr3 << endl;
    ptr3 = &val2;             // Changing pointer target
    cout << "Non-constant pointer to constant data after pointing to val2: " << *ptr3 << endl;
    // *ptr3 = 3000;          // Error: cannot modify constant data

    // Array example with constant pointer
    int arr[] = {1, 2, 3, 4, 5};
    int* const arrPtr = arr;  // Constant pointer to the first element of array
    cout << "Array elements before incrementing (arrPtr): ";
    for(int i = 0; i < 5; i++) {
        cout << *(arrPtr + i) << " ";
    }
    cout << endl;

    // Increment each array element using the constant pointer
    for(int i = 0; i < 5; i++) {
        *(arrPtr + i) += 1;
    }

    cout << "Array elements after incrementing each element by 1: ";
    for(int i = 0; i < 5; i++) {
        cout << *(arrPtr + i) << " ";
    }
    cout << endl;

    // Pointer arithmetic with non-constant pointer to non-constant data
    int values[] = {10, 20, 30, 40, 50};
    int* ptr4 = values; // Non-constant pointer to non-constant data
    cout << "Values array elements via pointer arithmetic (ptr4): ";
    for(int i = 0; i < 5; i++) {
        cout << *(ptr4 + i) << " ";
    }
    cout << endl;

    // Increment each element in values array using pointer arithmetic
    for(int i = 0; i < 5; i++) {
        *(ptr4 + i) += 5;
    }

    cout << "Values array elements after incrementing each element by 5: ";
    for(int i = 0; i < 5; i++) {
        cout << *(ptr4 + i) << " ";
    }
    cout << endl;

    // Incrementing the pointer itself (moving ptr4 through the array)
    cout << "Traversing values array with ptr4 incremented on each loop: ";
    ptr4 = values; // Reset to the start of the array
    for(int i = 0; i < 5; i++) {
        cout << *ptr4 << " ";
        ptr4++; // Move pointer to the next element
    }
    cout << endl;

    //=================================
    int nonConst_X = 33;
    int nonConst_Y = 40;
    nonConst_X = 20;
    //const int const_y;
    const int y = 10;
    int const z = 20;
    //y++;
    //int const z;
    int const z1 = 20;
    //z++;
    //z++;

    /*** 1. POINTER IS "NON - CONSTANT" **/
    const int* ptr;    // NonConst Ptr to NonConst integer
    ptr = &nonConst_X;
    cout << *ptr << endl;
    cout << nonConst_X << endl;

    //ptr = &y;
    //(*ptr)++;
    //cout << *ptr << endl;

    //ptr = &z;

    //int a[3] = { 1,2,3 };

    //const int* p = a;
    //cout << *p << endl;
    //cout << *(p++) << endl;
    //cout << *(p++) << endl;

    //(*p)++;
    //(*p)++;
    //(*p)++;

    //ptr++;
    //cout << *ptr << endl;
    //(*ptr)++;

    //NonConst Ptr to Const integer
    //ptr = &y;
    //cout<<(*ptr)<<endl;

    /*** 2. POINTER IS CONSTANT **/
    //int* const ptr;
    //int* const ptr1 = &nonConst_X;
    //cout << *ptr1<<endl;
    //(*ptr1)++;
    //cout << *ptr1 << endl;
    //ptr1++; //pointer cannot be changed.

    //int* const ptr2 = &y;

    //const int* const ptr3 = &nonConst_X;
    //cout << *ptr3<<endl;
    //ptr3++;
    //(*ptr3)++;

    //const int* const ptr4 = &y;
    //cout << *ptr4 << endl;
    //ptr4++;
    //(*ptr4)++;

    return 0;
}

// Constant pointer to constant data (ptr1): 10
// Constant pointer to constant data remains: 10
// Constant pointer to non-constant data after increment (ptr2): 150
// Updated value in data1 via ptr2: 300
// Non-constant pointer to constant data (ptr3): 1000
// Non-constant pointer to constant data after pointing to val2: 2000
// Array elements before incrementing (arrPtr): 1 2 3 4 5
// Array elements after incrementing each element by 1: 2 3 4 5 6
// Values array elements via pointer arithmetic (ptr4): 10 20 30 40 50
// Values array elements after incrementing each element by 5: 15 25 35 45 55
// Traversing values array with ptr4 incremented on each loop: 15 25 35 45 55