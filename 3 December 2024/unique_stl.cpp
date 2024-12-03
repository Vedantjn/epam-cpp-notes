// std::remove shifts unwanted elements to the end of a container and returns an iterator to the new logical end.

// Returns an iterator to the new end of the modified range that only contains the elements not be deleted.
// If there are no elements to be deleted, returns iterator to the container’s end.

#include <vector>
#include <iostream>
#include <algorithm> // For std::remove

using namespace std;

int main() {
    vector<int> s = {1, 2, 3, 2, 4, 2, 5};

    cout << "Original Vector: ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    // Remove all occurrences of the value 2
    auto newEnd = remove(s.begin(), s.end(), 2);

    cout << "After Remove (logical removal): ";
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

// Original Vector: 1 2 3 2 4 2 5 
// After Remove (logical removal): 1 3 4 5 4 2 5 
// After Erase (physical removal): 1 3 4 5 