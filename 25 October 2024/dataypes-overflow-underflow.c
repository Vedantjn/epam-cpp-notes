#include <stdio.h>

int main() {
    // Unsigned 
    // unsigned char range: 0 to 255 (2^8 - 1)
    // Size: 1 byte (1 bytes = 8 bits)
    unsigned char maxUChar = 255;
    unsigned char overflowChar = maxUChar + 1;
    printf("Overflowed unsigned char: %u\n", overflowChar);
    // Output: Overflowed unsigned char: 0

    unsigned char underflowChar = 0 - 1;
    printf("Underflowed unsigned char: %u\n", underflowChar);
    // Output: Underflowed unsigned char: 255

    // unsigned short range: 0 to 65535 (2^16 - 1)
    // Size: 2 bytes
    unsigned short maxUShort = 65535;
    unsigned short overflowShort = maxUShort + 1;
    printf("Overflowed unsigned short: %u\n", overflowShort);
    // Output: Overflowed unsigned short: 0

    unsigned short underflowShort = 0 - 1;
    printf("Underflowed unsigned short: %u\n", underflowShort);
    // Output: Underflowed unsigned short: 65535

    // unsigned int range: 0 to 4294967295 (2^32 - 1)
    // Size: 4 bytes
    unsigned int maxUInt = 4294967295U;
    unsigned int overflowInt = maxUInt + 1;
    printf("Overflowed unsigned int: %u\n", overflowInt);
    // Output: Overflowed unsigned int: 0

    unsigned int underflowInt = 0 - 1;
    printf("Underflowed unsigned int: %u\n", underflowInt);
    // Output: Underflowed unsigned int: 4294967295

    // unsigned long range: 0 to 4294967295 (2^32 - 1) on 32-bit systems
    // Size: 4 bytes on 32-bit systems, 8 bytes on 64-bit systems
    unsigned long maxULong = 4294967295UL;
    unsigned long overflowLong = maxULong + 1;
    printf("Overflowed unsigned long: %lu\n", overflowLong);
    // Output: Overflowed unsigned long: 0

    unsigned long underflowLong = 0 - 1;
    printf("Underflowed unsigned long: %lu\n", underflowLong);
    // Output: Underflowed unsigned long: 4294967295

    
    // Signed 
    // signed char range: -128 to 127 (-2^7 to 2^7 - 1)
    // Size: 1 byte (8 bits)
    // For signed numbers, 1 bit is used for sign (+ or -), leaving 7 bits for value
    // So range is -(2^7) to (2^7 - 1), not -(2^8) to (2^8 - 1)
    char maxChar = 127;
    char signedOverflowChar = maxChar + 1;
    printf("Overflowed signed char: %d\n", signedOverflowChar);
    // Output: Overflowed signed char: -128

    char minChar = -128;
    char signedUnderflowChar = minChar - 1;
    printf("Underflowed signed char: %d\n", signedUnderflowChar);
    // Output: Underflowed signed char: 127

    // signed short range: -32768 to 32767 (-2^15 to 2^15 - 1)
    // Size: 2 bytes (16 bits)
    // 1 bit for sign, 15 bits for value
    short maxShort = 32767;
    short signedOverflowShort = maxShort + 1;
    printf("Overflowed signed short: %d\n", signedOverflowShort);
    // Output: Overflowed signed short: -32768

    short minShort = -32768;
    short signedUnderflowShort = minShort - 1;
    printf("Underflowed signed short: %d\n", signedUnderflowShort);
    // Output: Underflowed signed short: 32767

    // signed int range: -2147483648 to 2147483647 (-2^31 to 2^31 - 1)
    // Size: 4 bytes (32 bits)
    // 1 bit for sign, 31 bits for value
    int maxInt = 2147483647;
    int signedOverflowInt = maxInt + 1;
    printf("Overflowed signed int: %d\n", signedOverflowInt);
    // Output: Overflowed signed int: -2147483648

    int minInt = -2147483648;
    int signedUnderflowInt = minInt - 1;
    printf("Underflowed signed int: %d\n", signedUnderflowInt);
    // Output: Underflowed signed int: 2147483647

    // signed long range: -2147483648 to 2147483647 (-2^31 to 2^31 - 1) on 32-bit systems
    // Size: 4 bytes (32 bits) on 32-bit systems, 8 bytes (64 bits) on 64-bit systems
    // 1 bit for sign, remaining bits for value
    long maxLong = 2147483647L;
    long signedOverflowLong = maxLong + 1;
    printf("Overflowed signed long: %ld\n", signedOverflowLong);
    // Output: Overflowed signed long: -2147483648

    long minLong = -2147483648L;
    long signedUnderflowLong = minLong - 1;
    printf("Underflowed signed long: %ld\n", signedUnderflowLong);
    // Output: Underflowed signed long: 2147483647

    return 0;
}
