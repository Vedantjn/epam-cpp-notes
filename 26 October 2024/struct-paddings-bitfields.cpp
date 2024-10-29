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
    // Total: 8 bytes (bitfields packed within a 4-byte int)
};

// Struct 4 - With bitfields and packed (1-byte alignment)
#pragma pack(1)
struct WithBitfieldsPacked {
    unsigned int a : 3;    // 3 bits
    unsigned int b : 5;    // 5 bits
    unsigned int c : 4;    // 4 bits
    int x;                 // 4 bytes
    unsigned int d : 2;    // 2 bits
    // Total: 8 bytes (packing has no effect due to bitfields)
};
#pragma pack()

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