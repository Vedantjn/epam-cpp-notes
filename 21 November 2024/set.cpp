#include <iostream>
#include <set>

using namespace std;

int main() {
    using namespace std;
    
    set<int> stl;

    // Inserting elements
    stl.insert(10);
    stl.insert(20);
    stl.insert(30);

    // Checking if an element exists
    if (stl.find(20) != stl.end()) {
        // Element found
    }

    // Erasing an element
    stl.erase(10);

    // Iterating through the set
    for (const auto& element : stl) {
        // Process element
    }

    // Getting the size of the set
    size_t size = stl.size();

    // Clearing the set
    stl.clear();

    // Checking if the set is empty
    if (stl.empty()) {
        // Set is empty
    }

    // Inserting multiple elements
    stl.insert({40, 50, 60});

    // Finding the lower bound of an element
    auto it = stl.lower_bound(50);
    if (it != stl.end()) {
        // Lower bound found
    }

    // Finding the upper bound of an element
    auto it2 = stl.upper_bound(50);
    if (it2 != stl.end()) {
        // Upper bound found
    }

    // Checking the maximum size of the set
    size_t maxSize = stl.max_size();

    // Swapping with another set
    set<int> anotherSet = {70, 80};
    stl.swap(anotherSet);

    return 0;
}  
