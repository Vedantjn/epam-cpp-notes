#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {
    // Arrays:
    // - Fixed size (static)
    // - Stored in stack memory
    // - Faster access time
    // - Cannot be resized
    // - Size must be known at compile time
    int staticArray[5] = {1, 2, 3, 4, 5};
    array<int, 5> modernArray = {1, 2, 3, 4, 5}; // C++11 array

    // Vectors:
    // - Dynamic size
    // - Stored in heap memory
    // - Slightly slower access time
    // - Can be resized at runtime
    // - Automatic memory management
    vector<int> dynamicVector = {1, 2, 3, 4, 5};

    // Demonstrating vector's dynamic nature
    cout << "Vector initial size: " << dynamicVector.size() << endl;
    dynamicVector.push_back(6);
    cout << "Vector after push_back: " << dynamicVector.size() << endl;

    // Array bounds are not automatically checked (unsafe)
    // staticArray[5] = 6; // Dangerous! Buffer overflow

    // Vector bounds are checked with at() method (safe)
    try {
        dynamicVector.at(10) = 6; // Throws out_of_range exception
    } catch (const out_of_range& e) {
        cout << "Vector access error: " << e.what() << endl;
    }

    return 0;
}

// Vector initial size: 5
// Vector after push_back: 6
// Vector access error: vector::_M_range_check: __n (which is 10) >= this->size() (which is 6)