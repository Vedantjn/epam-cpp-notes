// in stack unwinding, before reaching the catch block, all the fully constructed objects will be destructed
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructed\n"; }
    ~A() { cout << "A destructed\n"; }
};

class B {
public:
    B() { cout << "B constructed\n"; }
    ~B() { cout << "B destructed\n"; }
};

void func() {
    A a;
    B b;
    throw runtime_error("Exception thrown in func()");
}

int main() {
    try {
        func();
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    return 0;
}

// A constructed
// B constructed
// B destructed
// A destructed
// Caught exception: Exception thrown in func()