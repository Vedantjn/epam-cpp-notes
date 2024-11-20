// • Memory fragmentation refers to the inefficient use of memory caused by the allocation and deallocation of memory blocks of varying sizes.
// • It occurs when free memory is divided into small, non-contiguous blocks.
// • This makes it challenging to allocate large contiguous memory chunks, even though sufficient total memory is available.

#include <iostream>

int main() {
    // Allocate and deallocate memory
    int* a = new int[10];    // Allocate 10 integers
    int* b = new int[20];    // Allocate 20 integers
    delete[] a;              // Deallocate first block
    int* c = new int[5];     // Allocate a smaller block

    // Fragmentation: Memory left by `a` may not be usable for larger allocations like `d`
    int* d = new int[15];    // May fail if free memory is not contiguous

    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}
