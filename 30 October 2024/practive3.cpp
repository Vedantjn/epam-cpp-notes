// what is difference in line 71 and 73
// print address(value of p ) before using delete and print (p) after setting nullptr
#include <iostream>
using namespace std;

int main() {
    int* p = new int(42);

    cout << "Before delete:" << endl;
    cout << "p (address stored in p): " << p << endl;
    cout << "&p (address of pointer p): " << &p << endl;
    cout << "*p (value pointed by p): " << *p << endl;

    delete p;

    cout << "\nAfter delete, before nullptr:" << endl;
    cout << "p (address stored in p): " << p << endl;
    cout << "&p (address of pointer p): " << &p << endl;
    // cout << "*p (value pointed by p): " << *p << endl;  // dangerous, undefined behavior

    p = nullptr;

    cout << "\nAfter setting to nullptr:" << endl;
    cout << "p (address stored in p): " << p << endl;
    cout << "&p (address of pointer p): " << &p << endl;
    // cout << "*p (value pointed by p): " << *p << endl;  // would cause crash

    return 0;
}


// Before delete:
// p (address stored in p): 0x25767687c90
// &p (address of pointer p): 0xdf473ffb88
// *p (value pointed by p): 42

// After delete, before nullptr:
// p (address stored in p): 0x25767687c90
// &p (address of pointer p): 0xdf473ffb88

// After setting to nullptr:
// p (address stored in p): 0
// &p (address of pointer p): 0xdf473ffb88