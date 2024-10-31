#include <iostream>
using namespace std;

class Box {
    private:
        int length;
        int* width;
    public:
        Box() {
            length = 0;
            width = new int(0);
        }
        
        Box(int l, int w) {
            length = l;
            width = new int(w);
        }
        
        void setValues(int l, int w) {
            length = l;
            *width = w;
        }
        
        void display() {
            cout << "Length: " << length << endl;
            cout << "Width: " << *width << endl;
        }
};

int main() {
    Box box1(10, 20);
    cout << "Original Box:" << endl;
    box1.display();
    
    // Shallow copy using default copy constructor
    Box box2 = box1;
    cout << "\nCopied Box:" << endl;
    box2.display();
    
    // Modifying box2 will affect box1's width since it's a shallow copy
    box2.setValues(30, 40);
    cout << "\nAfter modifying box2:" << endl;
    cout << "Box1:" << endl;
    box1.display();
    cout << "Box2:" << endl;
    box2.display();
    
    return 0;
}






