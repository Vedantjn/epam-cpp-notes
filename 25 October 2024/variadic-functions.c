#include <stdio.h>
#include <stdarg.h>

// Function to find sum of numbers
int sum(int count, ...) {
    int result = 0;
    
    // Declaring pointer to the argument list
    va_list args;
    
    // Initializing argument to the list pointer
    va_start(args, count);
    
    // Accessing all arguments
    for (int i = 0; i < count; i++) {
        result += va_arg(args, int);
    }
    
    // Ending argument list traversal
    va_end(args);
    
    return result;
}

// Function to find average of numbers
float average(int count, ...) {
    int total = 0;
    
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    
    return (float)total/count;
}

// Function to print numbers with custom format
void print_numbers(char *format, int count, ...) {
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        printf(format, va_arg(args, int));
    }
    
    va_end(args);
    printf("\n");
}

int main() {
    printf("Sum of 2, 3, 4: %d\n", sum(3, 2, 3, 4));
    // Sum of 2, 3, 4: 9
    printf("Sum of 5, 10, 15, 20: %d\n", sum(4, 5, 10, 15, 20));
    // Sum of 2, 3, 4: 9
    
    printf("Average of 2, 3, 4: %.2f\n", average(3, 2, 3, 4));
    // Average of 2, 3, 4: 3.00

    printf("Average of 5, 10, 15, 20: %.2f\n", average(4, 5, 10, 15, 20));
    // Average of 5, 10, 15, 20: 12.50     
    
    printf("Printing numbers with different formats:\n");
    print_numbers("%d ", 4, 10, 20, 30, 40);
    // 10 20 30 40
    print_numbers("%03d ", 3, 5, 10, 15);
    // 005 010 015
    
    return 0;
}
