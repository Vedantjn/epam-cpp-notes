#include<iostream>
using namespace std;

class MyClass {
public:
    inline int add(int a, int b);  // Declaring inline function
};

int MyClass::add(int a, int b) {  // Defining inline function outside class
    return a + b;
}

int main() {
    MyClass obj;
    int result = obj.add(5, 3);
    cout << "Result: " << result << std::endl;
    return 0;
}

// Result: 8