
#include <iostream>
using namespace std;

class Base {
    int x;
public:
    Base(int a) : x(a) {
        cout << "Base constructor called" << endl;
    }
    
    // Copy constructor with explicit keyword
    explicit Base(const Base& obj) : x(obj.x) {
        cout << "Base copy constructor called" << endl;
    }
};

class Derived : public Base {
    int y;
public:
    // Constructor
    Derived(int a, int b) : Base(a), y(b) {
        cout << "Derived constructor called" << endl;
    }
    
    // Explicit copy constructor
    explicit Derived(const Derived& obj) : Base(obj), y(obj.y) {
        cout << "Derived copy constructor called" << endl;
    }
};

int main() {
    Derived d1(10, 20);
    
    // This will work
    Derived d2(d1);
    
    // This will not work due to explicit keyword
    // Derived d3 = d1;  // Error: Copy initialization not allowed due to explicit copy constructor
    // The explicit keyword prevents implicit conversions and copy-initialization
    // To fix, use direct initialization: Derived d3(d1);
    
    return 0;
}

// Base constructor called
// Derived constructor called
// Base copy constructor called
// Derived copy constructor called