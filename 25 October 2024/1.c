  #include<stdio.h>

  int main() {
      int arr[3][4] = {
          {10, 20, 30, 40},
          {50, 60, 70, 80},
          {90, 100, 110, 120}
      };
      int (*ptr)[4] = arr;  // pointer to array of 4 integers
    
      printf("2D Array elements using pointer:\n");
    
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 4; j++) {
              printf("%d ", *(*(ptr + i) + j));
          }
          printf("\n");
      }
    
      printf("\nArray addresses using pointer:\n");
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 4; j++) {
              printf("%p ", (void*)(*(ptr + i) + j));
          }
          printf("\n");
      }
    
      printf("\nAlternative way using array notation:\n");
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 4; j++) {
              printf("%d ", ptr[i][j]);
          }
          printf("\n");
      }
    
      return 0;
  }

// Output:

// 2D Array elements using pointer:
// 10 20 30 40 
// 50 60 70 80 
// 90 100 110 120 

// Array addresses using pointer:
// 000000C29B9FFC60 000000C29B9FFC64 000000C29B9FFC68 000000C29B9FFC6C 
// 000000C29B9FFC70 000000C29B9FFC74 000000C29B9FFC78 000000C29B9FFC7C 
// 000000C29B9FFC80 000000C29B9FFC84 000000C29B9FFC88 000000C29B9FFC8C 

// Alternative way using array notation:
// 10 20 30 40 
// 50 60 70 80 
// 90 100 110 120 