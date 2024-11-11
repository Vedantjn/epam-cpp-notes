// const int* ptr1 - A pointer to a const int. ptr1 can point to different locations, but the integer it points to cannot be modified through this pointer.
// int* const ptr2 - A constant pointer to an integer. ptr2 cannot point to a different location, but the integer value it points to can be modified.
// const int* const ptr3 - A constant pointer to a const int. Neither the pointer nor the integer value can be modified.

#include <iostream>
using namespace std;

int main() {
    // Regular pointer to const integer
    const int val1 = 10;
    const int* ptr1 = &val1;  // Cannot modify the value through pointer

    // Const pointer to non-const integer
    int val2 = 20;
    int* const ptr2 = &val2;  // Cannot modify the pointer
    *ptr2 = 30;               // Can modify the value

    // Const pointer to const integer
    const int val3 = 30;
    const int* const ptr3 = &val3;  // Cannot modify both pointer and value

    // Multiple pointers with different const combinations
    int val4 = 40;
    const int* ptr4 = &val4; // pointer to a const integer
    int* const ptr5 = &val4; // const pointer integer
    const int* const ptr6 = &val4; // const pointer to a const integer

    cout << "Initial values:" << endl;
    cout << "val1: " << val1 << ", *ptr1: " << *ptr1 << endl;
    cout << "val2: " << val2 << ", *ptr2: " << *ptr2 << endl;
    cout << "val3: " << val3 << ", *ptr3: " << *ptr3 << endl;
    cout << "val4: " << val4 << ", *ptr4: " << *ptr4 << ", *ptr5: " << *ptr5 << ", *ptr6: " << *ptr6 << endl;

    // Allowed modifications
    val2 = 50;      // Can modify original value
    *ptr2 = 60;     // Can modify through const pointer to non-const int
    val4 = 70;      // Can modify original value
    *ptr5 = 80;     // Can modify through const pointer to non-const int

    cout << "\nAfter modifications:" << endl;
    cout << "val2: " << val2 << ", *ptr2: " << *ptr2 << endl;
    cout << "val4: " << val4 << ", *ptr4: " << *ptr4 << ", *ptr5: " << *ptr5 << ", *ptr6: " << *ptr6 << endl;

    return 0;
}


// Initial values:
// val1: 10, *ptr1: 10
// val2: 30, *ptr2: 30
// val3: 30, *ptr3: 30
// val4: 40, *ptr4: 40, *ptr5: 40, *ptr6: 40

// After modifications:
// val2: 60, *ptr2: 60
// val4: 80, *ptr4: 80, *ptr5: 80, *ptr6: 80