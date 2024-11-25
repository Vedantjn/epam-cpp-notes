#include<iostream>
#include<memory>
using namespace std;

class MyClass {
public:
    MyClass() {cout << "MyClass constructor called" << endl; }
    ~MyClass() {cout << "MyClass destructor called" << endl; }

};

void customDelete(MyClass* ptr) {
    cout << "Custom delete called" << endl;
    delete ptr;
}

int main(){
    unique_ptr<MyClass, decltype(&customDelete)> ptr(new MyClass(), customDelete);
    
    return 0;
}

// MyClass constructor called
// Custom delete called
// MyClass destructor called

// -------------------------------------------

#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    MyClass() { cout << "MyClass constructor called\n"; }
    ~MyClass() { cout << "MyClass destructor called\n"; }
};

void customDelete(MyClass* ptr) {
    cout << "Custom delete called\n";
    delete ptr;  // Deleting the object in a custom way
}

int main() {
    shared_ptr<MyClass> ptr1(new MyClass(), customDelete);
    {
        shared_ptr<MyClass> ptr2 = ptr1;  // Sharing ownership
    }  // ptr2 goes out of scope, but ptr1 still holds the object

    // When ptr1 goes out of scope, the custom deleter will be invoked
    return 0;
}

// MyClass constructor called
// Custom delete called
// MyClass destructor called