#include <iostream>
using namespace std;

class MyClass {
public:
    int value = 0;

    void setValue(int val) { // Non-const member function
        value = val;
    }

    int getValue() const { // Const member function
        return value; 
    }
};

int main() {
    const MyClass constObj;    // Const object
    MyClass nonConstObj;       // Non-const object

    nonConstObj.setValue(10);  // Valid, modifies value
    cout << "Non-const object's value: " << nonConstObj.getValue() << std::endl;

    // constObj.setValue(10);  // Error, const object cannot call non-const function
    cout << "Const object's value: " << constObj.getValue() << std::endl; // Valid, const object can call const function

    return 0;
}

// Non-const object's value: 10
// Const object's value: 0