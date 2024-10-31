#include <iostream>
using namespace std;

class Base {
    const int id;
    int& ref;
    string name;
public:
    Base(int i, int& r, string n) : id(i), ref(r), name(n) {
        // Constructor body - executes after initialization list
        cout << "Base constructor called" << endl;
    }
};

class Derived : public Base {
    const double value;
public:
    // Must initialize base class members through init list
    Derived(int i, int& r, string n, double v) 
        : Base(i, r, n),  // Base class initialization
          value(v)        // Derived class const member initialization
    {
        cout << "Derived constructor called" << endl;
    }
};

int main() {
    int x = 10;
    Base b1(1, x, "Base");
    Derived d1(2, x, "Derived", 3.14);
    
    return 0;
}

// Base constructor called
// Base constructor called
// Derived constructor called


/*
Constructor Initialization List Benefits:

1. Required for const members:
   - Const members must be initialized at declaration or in init list
   - Cannot be assigned values in constructor body
   - Example: 'id' in Base class must use init list

2. Required for reference members:
   - References must be initialized when created
   - Cannot be reassigned later
   - Example: 'ref' in Base class must use init list

3. Performance Benefits:
   - Direct initialization, avoiding double initialization
   - Members initialized before constructor body executes
   - More efficient than assigning in constructor body

4. Inheritance Benefits:
   - Required to initialize base class members
   - Derived class must call base class constructor via init list
   - Ensures proper initialization order
   - Example: Derived class uses Base(i,r,n) in init list

5. Initialization Order:
   - Members initialized in declaration order, not init list order
   - Base class initialized before derived class
   - Const and reference members must be initialized first

6. Better for Complex Objects:
   - Avoids unnecessary default constructions
   - Single step initialization instead of construct-then-assign
   - More efficient for class type members
*/
