// 1. Array Memory Allocation with new[]:
//    - Runtime allocates memory for array elements
//    - Additional memory reserved for metadata
//    - Memory block includes both data and size information

// 2. Memory Layout:
//    - Metadata section contains array size
//    - Located before actual array memory
//    - Hidden from direct access by programmer

// 3. Storage of Size Information:
//    - Size metadata stored automatically
//    - Implementation-dependent location
//    - Crucial for proper deallocation

// 4. Delete[] Operation:
//    - Accesses stored size information
//    - Determines number of elements to destroy
//    - Calls destructors for each element
//    - Deallocates entire memory block

// 5. Key Benefits:
//    - Automatic tracking of array size
//    - Proper cleanup of all elements
//    - Prevention of memory leaks
//    - Safe array deallocation

// 6. Important Considerations:
//    - Always use delete[] for array allocation
//    - Never use regular delete for arrays
//    - Mismatch leads to undefined behavior
//    - Memory layout is compiler-specific


// 1. Issue with Using delete Instead of delete[]
//    - Incorrect deallocation method for arrays
//    - Can cause memory leaks and undefined behavior

// 2. Problems when using delete p; instead of delete[] p;:
//    - Fails to access array metadata
//    - Cannot determine array size
//    - Treats memory as single object

// 3. Consequences of incorrect deletion:
//    - Memory corruption possible
//    - Not all array elements properly destroyed
//    - Undefined program behavior
//    - Potential application crashes

// 4. Proper Usage:
//    - Always use delete[] for array deallocation
//    - Ensures proper cleanup of all elements
//    - Maintains memory integrity
//    - Prevents resource leaks

  #include <iostream>
  using namespace std;

  int main() {
      // Case 1: Single pointer deletion
      int *ptr1 = new int;
      *ptr1 = 10;
      cout << "Case 1: Single pointer value: " << *ptr1 << endl;
      delete ptr1;    // Correct - single object deletion
      cout << "Case 1: Single pointer value after  before nullptr " << *ptr1 << endl;
      ptr1 = nullptr;
      cout << "Case 1: Single pointer value after deletion " << *ptr1 << endl;

      // Case 2: Array pointer deletion - with delete[]
      int *ptr2a = new int[10];
      for(int i = 0; i < 10; i++) ptr2a[i] = i;
      cout << "Case 2a: Array values (with delete[]): ";
      for(int i = 0; i < 10; i++) cout << ptr2a[i] << " ";
      cout << endl;
      delete[] ptr2a;  // Correct - array deletion
      cout << "Case 2a: Array values after before nullptr: ";
      for(int i = 0; i < 10; i++) cout << ptr2a[i] << " ";
      cout << endl;
      ptr2a = nullptr;
      cout << "Case 2a: Array values after deletion: ";
      for(int i = 0; i < 10; i++) cout << ptr2a[i] << " ";
      cout << endl;

      // Case 2: Array pointer deletion - with delete
      int *ptr2b = new int[10];
      for(int i = 0; i < 10; i++) ptr2b[i] = i;
      cout << "Case 2b: Array values (with delete): ";
      for(int i = 0; i < 10; i++) cout << ptr2b[i] << " ";
      cout << endl;
      delete ptr2b;  // Incorrect - single object deletion for array
      cout << "Case 2b: Array values after before nullptr: ";
      for(int i = 0; i < 10; i++) cout << ptr2b[i] << " ";
      cout << endl;
      ptr2b = nullptr;
      cout << "Case 2b: Array values after deletion: ";
      for(int i = 0; i < 10; i++) cout << ptr2b[i] << " ";
      cout << endl;

      // Case 3: Array pointer deletion
      int *ptr3 = new int[10];
      for(int i = 0; i < 10; i++) ptr3[i] = i * 2;
      cout << "Case 3: Array values: ";
      for(int i = 0; i < 10; i++) cout << ptr3[i] << " ";
      cout << endl;
      delete[] ptr3;    
      cout << "Case 3: Array values after before nullptr: ";
      for(int i = 0; i < 10; i++) cout << ptr3[i] << " ";
      cout << endl;
      ptr3 = nullptr;
      cout << "Case 3: Array values after deletion: ";
      for(int i = 0; i < 10; i++) cout << ptr3[i] << " ";
      cout << endl;

      // Case 5: Multiple array elements
      int *ptr5 = new int[5]{1, 2, 3, 4, 5};
      cout << "Case 5: Array values: ";
      for(int i = 0; i < 5; i++) cout << ptr5[i] << " ";
      cout << endl;
      delete[] ptr5;
      cout << "Case 5: Array values after before nullptr: ";
      for(int i = 0; i < 5; i++) cout << ptr5[i] << " ";
      cout << endl;
      ptr5 = nullptr;
      cout << "Case 5: Array values after deletion: ";
      for(int i = 0; i < 5; i++) cout << ptr5[i] << " ";
      cout << endl;

      // Case 6: Null pointer deletion
      int *ptr6 = nullptr;
      cout << "Case 6: Attempting to delete nullptr" << endl;
      cout << *ptr6 << endl;
      delete ptr6;
      cout << "Case 6: Null pointer value after before nullptr: " << *ptr6 << endl;
      ptr6 = nullptr;
      cout << "Case 6: Null pointer value after deletion: " << *ptr6 << endl;

      return 0;
  }