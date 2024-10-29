#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int &ref = x;  // ref is a reference to x
    cout << "x = " << x << ", ref = " << ref << endl;
    // x = 10, ref = 10
    
    ref = 20;  // changing ref will change x
    cout << "After changing ref, x = " << x << endl;
    // After changing ref, x = 20
    
    // Swap using pass by value vs reference
    int num1 = 5, num2 = 10;
    cout << "\nBefore swap by value: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapByValue(num1, num2);
    cout << "After swap by value: num1 = " << num1 << ", num2 = " << num2 << endl;
    // Before swap by value: num1 = 5, num2 = 10
    // After swap by value: num1 = 5, num2 = 10


    cout << "\nBefore swap by reference: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapByReference(num1, num2);
    cout << "After swap by reference: num1 = " << num1 << ", num2 = " << num2 << endl;
    // Before swap by reference: num1 = 5, num2 = 10
    // After swap by reference: num1 = 10, num2 = 5
    
    // Reference as function parameter
    int value = 100;
    auto modifyValue = [](int &val) { val *= 2; };
    cout << "\nBefore modification: value = " << value << endl;
    modifyValue(value);
    cout << "After modification: value = " << value << endl;
    // Before modification: value = 100
    // After modification: value = 200

    // Const reference
    const int &constRef = x;
    cout << "\nConst reference value: " << constRef << endl;
    // Const reference value: 20
    // constRef = 30;  // This would cause an error as constRef is constant
    
    return 0;
}
