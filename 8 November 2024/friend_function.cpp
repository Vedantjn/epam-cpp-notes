// Friend Function
#include <iostream>
using namespace std;

/*
Friend Functions:
1. Friend functions are not member functions of a class
2. They can access private and protected members of the class
3. They are declared inside the class with 'friend' keyword
4. They can be declared in public or private section of the class
5. They cannot access members directly, need object name and dot operator
6. Multiple classes can have same friend function
7. Friend functions break encapsulation but provide flexibility
*/

class Box {
private:
    double length;
    double width;
    double height;

public:
    Box(double l = 0.0, double w = 0.0, double h = 0.0) {
        length = l;
        width = w;
        height = h;
    }

    // Friend function declaration
    friend double getVolume(Box box);
};

// Friend function definition
double getVolume(Box box) {
    // Friend function can access private members
    return box.length * box.width * box.height;
}

int main() {
    Box myBox(3.0, 4.0, 5.0);
    
    // Using friend function to calculate volume
    cout << "Volume of box: " << getVolume(myBox) << endl; // Volume of box: 60
    
    return 0;
}