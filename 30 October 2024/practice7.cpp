#include <iostream>
using namespace std;

class Test {
    int *ptr;
public:
    Test() {
        ptr = new int(0);
    }
    
    // Deep copy constructor
    Test(const Test &t) {
        ptr = new int(*t.ptr);  // Creates new memory and copies value
    }
    
    // Shallow copy constructor (default)
    // Test(const Test &t) {
    //     ptr = t.ptr;  // Just copies pointer address
    // }
    
    void setValue(int value) {
        *ptr = value;
    }
    
    int getValue() {
        return *ptr;
    }
    
    ~Test() {
        delete ptr;
    }
};

int main() {
    Test obj1;
    obj1.setValue(5);
    
    // Deep copy
    Test obj2 = obj1;  // Copy constructor called
    
    obj2.setValue(10);
    
    cout << "obj1 value: " << obj1.getValue() << endl;  // Will print 5
    cout << "obj2 value: " << obj2.getValue() << endl;  // Will print 10
    
    return 0;
}

// obj1 value: 5
// obj2 value: 10