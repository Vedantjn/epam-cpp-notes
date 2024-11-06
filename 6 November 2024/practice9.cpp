// Operator Overloading
#include <iostream>
using namespace std;

class Complex {
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiply operator
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                      real * other.imag + imag * other.real);
    }

    // Division operator
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                      (imag * other.real - real * other.imag) / denominator);
    }

    // Increment operators
    Complex& operator++() {  // Pre-increment
        // Increment real part by 1 and return reference to modified object
        real++;
        return *this;
    }

    Complex operator++(int) {  // Post-increment
        // Save current state, increment real part, return unmodified copy
        Complex temp = *this;
        real++;
        return temp;
    }

    // Assignment operators
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex& operator-=(const Complex& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    // Comparison operators
    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    // Display function
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1 + c2;  // Using overloaded + operator
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;  // Multiplication
    Complex c6 = c1 / c2;  // Division
    
    ++c1;  // Pre-increment
    c2++;  // Post-increment
    
    Complex c7(3, 4);
    c7 += c2;  // Using += operator

    c3.display();  // Output: 4 + 6i
    c4.display();
    c5.display();
    c6.display();
    c1.display();
    c2.display();
    c7.display();

    // Test comparison
    if(c1 == c2)
        cout << "c1 equals c2" << endl;
    else
        cout << "c1 does not equal c2" << endl;

    return 0;
}

// 4 + 6i
// 2 + 2i
// -5 + 10i
// 2.2 + -0.4i
// 4 + 4i
// 2 + 2i
// 5 + 6i
// c1 does not equal c2