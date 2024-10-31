#include <iostream>
using namespace std;

void callByValue(int x) {
    x = x + 10;
    cout << "Inside callByValue: " << x << endl;
}

void callByReference(int &x) {
    x = x + 10;
    cout << "Inside callByReference: " << x << endl;
}

void callByPointer(int *x) {
    *x = *x + 10;
    cout << "Inside callByPointer: " << *x << endl;
}

int main() {
    int num = 10;
    
    cout << "Original value: " << num << endl;
    
    callByValue(num);
    cout << "After callByValue: " << num << endl;
    
    callByReference(num);
    cout << "After callByReference: " << num << endl;
    
    callByPointer(&num);
    cout << "After callByPointer: " << num << endl;
    
    return 0;
}

// Original value: 10
// Inside callByValue: 20
// After callByValue: 10
// Inside callByReference: 20
// After callByReference: 20
// Inside callByPointer: 30
// After callByPointer: 30