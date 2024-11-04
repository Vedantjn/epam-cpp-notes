#include <iostream>
using namespace std;

class exampleClass {
private:
    int x;
    static int count;

public:
    exampleClass() {
        x = 0;
        count++;
    }

    void setX(int val) {
        this->x = val;
    }

    int getX() {
        return this->x;
    }

    static int getCount() {
        return count;
    }
};

int exampleClass::count = 0;

int main() {
    exampleClass e1;
    exampleClass e2;
    
    e1.setX(10);
    e2.setX(20);
    
    cout << "e1.x = " << e1.getX() << endl;
    cout << "e2.x = " << e2.getX() << endl;
    cout << "Total objects created: " << exampleClass::getCount() << endl;
    
    return 0;
}

// e1.x = 10
// e2.x = 20
// Total objects created: 2