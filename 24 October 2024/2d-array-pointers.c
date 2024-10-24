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
    printf("%d", *p);
    // int (*p);
    // p = arr;
    // printf("%d", *p);

    
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

// -------------------------------------------------------------------

  #include <stdio.h>

  int main() {
      int arr[3][4] = {{2, 4, 5, 7}, {12, 3, 23, 55}, {6, 3, 2, 1}};

      // This won't work - cannot assign 2D array to int pointer
      // int *ptr = arr;  
    
      // This is also incorrect - &arr gives address of whole 2D array
      // int *ptr2 = &arr;
    
      // Correct ways to point to 2D array:
      int (*ptr)[4] = arr;     // Pointer to an array of 4 integers - points to entire row
      int *ptr2 = arr[0];      // Points to first row, decays to pointer to first element
      int *ptr3 = &arr[0][0];  // Pointer to first element - direct way to get first element address

      // Print using different pointer methods
      printf("Using ptr (array pointer):\n");
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 4; j++) {
              printf("%d ", ptr[i][j]);
          }
          printf("\n");
      }

      printf("\nUsing ptr2 (first row pointer):\n");
      for(int i = 0; i < 4; i++) {
          printf("%d ", ptr2[i]);
      }
      printf("\n");

      printf("\nUsing ptr3 (first element pointer):\n");
      for(int i = 0; i < 12; i++) {
          printf("%d ", ptr3[i]);
      }
      printf("\n");

      return 0;
  }

// -------------------------------------------------------------------
#include <stdio.h>

int main() {
    int arr[2][2] = {{1, 2}, {3, 4}};
    int *ptr = &arr[0][0];

    // Method 1 to print all elements: 
    printf("%d\n", *ptr);
    ptr++;
    printf("%d\n", *ptr);
    ptr++;
    printf("%d\n", *ptr);
    ptr++;
    printf("%d\n", *ptr);
    ptr++;

    // Method 2 to print all elements
    printf("%d\n", *(ptr + 0));      // First element (0,0)
    printf("%d\n", *(ptr + 1));      // Second element (0,1)
    printf("%d\n", *(ptr + 2));      // Third element (1,0)
    printf("%d\n", *(ptr + 3));      // Fourth element (1,1)

    // Method 3 to print all elements
    // For arr[i][j], the access can be simplified to *(ptr + (i * number_of_columns + j)).
    printf("%d\n", *(ptr + 0 * 2 + 0));    // First element (0,0)
    printf("%d\n", *(ptr + 0 * 2 + 1));    // Second element (0,1)
    printf("%d\n", *(ptr + 1 * 2 + 0));    // Third element (1,0)
    printf("%d\n", *(ptr + 1 * 2 + 1));    // Fourth element (1,1)

    // Method 4
    int *p;
    for(p = &arr[0][0]; p <= &arr[1][1]; p++) {
        printf("%d\n", *p);
    }
}

// ----------------------------------------------------------------------
  #include <stdio.h>

  int main() {
      int arr[3][3] = {{112, 33, 233}, {122, 535, 22}, {66, 3445, 3}};

      int *ptr;
      ptr = &arr[0][0];

      // Prints address of first element using pointer
      printf("%x\n", ptr);
      // Prints base address of array (same as first element)
      printf("%x\n", arr);
      // Prints address of entire array
      printf("%x\n", &arr);
      // Prints address of first row (same as base address)
      printf("%x\n", arr[0]);
      // Prints address of first row (same as base address)
      printf("%x\n", *arr);
      // Prints address of first element
      printf("%x\n", &arr[0][0]);
    

  }