// Function pointers are pointers that store the address of a function. 
// They allow functions to be invoked indirectly and are useful for scenarios 
// like callbacks, dynamic dispatching, and implementing algorithms that need 
// configurable behavior.

// return_type (*pointer_name)(parameter_list);

// Assign a function to the pointer and invoke it using (*pointer_name)(arguments) or pointer_name(arguments).

#include<iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

void compute(int x, int y, int (*operation)(int, int)) {
    cout << "Result : " << operation(x, y) << endl;
} 

int main(){
    int (*funcPointer)(int, int);

    funcPointer = add;
    cout << "Addition : " << funcPointer(5, 4) << endl;

    funcPointer = multiply;
    cout << "Multiplication : " << funcPointer(5, 4) << endl;

    compute(4, 7, add);
    compute(4, 7, multiply);

    return 0;
}

// Addition : 9
// Multiplication : 20
// Result : 11
// Result : 28