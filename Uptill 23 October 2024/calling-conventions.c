Calling Convention    Parameter Passing            Stack Cleanup    Variadic Function Support    Use Case
cdecl               Right to Left (Stack)             Caller           Yes                       Default for C/C++
stdcall             Right to Left (Stack)             Callee           No                        Windows API
pascal              Left to Right (Stack)             Callee           No                        Pascal Language, Borland
fastcall            Registers & Stack                 Callee           No                        Performance Optimization
thiscall            this in ECX, others on stack      Callee           No                        C++ Member Functions
vectorcall          Registers (Vector)                Callee           No                        Vector/Math Processing

}

Calling Conventions:

1. cdecl (C Declaration)
- Right to left parameter passing on stack
- Caller cleans stack
- Default for C/C++
- Supports variadic functions

#include <stdio.h>

int __cdecl add(int a, int b) {  // Using __cdecl explicitly
    return a + b;
}

int main() {
    int result = add(5, 3);
    printf("Result = %d\n", result);
    return 0;
}


2. stdcall (Standard Call)
- Right to left parameter passing on stack
- Callee cleans stack
- Used in Windows API
- No variadic function support

#include <stdio.h>

int __stdcall add(int a, int b) {  // Using __stdcall explicitly
    return a + b;
}

int main() {
    int result = add(5, 3);
    printf("Result = %d\n", result);
    return 0;
}


3. pascal
- Left to right parameter passing
- Callee cleans stack
- Used in Pascal/Borland
- No variadic function support

#include <stdio.h>

int __pascal add(int a, int b) {  // Using __pascal explicitly
    return a + b;
}

int main() {
    int result = add(5, 3);
    printf("Result = %d\n", result);
    return 0;
}


4. fastcall
- Uses registers first, then stack
- Callee cleans stack
- For performance optimization
- Limited parameter capacity

#include <stdio.h>

int __fastcall add(int a, int b) {  // Using __fastcall explicitly
    return a + b;
}

int main() {
    int result = add(5, 3);
    printf("Result = %d\n", result);
    return 0;
}


5. thiscall
- 'this' pointer in ECX register
- Other parameters on stack
- Used for C++ member functions
- Callee cleans stack

#include <iostream>

class MyClass {
public:
    int add(int a, int b) {  // Using thiscall implicitly
        return a + b;
    }
};

int main() {
    MyClass obj;
    int result = obj.add(5, 3);
    std::cout << "Result = " << result << std::endl;
    return 0;
}


6. vectorcall
- Optimized for vector/floating-point
- Uses registers for parameters
- Microsoft-specific
- For performance-critical operations


Variadic Functions
- Takes variable number of arguments
- Uses ellipsis (...) syntax
- Common in printf, scanf
- Requires stdarg.h for va_list

#include <stdio.h>
#include <stdarg.h>

// Sum variable number of integers
int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for(int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

// Print variable number of strings
void print_strings(int count, ...) {
    va_list args;
    va_start(args, count);
    
    for(int i = 0; i < count; i++) {
        char* str = va_arg(args, char*);
        printf("%s\n", str);
    }
    
    va_end(args);
}

int main() {
    // Using sum function
    int result1 = sum(4, 10, 20, 30, 40);
    printf("Sum = %d\n", result1);
    
    // Using print_strings function
    print_strings(3, "Hello", "World", "Variadic!");
    
    return 0;
}
