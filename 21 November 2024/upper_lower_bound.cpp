// In C++, the lower_bound and upper_bound are methods used in associative containers like std::set, std::map, std::multiset, and std::multimap. These methods help find elements in a sorted range.

// lower_bound(key): Returns an iterator pointing to the first element that is not less than the given key (i.e., the first element that is greater or equal to key). If no such element is found, it returns end().

// upper_bound(key): Returns an iterator pointing to the first element that is greater than the given key. If no such element exists, it returns end().

#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30, 40, 50};

    // Using lower_bound to find the first element >= 30
    auto lb = mySet.lower_bound(30);
    if (lb != mySet.end()) {
        cout << "Lower bound of 30: " << *lb << endl;  // Output: 30
    }

    // Using upper_bound to find the first element > 30
    auto ub = mySet.upper_bound(30);
    if (ub != mySet.end()) {
        cout << "Upper bound of 30: " << *ub << endl;  // Output: 40
    }

    // Test case for a value that's not in the set
    auto lb2 = mySet.lower_bound(25);
    if (lb2 != mySet.end()) {
        cout << "Lower bound of 25: " << *lb2 << endl;  // Output: 30
    }

    // Test case where upper_bound has no element greater than 50
    auto ub2 = mySet.upper_bound(50);
    if (ub2 == mySet.end()) {
        cout << "Upper bound of 50: Not found, at end of set" << endl;  // Output: Not found
    }

    return 0;
}

// Lower bound of 30: 30
// Upper bound of 30: 40
// Lower bound of 25: 30
// Upper bound of 50: Not found, at end of set  