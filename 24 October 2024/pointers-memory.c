  #include <stdio.h>

  int main() {
      int arr[3][3] = {
          {1, 2, 3},
          {4, 5, 6},
          {7, 8, 9}
      };

      printf("Addresses of elements in 2D array:\n");
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
              printf("Address of arr[%d][%d]: %p\n", i, j, &arr[i][j]);
          }
      }

      return 0;
  }

  // Output:
  // Addresses of elements in 2D array:
  // Address of arr[0][0]: 0x7fff5fbff6d0
  // Address of arr[0][1]: 0x7fff5fbff6d4
  // Address of arr[0][2]: 0x7fff5fbff6d8
  // Address of arr[1][0]: 0x7fff5fbff6dc
  // Address of arr[1][1]: 0x7fff5fbff6e0
  // Address of arr[1][2]: 0x7fff5fbff6e4
  // Address of arr[2][0]: 0x7fff5fbff6e8
  // Address of arr[2][1]: 0x7fff5fbff6ec
  // Address of arr[2][2]: 0x7fff5fbff6f0

  // ------------------------------------------------------------------


  #include <stdio.h>

  int main() {
      int arr[3][3][3] = {
          {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
          {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
      };

      printf("Addresses of elements in 3D array:\n");
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
              for(int k = 0; k < 3; k++) {
                  printf("Address of arr[%d][%d][%d]: %p\n", i, j, k, &arr[i][j][k]);
              }
          }
      }

      return 0;
  }

// Output:
// Address of arr[0][0][0]: 0000007FAD9FF990
// Address of arr[0][0][1]: 0000007FAD9FF994  // +4 bytes from previous (int size)
// Address of arr[0][0][2]: 0000007FAD9FF998  // +4 bytes, next element in innermost array
// Address of arr[0][1][0]: 0000007FAD9FF99C  // +4 bytes, first element of next middle array
// Address of arr[0][1][1]: 0000007FAD9FF9A0  // +4 bytes, continuing sequential allocation
// Address of arr[0][1][2]: 0000007FAD9FF9A4
// Address of arr[0][2][0]: 0000007FAD9FF9A8
// Address of arr[0][2][1]: 0000007FAD9FF9AC
// Address of arr[0][2][2]: 0000007FAD9FF9B0
// Address of arr[1][0][0]: 0000007FAD9FF9B4
// Address of arr[1][0][1]: 0000007FAD9FF9B8
// Address of arr[1][0][2]: 0000007FAD9FF9BC
// Address of arr[1][1][0]: 0000007FAD9FF9C0
// Address of arr[1][1][1]: 0000007FAD9FF9C4
// Address of arr[1][1][2]: 0000007FAD9FF9C8
// Address of arr[1][2][0]: 0000007FAD9FF9CC
// Address of arr[1][2][1]: 0000007FAD9FF9D0
// Address of arr[1][2][2]: 0000007FAD9FF9D4
// Address of arr[2][0][0]: 0000007FAD9FF9D8
// Address of arr[2][0][1]: 0000007FAD9FF9DC
// Address of arr[2][0][2]: 0000007FAD9FF9E0
// Address of arr[2][1][0]: 0000007FAD9FF9E4
// Address of arr[2][1][1]: 0000007FAD9FF9E8
// Address of arr[2][1][2]: 0000007FAD9FF9EC
// Address of arr[2][2][0]: 0000007FAD9FF9F0
// Address of arr[2][2][1]: 0000007FAD9FF9F4
// Address of arr[2][2][2]: 0000007FAD9FF9F8