// Demonstrating the 'explicit' keyword in C++

/*
Theory:
- The 'explicit' keyword prevents implicit type conversions in constructors
- Without explicit, C++ allows implicit conversion from int to MyClass
- With explicit, we must use direct initialization or explicit type conversion
- This helps prevent unintended type conversions and makes code more clear
*/

// Without using explicit - Allows implicit conversion
#include<iostream>
using namespace std;

class MyClass{
private:
    int data;
public:
    MyClass(int val): data(val){} // Implicit conversion allowed

    void display() {
        cout << data << endl;
    }
};

int main(){
    MyClass obj1 = 7;    // Works fine - implicit conversion from int to MyClass
    MyClass obj2(8);     // Direct initialization
    obj1.display();      // 7
    obj2.display();      // 8
    return 0;
}

// Using explicit - Prevents implicit conversion

#include<iostream>
using namespace std;

class MyClass{
private:
    int data;
public:
    explicit MyClass(int val): data(val){} // Prevents implicit conversion

    void display() {
        cout << data << endl;
    }
};

int main(){
    // MyClass obj1 = 7;    // Error: no suitable conversion
    MyClass obj1(7);        // Correct way: direct initialization
    obj1.display();         // 7
    return 0;
}