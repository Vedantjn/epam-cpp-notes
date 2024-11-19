#include <iostream>
using namespace std;

int main() {
    // 1. static_cast - compile-time type checking
    double pi = 3.14159;
    int intPi = static_cast<int>(pi);    // double to int
    cout << "static_cast<int>(3.14159) = " << intPi << endl;

    // 2. dynamic_cast - runtime type checking (for polymorphic types)
    class Base { virtual void dummy() {} };
    class Derived : public Base { };
    Base* base = new Derived;
    Derived* derived = dynamic_cast<Derived*>(base);
    if(derived)
        cout << "dynamic_cast successful" << endl;

    // 3. const_cast - remove const qualifier
    const int constant = 21;
    const int* constPtr = &constant;
    int* modifiable = const_cast<int*>(constPtr);
    *modifiable = 33;
    cout << "const_cast value: " << *modifiable << endl; // 33

    // 4. reinterpret_cast - dangerous, low-level reinterpretation
    int number = 42;
    int* ptr = &number;
    long long address = reinterpret_cast<long long>(ptr);
    cout << "reinterpret_cast address: " << address << endl; // 575276055816

    delete base;
    return 0;
}
