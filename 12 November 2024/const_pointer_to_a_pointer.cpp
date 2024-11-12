#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    int *ptr1 = &a;    // Pointer to int
    int **const ptr2 = &ptr1;  // Constant pointer to pointer to int

    cout << "Initial value of **ptr2: " << **ptr2 << endl;  // Output: 10

    // Case 1: Modifying value through double pointer
    **ptr2 = 40;
    cout << "Value of a after modification: " << a << endl;  // Output: 40

    // Case 2: Changing where ptr1 points to
    ptr1 = &b;
    cout << "Value of **ptr2 after ptr1 points to b: " << **ptr2 << endl;  // Output: 20

    // Case 3: Modifying value through ptr1
    *ptr1 = 50;
    cout << "Value of b after modification through ptr1: " << b << endl;  // Output: 50
    cout << "Value of **ptr2 after modifying b: " << **ptr2 << endl;  // Output: 50

    // Case 4: Demonstrating ptr2 constness
    int *ptr3 = &c;
    // ptr2 = &ptr3;  // Error: ptr2 is a constant pointer

    // Case 5: Showing original variable modification reflects in all pointers
    b = 60;
    cout << "Value of **ptr2 after modifying b directly: " << **ptr2 << endl;  // Output: 60

    return 0;
}

// Initial value of **ptr2: 10
// Value of a after modification: 40
// Value of **ptr2 after ptr1 points to b: 20
// Value of b after modification through ptr1: 50
// Value of **ptr2 after modifying b: 50
// Value of **ptr2 after modifying b directly: 60