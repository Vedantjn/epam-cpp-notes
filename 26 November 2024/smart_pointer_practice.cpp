#include <iostream>
#include <memory>  

using namespace std;

class MyClass1 {
    int value;
    
public:
    MyClass1(int val) : value(val) {}

    void printvalue() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    shared_ptr<MyClass1> obj = make_shared<MyClass1>(10);
    obj->printvalue();  

    // shared_ptr<MyClass1[]> ptr = make_shared<MyClass1[]>(10);

    shared_ptr<MyClass1[]> ptr1(new MyClass1[10], default_delete<MyClass1[]>());

    shared_ptr<MyClass1[]> ptr2(new MyClass1[10], [](MyClass1* p) {
        delete[] p; 
    });

    return 0;
}
