#include <iostream>
using namespace std;

class myClass {
    int x;
public:
    myClass(int y): x(y) {
        cout << "Inside constructor" << endl;
    }

    void memFunc() {
        cout << "Inside member function" << endl;
        cout << "Address of obj is: " << this << endl;
        cout << this->x << endl;    
        cout << x << endl; // this->x
        
    }
};

int main() {
    myClass obj(10);
    cout << &obj << endl;
    obj.memFunc();
    return 0;
}