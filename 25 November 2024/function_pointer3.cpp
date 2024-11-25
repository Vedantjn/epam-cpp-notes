#include <iostream>
using namespace std;

class myClass {
    // A private member function
    void memFunc1(int x) {
        cout << "memFunc1 called with value: " << x << endl;
    }

    // Another private member function
    void memFunc2(bool b) {
        cout << "memFunc2 called with value: " << boolalpha << b << endl;
    }

public:
    // A public wrapper function to allow controlled access to private member functions
    void invokeMemFunc1(int x) {
        memFunc1(x);
    }

    // A public member function
    void myFunc(int x) {
        cout << "myFunc called with value: " << x << endl;
    }
};

int main() {
    myClass obj;

    // Declare a pointer to a member function with the signature `void(int)`
    void (myClass::*memFuncPtr)(int);

    // Point the function pointer to `myFunc`
    memFuncPtr = &myClass::myFunc;

    // Call the member function via the pointer
    (obj.*memFuncPtr)(42);  // Output: myFunc called with value: 42

    // Use a public wrapper to access a private member function
    obj.invokeMemFunc1(10); // Output: memFunc1 called with value: 10

    return 0;
}

// myFunc called with value: 42
// memFunc1 called with value: 10