// static member functions cannot access non-static member variables of the class. 
// This is because static member functions belong to the class itself, not to any 
// specific instance (object) of the class.

#include <iostream>
using namespace std;

class myClass {
    int x;
    static int count;
    static int totalSum;
public:
    myClass(int y): x(y) {
        cout << "Inside constructor" << endl;
        count++;
        totalSum += y;
    }

    void memFunc() {
        cout << "Inside member function" << endl;
        cout << "Address of obj is: " << this << endl;
        cout << this->x << endl;    
        cout << x << endl; // this->x
        cout << "Number of objects created: " << count << endl;
    }

    static int getCount() {
        return count;
    }

    static int getTotalSum() {
        return totalSum;
    }

    static double getAverage() {
        if(count == 0) return 0;
        return static_cast<double>(totalSum) / count;
    }
};

int myClass::count = 0;
int myClass::totalSum = 0;

int main() {
    cout << "Initial count: " << myClass::getCount() << endl;
    cout << "Initial average: " << myClass::getAverage() << endl;

    myClass obj(10);
    cout << &obj << endl;
    obj.memFunc();

    myClass obj2(20);
    obj2.memFunc();

    cout << "Total objects: " << myClass::getCount() << endl;
    cout << "Sum of all values: " << myClass::getTotalSum() << endl;
    cout << "Average value: " << myClass::getAverage() << endl;
    return 0;
}