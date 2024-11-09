// Copy constructor and Assignment operator
//  if you define any constructor (e.g., a parameterized constructor or a copy constructor), 
//  the compiler no longer provides a default constructor automatically.
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