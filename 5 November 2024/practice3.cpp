
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() {
        length = 0.0;
        width = 0.0;
    }

    // Explicit constructor to prevent implicit conversions
    Rectangle(double size) {
        length = size;
        width = size;
    }

    double getArea() {
        return length * width;
    }
};

int main() {
    // Valid: Direct initialization using explicit constructor
    Rectangle square1(5.0);
    cout << "Area of square1: " << square1.getArea() << endl;

    // Invalid: This will cause compilation error due to explicit keyword
    // Rectangle square2 = 5.0;  // Won't work - implicit conversion not allowed
    // cout << "Area of square1: " << square2.getArea() << endl;

    // Valid: Explicit conversion
    Rectangle square3 = Rectangle(5.0);
    cout << "Area of square3: " << square3.getArea() << endl;

    return 0;
}