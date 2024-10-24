#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    
    *ptr = 20;
    printf("\nAfter modification:\n");
    printf("Value of num: %d\n", num);
    
    // Array with pointers
    int arr[] = {22, 221, 53453, 2344, 555};
    int *arrPtr = arr; // Assign the address of the first element to the pointer, this is equicalent to arrPtr = &arr[0]
    
    printf("%d\n", *arrPtr);
    printf("%d\n", *arrPtr + 1);
    printf("%d\n", *(arrPtr + 1));

    printf("\nArray elements using pointer:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(arrPtr + i));
    }
    
    // The expression arrPtr + i performs pointer arithmetic. In C, when you add an integer i to a pointer, it moves the pointer forward by i elements, not by i bytes. This is because the pointer keeps track of the type it points to. In this case:

    // arrPtr + i points to the (i+1)th element of the array, because pointer arithmetic takes the size of the type into account.
    // If arrPtr points to the first element (i.e., arr[0]), then:
    // When i = 0, arrPtr + 0 points to arr[0]
    // When i = 1, arrPtr + 1 points to arr[1]
    // When i = 2, arrPtr + 2 points to arr[2]
    // And so on...


    // Dereferencing: The asterisk * operator is used to dereference the pointer. This means that *(arrPtr + i) retrieves the value at the address that arrPtr + i points to.

    // When you dereference it:
    // *(arrPtr + 0) retrieves the value of arr[0] (which is 1).
    // *(arrPtr + 1) retrieves the value of arr[1] (which is 2).
    // *(arrPtr + 2) retrieves the value of arr[2] (which is 3).
    // And so on...

    return 0;
}

// --------------------------------------------------------

// #include <stdio.h>

// void pointersWithDifferentTypes() {
//     char ch = 'A';
//     char *charPtr = &ch;
//     printf("\nChar pointer:\n");
//     printf("Value of ch: %c\n", ch);
//     printf("Address of ch: %p\n", &ch);
//     printf("Address of ch: %p\n", charPtr);
//     printf("Value pointed by charPtr: %c\n", *charPtr);
    
//     float fl = 3.14f;
//     float *floatPtr = &fl;
//     printf("\nFloat pointer:\n");
//     printf("Value of fl: %.2f\n", fl);
//     printf("Value pointed by floatPtr: %.2f\n", *floatPtr);
    
//     double db = 3.14159;
//     double *doublePtr = &db;
//     printf("\nDouble pointer:\n");
//     printf("Value of db: %.5f\n", db);
//     printf("Value pointed by doublePtr: %.5f\n", *doublePtr);
    
//     char str[] = "Hello";
//     char *strPtr = str;
//     printf("\nString pointer:\n");
//     printf("Original string: %s\n", str);
//     printf("Using pointer: ");
//     while(*strPtr != '\0') {
//         printf("%c", *strPtr);
//         strPtr++;
//     }

//     printf("\n");
// }

// int main() {
//     pointersWithDifferentTypes();
//     return 0;
// }
