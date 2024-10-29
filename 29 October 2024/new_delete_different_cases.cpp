// Case 1: Single allocation with new
int *ptr1 = new int;        // Single allocation - CORRECT
*ptr1 = 5;                  // Memory access is correct
delete ptr1;               // Single deallocation - CORRECT

// Case 2: Array allocation with new[]
int *ptr2 = new int[5];    // Array allocation - CORRECT
ptr2[0] = 5;               // Array access is correct
delete[] ptr2;            // Array deallocation - CORRECT

// Case 3: Wrong deallocation example
int *ptr3;
ptr3 = new int[5];
ptr3[0] = 5;
delete ptr3;    // Wrong: Using single delete for array allocation
// Undefined behavior. Use delete[] ptr3 to correctly deallocate the array.
// This leads to undefined behavior. Since delete does not know it’s dealing with
//  an array, it won’t correctly free the entire allocated memory. It may appear
//   to work in simple cases but can cause memory leaks, crashes, or other issues
//    depending on the compiler and environment.

// Case 4: Multiple elements array
int *ptr4 = new int[10];   // Array allocation - CORRECT
for(int i = 0; i < 10; i++) {
    ptr4[i] = i;           // Array access is correct
}
delete[] ptr4;            // Array deallocation - CORRECT

// Case 5: 2D array allocation
int **ptr5 = new int*[3];  // Array of pointers - CORRECT
for(int i = 0; i < 3; i++) {
    ptr5[i] = new int[4];  // Array allocation for each row - CORRECT
}
// Deallocation of 2D array
for(int i = 0; i < 3; i++) {
    delete[] ptr5[i];     // Delete each row - CORRECT
}
delete[] ptr5;            // Delete array of pointers - CORRECT

// Case 6: Single pointer to multiple elements
int *ptr6 = new int;      // Single allocation - CORRECT
*ptr6 = 100;              // Memory access is correct
delete ptr6;             // Single deallocation - CORRECT

// Case 7: Dynamic array of chars
char *ptr7 = new char[20];  // Array allocation - CORRECT
delete[] ptr7;             // Array deallocation - CORRECT

// The key rules followed are:
// 1. new paired with delete
// 2. new[] paired with delete[]
// 3. Proper memory access (*ptr for single, ptr[i] for arrays)
// 4. Proper cleanup of multi-dimensional arrays