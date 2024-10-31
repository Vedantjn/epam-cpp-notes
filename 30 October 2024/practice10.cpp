// The 'explicit' keyword prevents implicit type conversions in constructors
// It helps avoid unintended automatic conversions that could lead to bugs

#include <iostream>
using namespace std;

class Distance {
private:
    int meters;
    
public:
    // Explicit constructor to prevent implicit conversion
    // Without explicit, Distance dist2 = 200; would work by implicitly converting int to Distance
    // With explicit, only direct initialization Distance dist1(100); is allowed
    explicit Distance(int m) {
        meters = m;
    }
    
    void displayDistance() {
        cout << "Distance is " << meters << " meters" << endl;
    }
};

int main() {
    Distance dist1(100);    // Direct initialization - allowed
    dist1.displayDistance(); // Distance is 100 meters
    
    // Distance dist2 = 200;  // Copy initialization - not allowed due to explicit
    // The above line would work if explicit was removed, but could lead to unexpected behavior
//     practice10.cpp:28:22: error: conversion from 'int' to non-scalar type 'Distance' requested
//    28 |     Distance dist2 = 200;  // Copy initialization - not allowed due to explicit
      
    return 0;
}
