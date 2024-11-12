
#include <iostream>
using namespace std;

int main() {
    try {
        cout << "Outer try block\n";
        
        try {
            cout << "Inner try block\n";
            throw 20;
        }
        catch(int x) {
            cout << "Inner catch block, caught: " << x << endl;
            throw; // Re-throwing the exception
        }
    }
    catch(int x) {
        cout << "Outer catch block, caught: " << x << endl;
    }
    
    cout << "End of program\n";
    return 0;
}

// Outer try block
// Inner try block
// Inner catch block, caught: 20
// Outer catch block, caught: 20
// End of program