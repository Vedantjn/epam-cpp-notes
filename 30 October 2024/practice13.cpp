// Initializing the member variable of type class using iniitalization list & inside the constructor body

#include <iostream>
using namespace std;

class Test {
    int x;
    int y;
public:
    Test() : x(0) {  // initialization list for x
        y = 0;       // initialization inside constructor body
    }
    
    Test(int a, int b) : x(a) {  // initialization list for x
        y = b;                    // initialization inside constructor body
    }
    
    void display() {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Test t1;             // calls default constructor
    Test t2(10, 20);     // calls parameterized constructor
    
    t1.display();
    t2.display();
    
    return 0;
}

// x = 0, y = 0
// x = 10, y = 20