#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    // Value of num: 10
    // Address of num: 00000077FDBFFC74
    // Address of num: 00000077FDBFFC74
    // Value of ptr: 00000077FDBFFC74
    // Value pointed by ptr: 10
    
    *ptr = 20;
    printf("\nAfter modification:\n");
    printf("Value of num: %d\n", num);
    
    // After modification:
    // Value of num: 20    

    // Array with pointers
    int arr[] = {22, 221, 53453, 2344, 555};
    int *arrPtr = arr; // Assign the address of the first element to the pointer, this is equicalent to arrPtr = &arr[0]
    
    printf("%d\n", *arrPtr); // 22
    printf("%d\n", *arrPtr + 1); // 23
    printf("%d\n", *(arrPtr + 1)); // 221

    printf("\nArray elements using pointer:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(arrPtr + i));
    }

    // Array elements using pointer:
    // 22 221 53453 2344 555
    
    // The expression arrPtr + i performs pointer arithmetic. In C, when you add an integer i to a pointer, it moves the pointer forward by i elements, not by i bytes. This is because the pointer keeps track of the type it points to. In this case:
    // arrPtr + i points to the (i+1)th element of the array, because pointer arithmetic takes the size of the type into account.
    // If arrPtr points to the first element (i.e., arr[0]), then:
    // When i = 0, arrPtr + 0 points to arr[0] (22)
    // When i = 1, arrPtr + 1 points to arr[1] (221)
    // When i = 2, arrPtr + 2 points to arr[2] (53453)
    // And so on...


    // Dereferencing: The asterisk * operator is used to dereference the pointer. This means that *(arrPtr + i) retrieves the value at the address that arrPtr + i points to.

    // When you dereference it:
    // *(arrPtr + 0) retrieves the value of arr[0] (which is 22)
    // *(arrPtr + 1) retrieves the value of arr[1] (which is 221)
    // *(arrPtr + 2) retrieves the value of arr[2] (which is 53453)
    // And so on...
    return 0;
}

// --------------------------------------------------------

#include <stdio.h>

void pointersWithDifferentTypes() {
    char ch = 'A';
    char *charPtr = &ch;
    printf("\nChar pointer:\n");
    printf("Value of ch: %c\n", ch);
    printf("Address of ch: %p\n", &ch);
    printf("Address of ch: %p\n", charPtr);
    printf("Value pointed by charPtr: %c\n", *charPtr);

    // Char pointer:
    // Value of ch: A
    // Address of ch: 000000491DBFF8FF
    // Address of ch: 000000491DBFF8FF
    // Value pointed by charPtr: A
    
    float fl = 3.14f;
    float *floatPtr = &fl;
    printf("\nFloat pointer:\n");
    printf("Value of fl: %.2f\n", fl);
    printf("Value pointed by floatPtr: %.2f\n", *floatPtr);

    // Float pointer:
    // Value of fl: 3.14
    // Value pointed by floatPtr: 3.14
    
    double db = 3.14159;
    double *doublePtr = &db;
    printf("\nDouble pointer:\n");
    printf("Value of db: %.5f\n", db);
    printf("Value pointed by doublePtr: %.5f\n", *doublePtr);

    // Double pointer:
    // Value of db: 3.14159
    // Value pointed by doublePtr: 3.14159
    
    char str[] = "Hello";
    char *strPtr = str;
    printf("\nString pointer:\n");
    printf("Original string: %s\n", str);
    printf("Using pointer: ");
    while(*strPtr != '\0') {
        printf("%c", *strPtr);
        strPtr++;
    }

    // String pointer:
    // Original string: Hello
    // Using pointer: Hello

    printf("\n");
}

int main() {
    pointersWithDifferentTypes();
    return 0;
}
