// Bit fields allow packing multiple fields into a single byte/word
// This reduces memory usage by specifying exact bits needed

#include <stdio.h>

// Define a bit field structure
struct PackedData {
    unsigned int flag1 : 1;    // 1 bit - can store 0 or 1
    unsigned int flag2 : 1;    // 1 bit - can store 0 or 1
    unsigned int count : 4;    // 4 bits - can store values from 0 to 15 (2^4 - 1)
    unsigned int status : 2;   // 2 bits - can store values from 0 to 3 (2^2 - 1)
    // Total bits used = 8 bits (1 byte)
    // Without bit fields, each member would take 4 bytes (32 bits)
} data;

int main() {
    // Initialize the bit fields
    data.flag1 = 1;      // Set first flag (uses only 1 bit)
    data.flag2 = 0;      // Clear second flag (uses only 1 bit)
    data.count = 12;     // Set count to 12 (uses 4 bits: 1100 in binary)
    data.status = 2;     // Set status to 2 (uses 2 bits: 10 in binary)

    printf("Flag1: %d\n", data.flag1);
    printf("Flag2: %d\n", data.flag2);
    printf("Count: %d\n", data.count);
    printf("Status: %d\n", data.status);

    // Size is usually 4 bytes due to memory alignment, though only 8 bits are used
    printf("Size of PackedData: %zu bytes\n", sizeof(struct PackedData));

    return 0;
}

// Output:

// Flag1: 1
// Flag2: 0
// Count: 12
// Status: 2
// Size of PackedData: 4 bytes