// Reference variables can also be initialised with Constructor initialisation list,
// they can also be declared as other member variables.

#include <iostream>
using namespace std;

class Test {
    int &ref;
    int value;
public:
    Test(int &x) : ref(x), value(100) {  // constructor initialization list for reference
        cout << "Reference value: " << ref << endl;
        cout << "Member value: " << value << endl;
    }
    
    void updateRef(int newVal) {
        ref = newVal;
    }
    
    void display() {
        cout << "Current reference value: " << ref << endl;
        cout << "Current member value: " << value << endl;
    }
};

int main() {
    int num = 50;
    Test obj(num);
    
    cout << "\nOriginal num: " << num << endl;
    obj.updateRef(75);
    cout << "After update num: " << num << endl;
    
    obj.display();
    
    return 0;
}

// Reference value: 50
// Member value: 100

// Original num: 50
// After update num: 75
// Current reference value: 75
// Current member value: 100
