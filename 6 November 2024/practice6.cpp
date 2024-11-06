// Compile Time Polymorphism (Function Overloading)
#include <iostream>
using namespace std;

class Shape {
public:
    // Area calculation for circle
    double calculateArea(double radius) {
        return 3.14159 * radius * radius;
    }
    
    // Area calculation for rectangle
    double calculateArea(double length, double width) {
        return length * width;
    }
    
    // Area calculation for triangle
    double calculateArea(double base, double height, bool isTriangle) {
        if (isTriangle) {
            return 0.5 * base * height;
        }
        return 0;
    }
};

class MathOperations {
public:
    // Integer addition
    int operate(int a, int b) {
        return a + b;
    }
    
    // Double multiplication
    double operate(double a, double b) {
        return a * b;
    }
    
    // String concatenation
    string operate(string a, string b) {
        return a + b;
    }
};

int main() {
    Shape shape;
    MathOperations math;
    
    // Shape area calculations
    cout << "Circle area: " << shape.calculateArea(5.0) << endl;
    cout << "Rectangle area: " << shape.calculateArea(4.0, 6.0) << endl;
    cout << "Triangle area: " << shape.calculateArea(3.0, 4.0, true) << endl;
    
    // Math operations
    cout << "Integer addition: " << math.operate(5, 3) << endl;
    cout << "Double multiplication: " << math.operate(2.5, 3.0) << endl;
    cout << "String concatenation: " << math.operate("Hello ", "C++!") << endl;
    
    return 0;
}

// Circle area: 78.5397
// Rectangle area: 24
// Triangle area: 6
// Integer addition: 8
// Double multiplication: 7.5
// String concatenation: Hello C++!

