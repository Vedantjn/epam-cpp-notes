#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create and initialize vector
    vector<int> vec = {1, 2, 3, 4, 5};

    // Add elements
    vec.push_back(6);                  // Add at end
    vec.emplace_back(7);              // Construct element in-place
    vec.insert(vec.begin(), 0);       // Insert at beginning

    // Access elements
    cout << "First element: " << vec.front() << endl;
    cout << "Last element: " << vec.back() << endl;
    cout << "Element at index 2: " << vec.at(2) << endl;

    // Size operations
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    cout << "Is empty: " << vec.empty() << endl;

    // Modify vector
    vec.resize(10);                   // Resize vector
    vec.reserve(20);                  // Reserve capacity
    vec.shrink_to_fit();             // Reduce capacity to fit size

    // Remove elements
    vec.pop_back();                   // Remove last element
    vec.erase(vec.begin());          // Remove first element
    vec.erase(vec.begin(), vec.begin() + 2);  // Remove range

    // Vector algorithms
    sort(vec.begin(), vec.end());                    // Sort
    reverse(vec.begin(), vec.end());                 // Reverse
    auto it = find(vec.begin(), vec.end(), 3);      // Find element

    // Clear vector
    vec.clear();                      // Remove all elements

    // Vector of custom size
    vector<int> vec2(5, 10);     // Create vector of size 5 with all elements as 10

    // Copy vectors
    vector<int> vec3(vec2);      // Copy constructor
    vector<int> vec4 = vec2;     // Assignment operator

    // Swap vectors
    vec3.swap(vec4);                  // Swap contents

    // Iterators
    for(auto it = vec2.begin(); it != vec2.end(); ++it) {
        cout << *it << " ";
    }

    // Range-based for loop
    for(const auto& element : vec2) {
        cout << element << " ";
    }

    return 0;
}

// First element: 0
// Last element: 7
// Element at index 2: 2
// Size: 8
// Capacity: 10
// Is empty: 0
// 10 10 10 10 10 10 10 10 10 10