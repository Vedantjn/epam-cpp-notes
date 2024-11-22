#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // 1. Create a map
    map<int, string> myMap;

    // 2. Insert elements using insert()
    myMap.insert({1, "One"});
    myMap.insert(pair<int, string>(2, "Two"));
    myMap.insert(make_pair(3, "Three"));

    // 3. Emplace elements (constructs in-place)
    myMap.emplace(4, "Four");
    myMap.emplace(5, "Five");

    // 4. Access elements using []
    myMap[6] = "Six";
    cout << "Element with key 6: " << myMap[6] << endl;

    // 5. Access elements using at()
    cout << "Element with key 4: " << myMap.at(4) << endl;

    // 6. Find an element using find()
    auto it = myMap.find(3);
    if (it != myMap.end()) {
        cout << "Found key 3 with value: " << it->second << endl;
    }

    // 7. Count occurrences of a key (always 0 or 1 in std::map)
    cout << "Count of key 2: " << myMap.count(2) << endl;

    // 8. Iterating through the map
    cout << "Iterating through map:\n";
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 9. Erase an element by key
    myMap.erase(2);
    cout << "Key 2 erased.\n";

    // 10. Erase an element by iterator
    it = myMap.find(4);
    if (it != myMap.end()) {
        myMap.erase(it);
        cout << "Key 4 erased by iterator.\n";
    }

    // 11. Clear the map
    map<int, string> tempMap = myMap; // Backup for demonstration
    myMap.clear();
    cout << "Map cleared.\n";

    // 12. Check if map is empty
    if (myMap.empty()) {
        cout << "Map is empty.\n";
    }

    // 13. Swap two maps
    myMap.swap(tempMap);
    cout << "Swapped maps. Current map contents:\n";
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 14. Lower bound (returns iterator >= key)
    auto lower = myMap.lower_bound(5);
    if (lower != myMap.end()) {
        cout << "Lower bound for key 5: " << lower->first << " -> " << lower->second << endl;
    }

    // 15. Upper bound (returns iterator > key)
    auto upper = myMap.upper_bound(5);
    if (upper != myMap.end()) {
        cout << "Upper bound for key 5: " << upper->first << " -> " << upper->second << endl;
    }

    // 16. Equal range (returns a pair of iterators for lower and upper bounds)
    auto range = myMap.equal_range(5);
    cout << "Equal range for key 5:\n";
    if (range.first != myMap.end()) {
        cout << "Lower bound: " << range.first->first << " -> " << range.first->second << endl;
    }
    if (range.second != myMap.end()) {
        cout << "Upper bound: " << range.second->first << " -> " << range.second->second << endl;
    }

    // 17. Size and max_size
    cout << "Size of map: " << myMap.size() << endl;
    cout << "Maximum size of map: " << myMap.max_size() << endl;

    // 18. Key comparison
    auto keyComp = myMap.key_comp();
    cout << "Key comparison (is 3 < 5?): " << keyComp(3, 5) << endl;

    // 19. Value comparison
    auto valueComp = myMap.value_comp();
    cout << "Value comparison (is pair(3, 'Three') < pair(5, 'Five')?): ";
    if (valueComp(*myMap.find(3), *myMap.find(5))) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}

// Element with key 6: Six
// Element with key 4: Four
// Found key 3 with value: Three
// Count of key 2: 1       
// Iterating through map:  
// 1: One
// 2: Two
// 3: Three
// 4: Four
// 5: Five
// 6: Six
// Key 2 erased.
// Key 4 erased by iterator.
// Map cleared.
// Map is empty.
// Swapped maps. Current map contents:
// 1: One
// 3: Three
// 5: Five
// 6: Six
// Lower bound for key 5: 5 -> Five
// Upper bound for key 5: 6 -> Six
// Equal range for key 5:  
// Lower bound: 5 -> Five  
// Upper bound: 6 -> Six   
// Size of map: 4
// Maximum size of map: 128102389400760775
// Key comparison (is 3 < 5?): 1
// Value comparison (is pair(3, 'Three') < pair(5, 'Five')?): True