#include <stdio.h>

int main() {
    char charVar = 'A';
    unsigned char uCharVar = 255;
    short shortVar = -32768;
    unsigned short uShortVar = 65535;
    int intVar = -2147483648;
    unsigned int uIntVar = 4294967295;
    long longVar = -2147483648L;
    unsigned long uLongVar = 4294967295UL;
    long long longLongVar = -9223372036854775808LL;
    unsigned long long uLongLongVar = 18446744073709551615ULL;

    float floatVar = 3.14159F;
    double doubleVar = 3.141592653589793;
    long double longDoubleVar = 3.141592653589793238L;

    void *voidPtr = NULL;

    _Bool boolVar = 1;

    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of unsigned char: %zu bytes\n", sizeof(unsigned char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of unsigned short: %zu bytes\n", sizeof(unsigned short));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of unsigned long: %zu bytes\n", sizeof(unsigned long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of unsigned long long: %zu bytes\n", sizeof(unsigned long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of void pointer: %zu bytes\n", sizeof(void*));
    printf("Size of _Bool: %zu bytes\n", sizeof(_Bool));

    // Size of char: 1 bytes
    // Size of unsigned char: 1 bytes
    // Size of short: 2 bytes
    // Size of unsigned short: 2 bytes
    // Size of int: 4 bytes
    // Size of unsigned int: 4 bytes
    // Size of long: 4 bytes
    // Size of unsigned long: 4 bytes
    // Size of long long: 8 bytes
    // Size of unsigned long long: 8 bytes
    // Size of float: 4 bytes
    // Size of double: 8 bytes
    // Size of long double: 16 bytes
    // Size of void pointer: 8 bytes
    // Size of _Bool: 1 bytes

    return 0;
}
