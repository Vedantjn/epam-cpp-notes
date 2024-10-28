#include <stdio.h>
#pragma pack(1)  // Disable padding

// Structure without padding
struct Student1 {
    char name;    // 1 byte
    int roll;     // 4 bytes
    char grade;   // 1 byte
};

// Structure with default padding
#pragma pack()
struct Student2 {
    char name;    // 1 byte + 3 bytes padding
    int roll;     // 4 bytes
    char grade;   // 1 byte + 3 bytes padding
};

int main() {
    struct Student1 s1;
    struct Student2 s2;
    
    printf("Size of structure without padding: %d\n", sizeof(s1));  // 6
    printf("Size of structure with padding: %d\n", sizeof(s2));     // 12
    
    printf("\nMemory layout explanation:\n");
    printf("Without padding (Student1):\n");
    printf("name  (1 byte):  Byte 0\n");
    printf("roll  (4 bytes): Bytes 1-4\n");
    printf("grade (1 byte):  Byte 5\n");
    
    printf("\nWith padding (Student2):\n");
    printf("name  (1 byte):  Byte 0  [3 bytes padding]\n");
    printf("roll  (4 bytes): Bytes 4-7\n");
    printf("grade (1 byte):  Byte 8  [3 bytes padding]\n");
    
    return 0;
}

// Output:

// Size of structure without padding: 6
// Size of structure with padding: 12

// Memory layout explanation:
// Without padding (Student1):
// name  (1 byte):  Byte 0
// roll  (4 bytes): Bytes 1-4
// grade (1 byte):  Byte 5

// With padding (Student2):
// name  (1 byte):  Byte 0  [3 bytes padding]       
// roll  (4 bytes): Bytes 4-7
// grade (1 byte):  Byte 8  [3 bytes padding]   

// ------------------------------------------------------------

#include <stdio.h>

// Save current alignment setting
#pragma pack(push, 1)  // Push current alignment and set to 1 byte alignment

// Structure without padding
struct Student1 {
    char name;    // 1 byte
    int roll;     // 4 bytes
    char grade;   // 1 byte
};

#pragma pack(pop)  // Restore original alignment

// Structure with default padding
struct Student2 {
    char name;    // 1 byte + 3 bytes padding
    int roll;     // 4 bytes
    char grade;   // 1 byte + 3 bytes padding
};

int main() {
    struct Student1 s1;
    struct Student2 s2;
    
    printf("Size of structure without padding: %d\n", sizeof(s1));  // 6
    printf("Size of structure with padding: %d\n", sizeof(s2));     // 12
    
    printf("\nMemory layout explanation:\n");
    printf("Without padding (Student1):\n");
    printf("name  (1 byte):  Byte 0\n");
    printf("roll  (4 bytes): Bytes 1-4\n");
    printf("grade (1 byte):  Byte 5\n");
    
    printf("\nWith padding (Student2):\n");
    printf("name  (1 byte):  Byte 0  [3 bytes padding]\n");
    printf("roll  (4 bytes): Bytes 4-7\n");
    printf("grade (1 byte):  Byte 8  [3 bytes padding]\n");
    
    return 0;
}

// Output:

// Size of structure without padding: 6
// Size of structure with padding: 12

// Memory layout explanation:
// Without padding (Student1):
// name  (1 byte):  Byte 0
// roll  (4 bytes): Bytes 1-4
// grade (1 byte):  Byte 5

// With padding (Student2):
// name  (1 byte):  Byte 0  [3 bytes padding]       
// roll  (4 bytes): Bytes 4-7
// grade (1 byte):  Byte 8  [3 bytes padding]   

// ---------------------------------------------------

#include <iostream>
using namespace std;

struct Example {
    char a;       // 1 byte
    int b;        // 4 bytes (typically aligned to 4 bytes)
    char c;       // 1 byte
    double d;     // 8 bytes (typically aligned to 8 bytes)
};

int main() {
    Example ex;
    cout << "Size of struct Example: " << sizeof(ex) << " bytes" << endl;
    return 0;
}

// Explanation
// In the Example struct:

// char a occupies 1 byte, but since the next member (int b) requires alignment to 4 bytes, there may be 3 bytes of padding after a.
// int b requires 4 bytes.
// char c occupies 1 byte, and padding may be added after it to align double d to 8 bytes.
// double d requires 8 bytes.
// The size of Example can end up larger than the sum of its members due to padding.

// Output
// The output might show:

// Size of struct Example: 24 bytes
// This value may vary by compiler and platform, but it reflects the added padding bytes to maintain alignment.