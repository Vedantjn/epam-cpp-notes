// Significance of '&' in assignment operator
#include <iostream>
using namespace std;

class myClass {
    public:
        myClass() {
            cout << "Default constructor" << endl;
        }

        myClass(const myClass &obj) {
            cout << "Inside copy constructor" << endl;
        }

        myClass& operator=(const myClass &obj) {
            cout << "Inside assignment operator" << endl;
            return *this;  // Returns reference to the current object
        }


};

int main() {
    myClass obj1;
    myClass obj2 = obj1;  // Copy constructor called

    myClass obj3;
    obj3 = obj1;          // Assignment operator called. This is like obj3.operator=(obj1)
    
    return 0;
}

// Default constructor
// Inside copy constructor
// Default constructor
// Inside assignment operator


// The & in myClass& operator=(const myClass &obj) is significant because
//  it returns a reference to the object being assigned.

// 1. Enables Assignment Chaining
// By returning a reference to the current object (*this),
//  the assignment operator allows chaining of multiple assignment operations in a single expression:

// obj1 = obj2 = obj3;  // This is equivalent to: obj1 = (obj2 = obj3);
// Without returning a reference, this chaining would not be possible, 
// as each assignment would return a temporary copy of the object rather 
// than a reference to the actual object.


// 2. Prevents Unnecessary Object Copying
// When operator= returns by reference, it avoids copying the entire object,
// which would be required if we returned by value. This prevents performance overhead,
// especially for larger objects. Instead, a reference is returned, keeping the operation efficient.

// return *this; returns a reference to the current object, enabling assignment chaining and efficient 
// usage in assignment operations.

// The & in myClass& operator= allows the operator to:

// Support assignment chaining,
// Avoid unnecessary object copying, and
// Provide behavior consistent with built-in types.`