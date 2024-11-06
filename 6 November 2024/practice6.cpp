// Compile Time Polymorphism
#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
    
    string add(string a, string b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    
    cout << "Integer addition: " << calc.add(5, 3) << endl;
    cout << "Double addition: " << calc.add(3.5, 2.7) << endl;
    cout << "Triple integer addition: " << calc.add(1, 2, 3) << endl;
    cout << "String concatenation: " << calc.add("Hello ", "World!") << endl;
    
    return 0;
}

Integer addition: 8
Double addition: 6.2
Triple integer addition: 6
String concatenation: Hello World!