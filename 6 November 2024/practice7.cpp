
#include<iostream>
using namespace std;

int func1() {
    return 4;
}

int func1(int x) {
    return x;
}

int func1(int x = 2) {
    return x;
}

int main() {
    cout << func1(5) << endl;
}


// Function Overloading 

/* Problem:
   The last two functions have same signature (taking one int parameter)
   which creates ambiguity for compiler.

   Solution:
   Keep only one version of func1(int x), either with or without 
   default parameter, not both.
*/