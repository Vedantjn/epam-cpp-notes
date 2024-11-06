// this in assignment operator, address of objects
#include <iostream>
using namespace std;

class myClass {
    public:
        myClass() {

        }

        myClass(const myClass &obj) {
            cout << "Inside copy constructor" << endl;
        }

        myClass& operator=(const myClass &obj) {
            cout << "Inside = member function " << this << endl;
            cout << "Inside assignment operator" << endl;
            return *this;  // Returns reference to the current object
        }
};

int main() {
    myClass obj1;
    myClass obj2 = obj1;  // Copy constructor called
    obj2 = obj1;                          
    cout << "Address of obj1" << &obj1 << endl;
    cout << "Address of obj2" << &obj2 << endl;

    return 0;
}

// Inside copy constructor
// Inside = member function 0x8db3dffb2e
// Inside assignment operator
// Address of obj10x8db3dffb2f
// Address of obj20x8db3dffb2e