// Functions like remove_if and unique can accept custom lambdas for flexible behavior.

// STL algorithms like remove, remove_if, and unique don't shrink the container but rearrange elements. Use erase to shrink the container.

#include <vector>
#include <iostream>
#include <algorithm> // For std::remove_if

using namespace std;

int main() {
    vector<int> s = {1, 2, 3, 4, 5, 6};

    cout << "Original Vector: ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    // Remove all elements greater than 3
    auto newEnd = remove_if(s.begin(), s.end(), [](int x) { return x > 3; });

    cout << "After Remove_if (logical removal): ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    // Erase the removed elements physically
    s.erase(newEnd, s.end());

    cout << "After Erase (physical removal): ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

// Original Vector: 1 2 3 4 5 6 
// After Remove_if (logical removal): 1 2 3 4 5 6
// After Erase (physical removal): 1 2 3