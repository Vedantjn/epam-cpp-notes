
#include <iostream>
#include <string>
using namespace std;

// Generic template function
template <typename T>
void display(T x) {
    cout << "Template version: " << x << endl;
}

// Specific overload for int
void display(int x) {
    cout << "Int specific version: " << x << endl;
}

// Specific overload for string
void display(string x) {
    cout << "String specific version: " << x << endl;
}

// Template with multiple parameters
template <typename T, typename U>
void multiDisplay(T x, U y) {
    cout << "Template multi-param: " << x << ", " << y << endl;
}

// Specific overload for two ints
void multiDisplay(int x, int y) {
    cout << "Int-Int specific version: " << x << ", " << y << endl;
}

int main() {
    // Test case 1: When exact match exists
    display(10);          // Calls int specific version
    display("Hello");     // Calls template version (char*)
    display(string("Hi")); // Calls string specific version
    
    // Test case 2: When no exact match exists
    display(3.14);        // Calls template version
    
    // Test case 3: Multiple parameter templates
    multiDisplay(10, 20);     // Calls int-int specific version
    multiDisplay(10, 3.14);   // Calls template version
    multiDisplay("Hi", 100);  // Calls template version
    
    return 0;
}

// Int specific version: 10
// Template version: Hello
// String specific version: Hi
// Template version: 3.14
// Int-Int specific version: 10, 20
// Template multi-param: 10, 3.14
// Template multi-param: Hi, 100