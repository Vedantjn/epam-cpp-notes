// The std::set and std::map containers in C++ have an insert method, which returns a std::pair. This pair contains:

// First: An iterator pointing to either the newly inserted element or the element that prevented the insertion.
// Second: A bool value indicating whether the insertion was successful (true) or not (false).
// This behavior is because std::set and std::map ensure unique keys. 
// If you try to insert an element that already exists, the insertion will fail, and the existing element's iterator will be returned.

#include <iostream>
#include <set>
using namespace std;

int main() {
    // Declare a set of integers
    set<int> mySet;

    // Try inserting an element
    auto result1 = mySet.insert(10);
    // cout << result1 << endl;
    // Check the return value
    cout << "Inserted value: 10\n";
    cout << "Iterator points to: " << *result1.first << "\n";
    cout << "Insertion successful? " << (result1.second ? "Yes" : "No") << "\n";

    // Try inserting the same element again
    auto result2 = mySet.insert(10);

    // Check the return value again
    cout << "\nAttempting to insert duplicate value: 10\n";
    cout << "Iterator points to: " << *result2.first << "\n";
    cout << "Insertion successful? " << (result2.second ? "Yes" : "No") << "\n";

    return 0;
}

// Inserted value: 10
// Iterator points to: 10
// Insertion successful? Yes

// Attempting to insert duplicate value: 10
// Iterator points to: 10
// Insertion successful? No


#include <iostream>
#include <map>
using namespace std;

int main() {
    // Declare a map of integers to strings
    map<int, string> myMap;

    // Insert a key-value pair
    auto result1 = myMap.insert({1, "One"});

    cout << "Inserted key: 1 with value: 'One'\n";
    cout << "Iterator points to key: " << result1.first->first << ", value: " << result1.first->second << "\n";
    cout << "Insertion successful? " << (result1.second ? "Yes" : "No") << "\n";

    // Try inserting a duplicate key
    auto result2 = myMap.insert({1, "Duplicate"});

    cout << "\nAttempting to insert duplicate key: 1\n";
    cout << "Iterator points to key: " << result2.first->first << ", value: " << result2.first->second << "\n";
    cout << "Insertion successful? " << (result2.second ? "Yes" : "No") << "\n";

    return 0;
}

// Inserted key: 1 with value: 'One'
// Iterator points to key: 1, value: One
// Insertion successful? Yes

// Attempting to insert duplicate key: 1
// Iterator points to key: 1, value: One
// Insertion successful? No
