#include <vector>
#include <iostream>
#include <algorithm> // For std::transform

using namespace std;

int main() {
    vector<int> s = {1, 2, 3, 4, 5};
    vector<int> result(s.size()); // Result container of the same size

    cout << "Original Vector: ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    // Transform: Square each element
    transform(s.begin(), s.end(), result.begin(), [](int x) { return x * x; });

    cout << "After Transform (Square): ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    // In-place transformation: Increment each element by 10
    transform(s.begin(), s.end(), s.begin(), [](int x) { return x + 10; });

    cout << "After In-Place Transform (Add 10): ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

// Original Vector: 1 2 3 4 5 
// After Transform (Square): 1 4 9 16 25 
// After In-Place Transform (Add 10): 11 12 13 14 15 