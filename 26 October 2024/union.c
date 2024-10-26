// The size of a union is determined by the size of its largest member.
// In this case:
// - int i: 4 bytes
// - float f: 4 bytes
// - char str[20]: 20 bytes
// Therefore, the union size is 20 bytes (the largest member)

#include <stdio.h>
#include <string.h>

union Data {
    int i;           // 4 bytes
    float f;         // 4 bytes
    char str[20];    // 20 bytes
};

int main() {
    union Data data;

    //  1: Using integer
    data.i = 10;
    printf(" 1:\n");
    printf("data.i: %d\n", data.i);
    printf("data.f: %f\n", data.f);         // Will show garbage value
    printf("data.str: %s\n\n", data.str);   // Will show garbage value

    //  2: Using float
    data.f = 220.5;
    printf(" 2:\n");
    printf("data.i: %d\n", data.i);         // Will show garbage value
    printf("data.f: %f\n", data.f);
    printf("data.str: %s\n\n", data.str);   // Will show garbage value

    //  3: Using string
    strcpy(data.str, "C Programming");
    printf(" 3:\n");
    printf("data.i: %d\n", data.i);         // Will show garbage value
    printf("data.f: %f\n", data.f);         // Will show garbage value
    printf("data.str: %s\n\n", data.str);

    //  4: Using negative integer
    data.i = -42;
    printf(" 4:\n");
    printf("data.i: %d\n", data.i);
    printf("data.f: %f\n", data.f);         // Will show garbage value
    printf("data.str: %s\n\n", data.str);   // Will show garbage value

    //  5: Using larger float
    data.f = 3.14159265;
    printf(" 5:\n");
    printf("data.i: %d\n", data.i);         // Will show garbage value
    printf("data.f: %f\n", data.f);
    printf("data.str: %s\n\n", data.str);   // Will show garbage value

    printf("Size of union: %lu bytes\n", sizeof(data));

    return 0;
}

// Output:

//  1:
// data.i: 10
// data.f: 0.000000
// data.str: 


//  2:
// data.i: 1130135552
// data.f: 220.500000
// data.str:

//  3:
// data.i: 1917853763
// data.f: 4122360580327794860452759994368.000000
// data.str: C Programming

//  4:
// data.i: -42
// data.f: -nan
// data.str: ╓   ogramming

//  5:
// data.i: 1078530011
// data.f: 3.141593
// data.str: █I@ogramming

// Size of union: 20 bytes