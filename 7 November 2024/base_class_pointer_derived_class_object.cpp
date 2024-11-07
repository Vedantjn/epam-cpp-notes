// base class pointer, derived class object

#include <iostream>
using namespace std;

class Shape {
public:
    void draw() { cout << "Drawing shape\n"; }
};

class Circle : public Shape {
public:
    void draw() { cout << "Drawing circle\n"; }
};

int main() {
    Shape* shape = new Circle();
    shape->draw();  // Calls Shape::draw() without runtime polymorphism
    
    delete shape;
    return 0;
}

// Drawing shape

// ------------------------------------------------------

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() { cout << "Drawing shape\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing circle\n"; }
};

int main() {
    Shape* shape = new Circle();
    shape->draw();  // Calls Circle::draw() 
    
    delete shape;
    return 0;
}

// Drawing circle