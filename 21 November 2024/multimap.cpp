#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // 1. Create a multimap
    multimap<int, string> myMultimap;

    // 2. Insert elements using insert()
    myMultimap.insert({1, "One"});
    myMultimap.insert(pair<int, string>(2, "Two"));
    myMultimap.insert(make_pair(3, "Three"));
    myMultimap.insert({2, "Another Two"}); // Duplicate key allowed

    // 3. Emplace elements (constructs in-place)
    myMultimap.emplace(4, "Four");
    myMultimap.emplace(5, "Five");

    // 4. Iterating through the multimap
    cout << "Contents of the multimap:\n";
    for (const auto& pair : myMultimap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 5. Access elements using find()
    auto it = myMultimap.find(2);
    if (it != myMultimap.end()) {
        cout << "Found key 2 with value: " << it->second << endl;
    }

    // 6. Count occurrences of a key
    cout << "Count of key 2: " << myMultimap.count(2) << endl;

    // 7. Equal range
    cout << "Equal range for key 2:\n";
    auto range = myMultimap.equal_range(2);
    for (auto itr = range.first; itr != range.second; ++itr) {
        cout << itr->first << ": " << itr->second << endl;
    }

    // 8. Erase elements by key
    myMultimap.erase(2);
    cout << "All elements with key 2 erased.\n";

    // 9. Erase by iterator
    it = myMultimap.find(4);
    if (it != myMultimap.end()) {
        myMultimap.erase(it);
        cout << "Element with key 4 erased by iterator.\n";
    }

    // 10. Check size and max_size
    cout << "Size of multimap: " << myMultimap.size() << endl;
    cout << "Maximum size of multimap: " << myMultimap.max_size() << endl;

    // 11. Check if multimap is empty
    if (myMultimap.empty()) {
        cout << "Multimap is empty.\n";
    } else {
        cout << "Multimap is not empty.\n";
    }

    // 12. Clear the multimap
    myMultimap.clear();
    cout << "Multimap cleared.\n";

    // 13. Swap with another multimap
    multimap<int, string> anotherMultimap = {{7, "Seven"}, {8, "Eight"}};
    myMultimap.swap(anotherMultimap);
    cout << "Swapped with another multimap. Contents of the current multimap:\n";
    for (const auto& pair : myMultimap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 14. Lower bound
    auto lower = myMultimap.lower_bound(7);
    if (lower != myMultimap.end()) {
        cout << "Lower bound for key 7: " << lower->first << " -> " << lower->second << endl;
    }

    // 15. Upper bound
    auto upper = myMultimap.upper_bound(7);
    if (upper != myMultimap.end()) {
        cout << "Upper bound for key 7: " << upper->first << " -> " << upper->second << endl;
    }

    return 0;
}

// Contents of the multimap:
// 1: One
// 2: Two
// 2: Another Two
// 3: Three
// 4: Four
// 5: Five
// Found key 2 with value: Two
// Count of key 2: 2
// Equal range for key 2:
// 2: Two
// 2: Another Two
// All elements with key 2 erased.
// Element with key 4 erased by iterator.
// Size of multimap: 3
// Maximum size of multimap: 128102389400760775
// Multimap is not empty.
// Multimap cleared.
// Swapped with another multimap. Contents of the current multimap:
// 7: Seven
// 8: Eight
// Lower bound for key 7: 7 -> Seven
// Upper bound for key 7: 8 -> Eight



// lower_bound(>=): Returns an iterator to the first element not less than the given key.
// upper_bound(>): Returns an iterator to the first element greater than the given key.