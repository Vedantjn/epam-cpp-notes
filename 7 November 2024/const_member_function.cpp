/*
 * In C++, a const member function is a member function that is declared with the const
 * keyword at the end of its declaration. This means that the function is not allowed
 * to modify any member variables of the object (unless the member variable is explicitly
 * mutable).
 *
 * Const member functions are commonly used to access data without altering the object's
 * state, making them useful for accessor functions and other read-only operations.
 */

#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    // Const member function to get area
    int getArea() const {
        return width * height;
    }

    // Non-const function to change dimensions
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }

    // Const function to print the rectangle dimensions
    void print() const {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    const Rectangle rect(10, 5); // Const object

    cout << "Area: " << rect.getArea() << endl; // Works because getArea() is const

    // rect.setDimensions(20, 10); // Error: cannot call non-const function on a const object

    rect.print(); // Works because print() is a const member function

    return 0;
}

// Area: 50
// Width: 10, Height: 5
