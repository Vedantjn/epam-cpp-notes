// Return an object from inside member function and capture in main -> copy constructor

#include <iostream>
using namespace std;

class Test {
    int x;
public:
    // Constructor with default argument
    Test(int x = 0) : x(x) {
        cout << "Constructor called" << endl;
    }
    
    // Copy constructor
    Test(const Test& t) {
        x = t.x;
        cout << "Copy constructor called" << endl;
    }
    
    // Member function that returns Test object
    Test getObject() {
        Test temp(x);  // Creates temporary object
        return temp;   // Returns copy of temporary object
    }
    
    // Print function to display x
    void print() {
        cout << "x = " << x << endl;
    }
};

int main() {
    Test t1(10);                // Creates object t1 with x = 10
    Test t2 = t1.getObject();   // Calls getObject() and copies returned object to t2
    
    t2.print();                 // Prints value of x in t2
    
    return 0;
}

// Output:
// Constructor called         // For t1
// Constructor called         // For temp inside getObject()
// x = 10                    // Print statement