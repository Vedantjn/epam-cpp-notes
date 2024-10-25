#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Memory management functions
void free(void *address);              // Deallocates memory previously allocated
void *malloc(size_t size);             // Allocates requested bytes of memory
void *realloc(void *address, size_t newsize);  // Resizes previously allocated memory
void *calloc(size_t num, size_t size);       // Allocates and zeros memory for array

int main() {
    // Allocate memory for 5 integers
    int *arr = (int*)malloc(5 * sizeof(int));
    
    if (arr == NULL) {
        return 1;
    }
    
    // Initialize array
    for(int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("\nSize of pointer: %zu\n", sizeof(arr));
    // Output: Size of pointer: 8 (on 64-bit systems) or 4 (on 32-bit systems)
    
    // Resize array to hold 10 integers
    int *temp = (int*)realloc(arr, 10 * sizeof(int));
    if (temp == NULL) {
        free(arr);
        return 1;
    }
    arr = temp;
    
    printf("\nSize of pointer: %zu\n", sizeof(arr));
    // Output: Size of pointer: 8 (on 64-bit systems) or 4 (on 32-bit systems)
    
    // Allocate and zero-initialize memory for 3 doubles
    double *numbers = (double*)calloc(3, sizeof(double));
    if (numbers == NULL) {
        free(arr);
        return 1;
    }
    
    // Free allocated memory
    free(arr);
    free(numbers);
    
    return 0;
}

// sizeof on Pointers: Returns pointer size (8 bytes on 64-bit, 4 bytes on 32-bit systems), not the size of allocated memory.

// Allocated Memory: malloc, calloc, and realloc manage heap memory size without changing pointer size.