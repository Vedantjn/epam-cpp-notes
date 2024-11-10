/*
 * In C++, a const member function is a member function that is declared with the const
 * keyword at the end of its declaration. This means that the function is not allowed
 * to modify any member variables of the object (unless the member variable is explicitly
 * mutable).
 *
 * Const member functions are commonly used to access data without altering the object's
 * state, making them useful for accessor functions and other read-only operations.
 */

/*
 * A const object in C++ is an object that cannot be modified after it is created.
 * It is declared using the const keyword, which ensures that neither its member
 * variables nor its non-const member functions can be modified.
 *
 * Characteristics of Const Objects:
 * -------------------------------
 * 1. Immutability:
 *    - Once a const object is initialized, its state cannot be changed.
 *
 * 2. Cannot Call Non-Const Member Functions:
 *    - Non-const member functions that attempt to modify the object cannot be
 *      called on a const object.
 *
 * 3. Const Member Functions:
 *    - Only const member functions can be called on a const object.
 *    - These functions do not modify the state of the object.
 *
 * 4. Used for Read-Only Access:
 *    - Const objects are typically used when you want to provide read-only
 *      access to an object.
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