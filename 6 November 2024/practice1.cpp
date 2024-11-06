// Copy constructor and Assignment operator
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

// Inside copy constructor
// Inside assignment operator



// In the assignment operator overload function:
// return *this returns a reference to the current object (the object being assigned to)
// 
// The 'this' keyword is a pointer to the current object
// '*this' dereferences that pointer to get the actual object
// By returning *this, we enable chained assignments like: obj1 = obj2 = obj3
//
// For example, if we have:
// obj3 = obj1;
// The assignment operator returns a reference to obj3 via return *this
