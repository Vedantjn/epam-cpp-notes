#include <iostream>
#include <memory>  // For shared_ptr
#include <functional>  // For std::function

using namespace std;

class MyClass {
    int value;
    
public:
    MyClass(int val) : value(val) {}

    void printValue() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    // Creating shared_ptr with a custom deleter using a lambda function
    auto customDeleter = [](MyClass* ptr) {
        cout << "Custom deleter called, deleting object." << endl;
        delete ptr;  // Custom deletion logic
    };

    // Using shared_ptr with the custom deleter
    shared_ptr<MyClass> obj(new MyClass(10), customDeleter);
    obj->printValue();  // Print the value

    // When the shared_ptr goes out of scope, the custom deleter will be called.
    
    return 0;
}
