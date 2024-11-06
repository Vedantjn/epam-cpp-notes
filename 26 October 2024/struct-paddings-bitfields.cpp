#include <iostream>
using namespace std;

// Struct 1 - With padding, no bitfields
struct RegularPadded {
    char c;     // 1 byte, followed by 3 padding bytes for alignment
    int x;      // 4 bytes
    char y;     // 1 byte, followed by 3 padding bytes for alignment
    double d;   // 8 bytes
    // Total: 24 bytes (padding included)
};
// Assuming 64-bit alignment (8 bytes) for double, the layout with padding looks like this:
// char c: Takes 1 byte. To align the next member (int x) on a 4-byte boundary, the compiler adds 3 bytes of padding after c.
// int x: Takes 4 bytes, now starting at a 4-byte aligned boundary.
// char y: Takes 1 byte. To align the next member (double d) on an 8-byte boundary, the compiler adds 7 bytes of padding after y.
// double d: Takes 8 bytes, starting on an 8-byte aligned boundary.

// Struct 2 - Without padding (packed)
#pragma pack(1)
struct RegularPacked {
    char c;     // 1 byte
    int x;      // 4 bytes
    char y;     // 1 byte
    double d;   // 8 bytes
    // Total: 14 bytes (no padding)
};
#pragma pack()

// Struct 3 - With bitfields (default padding)
struct WithBitfields {
    unsigned int a : 3;    // 3 bits
    unsigned int b : 5;    // 5 bits
    unsigned int c : 4;    // 4 bits
    int x;                 // 4 bytes
    unsigned int d : 2;    // 2 bits
    // Total: 12 bytes (bitfields packed within a 4-byte int)
};
// 4 bytes for bitfields (fits a, b, c, and d within a single 4-byte unsigned int block).
// 4 bytes for int x.
// 4 bytes padding (if required by the compiler to align the structure to a multiple of its
//  largest member’s alignment, which is 4 bytes).

// Struct 4 - With bitfields and packed (1-byte alignment)
#pragma pack(1)
struct WithBitfieldsPacked {
    unsigned int a : 3;    // 3 bits
    unsigned int b : 5;    // 5 bits
    unsigned int c : 4;    // 4 bits
    int x;                 // 4 bytes
    unsigned int d : 2;    // 2 bits
    // Total: 12 bytes (packing has no effect due to bitfields)
};
#pragma pack()
// Bitfields a, b, c, and d:

// Bitfields in C++ are stored within the smallest multiple of their base type, which is unsigned int (4 bytes or 32 bits) here.
// The total number of bits in the bitfields is 3 + 5 + 4 + 2 = 14 bits, which the compiler packs into a 4-byte unsigned int.
// int x:

// The int x member takes 4 bytes (32 bits), and with #pragma pack(1), it will directly follow the packed bitfields without extra padding.
// Size Calculation:

// 4 bytes for the unsigned int that holds the bitfields (a, b, c, and d).
// 4 bytes for int x.
// Thus, even with #pragma pack(1), the structure size is 8 bytes if the compiler
//  fully optimizes for #pragma pack(1). However, due to some compilers' internal alignment
// rules for specific architectures, the structure may still round to 12 bytes to optimize 
// access or meet alignment constraints for more efficient memory access.

int main() {
    cout << "Size of RegularPadded: " << sizeof(RegularPadded) << " bytes\n";
    cout << "Size of RegularPacked: " << sizeof(RegularPacked) << " bytes\n";
    cout << "Size of WithBitfields: " << sizeof(WithBitfields) << " bytes\n";
    cout << "Size of WithBitfieldsPacked: " << sizeof(WithBitfieldsPacked) << " bytes\n";
    
    return 0;
}

// Size of RegularPadded: 24 bytes
// Size of RegularPacked: 14 bytes
// Size of WithBitfields: 12 bytes
// Size of WithBitfieldsPacked: 12 bytes



