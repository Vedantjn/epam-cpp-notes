#include<iostream>
using namespace std;

double add(double a, double b) {
    return a+b;
}

double subtract(double a, double b) {
    return a-b;
}

double multiply(double a, double b) {
    return a*b;
}

double divide(double a, double b) {
    return a/b;
}

double calculator(double a, double b, double(*ff)(double, double)) {
    return ff(a, b);
}

int main(){
    double a = 33;
    double b = 56;

    double result = 0;
    int option = 0;
    cout << "Choose \n 1 for Add \n 2 for Subtract \n 3 for Multiply \n 4 for Division \n ";
    cin >> option;

    switch(option) {
        case 1 :
            result = calculator(a, b, add);
            break;
        case 2 :
            result = calculator(a, b, subtract);
            break;
        case 3 :
            result = calculator(a, b, multiply);
            break;
        case 4 :
            result = calculator(a, b, divide);
            break;
    }

    cout << "\nThe final result is \n" << result << endl;

    return 0;
}