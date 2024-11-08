
#include <iostream>
using namespace std;

void modifyByReference(int &x) {
    x = x * 2;
}

void modifyByValue(int x) {
    x = x * 2;
}

int main() {
    int num1 = 10;
    int num2 = 10;
    
    cout << "Before modifications:" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    
    modifyByReference(num1);  // Pass by reference
    modifyByValue(num2);      // Pass by value
    
    cout << "\nAfter modifications:" << endl;
    cout << "num1 (passed by reference) = " << num1 << endl;  
    cout << "num2 (passed by value) = " << num2 << endl;     
    
    return 0;
}


// Before modifications:
// num1 = 10
// num2 = 10

// After modifications:
// num1 (passed by reference) = 20
// num2 (passed by value) = 10