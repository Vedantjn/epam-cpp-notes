// Swaps the values of two variables.

#include <vector>
#include <iostream>
#include <algorithm> // For std::swap

using namespace std;

int main() {
    vector<int> s1 = {1, 2, 3};
    vector<int> s2 = {4, 5, 6};

    cout << "Before Swap:" << endl;
    cout << "Vector 1: ";
    for (int value : s1) {
        cout << value << " ";
    }
    cout << endl;
    cout << "Vector 2: ";
    for (int value : s2) {
        cout << value << " ";
    }
    cout << endl;

    // Swap contents of s1 and s2
    swap(s1, s2);

    cout << "After Swap:" << endl;
    cout << "Vector 1: ";
    for (int value : s1) {
        cout << value << " ";
    }
    cout << endl;
    cout << "Vector 2: ";
    for (int value : s2) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

// Before Swap:
// Vector 1: 1 2 3 
// Vector 2: 4 5 6 
// After Swap:
// Vector 1: 4 5 6 
// Vector 2: 1 2 3 