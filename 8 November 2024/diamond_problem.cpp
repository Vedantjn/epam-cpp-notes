#include <iostream>
using namespace std;

// Base class
class A {
public:
    void display() {
        cout << "Class A display" << endl;
    }
};

// First derived class
class B : virtual public A {
public:
    void displayB() {
        cout << "Class B display" << endl;
    }
};

// Second derived class
class C : virtual public A {
public:
    void displayC() {
        cout << "Class C display" << endl;
    }
};

// Class inheriting from both B and C
class D : public B, public C {
public:
    void displayD() {
        cout << "Class D display" << endl;
    }
};

int main() {
    D d;
    d.display();  // Without virtual inheritance, this would be ambiguous
    d.displayB();
    d.displayC();
    d.displayD();
    
    return 0;
}

// Class A display
// Class B display
// Class C display
// Class D display