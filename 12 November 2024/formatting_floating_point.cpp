// This code demonstrates formatting of floating-point numbers in C++
#include <iostream>
using namespace std;

int main() {
    float f = 4.5;
    
    // Set width to 10 characters
    cout.width(10);    
    
    // Set precision to 3 decimal places
    cout.precision(3);  
    
    // Use fixed decimal notation
    cout.setf(ios::fixed);
    cout << f << endl;  // Outputs: "    4.500"
    
    // Switch back to default notation
    cout.unsetf(ios::fixed);
    cout << f << endl;  // Outputs: "     4.5"
    
    // Set fill character to '*'
    cout.fill('*');
    cout.width(10);
    cout << f << endl;  // Outputs: "*****4.50"
    
    return 0;
}

//      4.500
// 4.5
// *******4.5