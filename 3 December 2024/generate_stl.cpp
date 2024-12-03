#include <vector>
#include <iostream>
#include <algorithm> // For std::generate

using namespace std;

int main() {
    vector<int> s(5); // Vector with 5 default-initialized elements (0)

    cout << "Before Generate: ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    // Generate values using a lambda function
    int counter = 1;
    generate(s.begin(), s.end(), [&counter]() { return counter++; });

    cout << "After Generate (Counter): ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    // Generate random numbers
    generate(s.begin(), s.end(), []() { return rand() % 100; });

    cout << "After Generate (Random Numbers): ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

// Before Generate: 0 0 0 0 0 
// After Generate (Counter): 1 2 3 4 5 
// After Generate (Random Numbers): 41 67 34 0 69 