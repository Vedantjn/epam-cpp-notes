// return_type operator operator_symbol(arguments) {
//     // implementation
// }

#include<iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator + (const Complex& other) {
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main(){
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}

// 4 + 6i

// ------------------------------------

#include <iostream>
using namespace std;

class Counter {
public:
    int value;

    Counter(int val = 0) : value(val) {}

    // Overloading the prefix ++ operator
    Counter operator ++ () {
        ++value;
        return *this;
    }

    // Overloading the postfix ++ operator
    Counter operator ++ (int) {
        Counter temp = *this;
        ++value;
        return temp;
    }

    void display() {
        cout << value << endl;
    }
};

int main() {
    Counter c1(10);
    ++c1;  // Pre-increment
    c1.display();  // Output: 11

    Counter c2(20);
    c2++;  // Post-increment
    c2.display();  // Output: 21
    return 0;
}

// 11
// 21