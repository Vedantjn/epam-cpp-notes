#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    // Normal constructor
    Point(int x1 = 0, int y1 = 0) {
        x = x1;
        y = y1;
    }
    
    // Copy constructor
    Point(const Point &p) {
        x = p.x;
        y = p.y;
        cout << "Copy constructor called" << endl;
    }
    
    void display() {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Point p1(10, 20);     // Normal constructor called
    Point p2 = p1;        // Copy constructor called
    Point p3(p1);         // Copy constructor called
    
    cout << "Point p1: ";
    p1.display();
    
    cout << "Point p2: ";
    p2.display();
    
    cout << "Point p3: ";
    p3.display();
    
    return 0;
}
