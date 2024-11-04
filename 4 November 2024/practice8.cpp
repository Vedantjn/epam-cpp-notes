// try accessing base class member func from derived class through scope resolution operator 
 
#include <iostream>
using namespace std;

class Base {
    public:
        void display() {
            cout << "Display from Base class" << endl;
        }
};

class Derived : public Base {
    public:
        void display() {
            cout << "Display from Derived class" << endl;
            Base::display();  // Accessing base class member through scope resolution
        }
};

int main() {
    Derived d;
    d.display();
    return 0;
}

// Display from Derived class
// Display from Base class
