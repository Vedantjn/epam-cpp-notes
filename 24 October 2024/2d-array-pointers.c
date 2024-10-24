#include <stdio.h>

int main() {
    int rows = 3;
    int cols = 4;
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Pointer to array of 4 integers
    int (*p)[4];
    p = arr;

    
    // Alternative way using array notation
    printf("\nDirect way:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    // Print array using pointer arithmetic
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }

    return 0;
}
