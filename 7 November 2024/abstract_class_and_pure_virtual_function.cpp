// Abstract Class: A class that has at least one pure virtual function.
// - Cannot be instantiated on its own
// - Used as a base class for derived classes
// - Provides a common interface for derived classes
// - Forces derived classes to implement the pure virtual functions

// Pure Virtual Function: A virtual function that must be implemented by derived classes
// - Declared by assigning 0 (virtual void func() = 0;)
// - Makes the class abstract
// - Defines an interface that derived classes must follow

#include <iostream>
using namespace std;

// Abstract class Shape with pure virtual functions
class Shape {
public:
    // Pure virtual functions - must be implemented by derived classes
    virtual double calculateArea() = 0;  // No implementation in base class
    virtual void display() = 0;          // No implementation in base class
};

// Concrete class Circle implementing Shape
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    // Implementation of pure virtual functions
    double calculateArea() override {
        return 3.14159 * radius * radius;
    }
    
    void display() override {
        cout << "Circle with radius: " << radius << endl;
        cout << "Area: " << calculateArea() << endl;
    }
};

// Concrete class Rectangle implementing Shape
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    
    // Implementation of pure virtual functions
    double calculateArea() override {
        return length * width;
    }
    
    void display() override {
        cout << "Rectangle with length: " << length << " and width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
    }
};

int main() {
    // Shape shape; // Cannot create instance of abstract class
    
    Shape* shapes[2];
    shapes[0] = new Circle(5);      // Can use pointers/references to abstract class
    shapes[1] = new Rectangle(4, 6); // to achieve polymorphism
    
    for(int i = 0; i < 2; i++) {
        shapes[i]->display();
        cout << endl;
    }
    
    // Clean up
    for(int i = 0; i < 2; i++) {
        delete shapes[i];
    }
    
    return 0;
}

// Circle with radius: 5
// Area: 78.5397

// Rectangle with length: 4 and width: 6
// Area: 24