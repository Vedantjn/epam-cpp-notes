#include <iostream>
#include <memory>  // For shared pointers

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
    // Using shared_ptr for a single object
    shared_ptr<MyClass1> obj = make_shared<MyClass1>(10);
    obj->printvalue();  // Print the value of obj

    // Using shared_ptr for an array of objects
    shared_ptr<MyClass1[]> ptr = make_shared<MyClass1[]>(10);  // Array of 10 MyClass1 objects
    // shared_ptr<MyClass1[]>ptr = new MyClass1[](10);

    // Since shared_ptr handles memory deallocation automatically, we don't need to call delete explicitly

    return 0;
}
