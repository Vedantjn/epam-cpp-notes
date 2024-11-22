#include <iostream>
#include <set>

using namespace std;

int main() {
    // 1. Create a multiset
    multiset<int> myMultiset;

    // 2. Insert elements using insert()
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(10); // Duplicate allowed
    myMultiset.insert(30);

    // 3. Emplace elements (constructs in-place)
    myMultiset.emplace(40);
    myMultiset.emplace(50);

    // 4. Iterating through the multiset
    cout << "Contents of the multiset:\n";
    for (const auto& element : myMultiset) {
        cout << element << " ";
    }
    cout << endl;

    // 5. Access elements using find()
    auto it = myMultiset.find(20);
    if (it != myMultiset.end()) {
        cout << "Found element: " << *it << endl;
    }

    // 6. Count occurrences of an element
    cout << "Count of element 10: " << myMultiset.count(10) << endl;

    // 7. Equal range
    cout << "Equal range for element 10:\n";
    auto range = myMultiset.equal_range(10);
    for (auto itr = range.first; itr != range.second; ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    // 8. Erase elements by value
    myMultiset.erase(10);
    cout << "All elements with value 10 erased.\n";

    // 9. Erase by iterator
    it = myMultiset.find(30);
    if (it != myMultiset.end()) {
        myMultiset.erase(it);
        cout << "Element 30 erased by iterator.\n";
    }

    // 10. Check size and max_size
    cout << "Size of multiset: " << myMultiset.size() << endl;
    cout << "Maximum size of multiset: " << myMultiset.max_size() << endl;

    // 11. Check if multiset is empty
    if (myMultiset.empty()) {
        cout << "Multiset is empty.\n";
    } else {
        cout << "Multiset is not empty.\n";
    }

    // 12. Clear the multiset
    myMultiset.clear();
    cout << "Multiset cleared.\n";

    // 13. Swap with another multiset
    multiset<int> anotherMultiset = {70, 80, 90};
    myMultiset.swap(anotherMultiset);
    cout << "Swapped with another multiset. Contents of the current multiset:\n";
    for (const auto& element : myMultiset) {
        cout << element << " ";
    }
    cout << endl;

    // 14. Lower bound
    auto lower = myMultiset.lower_bound(80);
    if (lower != myMultiset.end()) {
        cout << "Lower bound for 80: " << *lower << endl;
    }

    // 15. Upper bound
    auto upper = myMultiset.upper_bound(80);
    if (upper != myMultiset.end()) {
        cout << "Upper bound for 80: " << *upper << endl;
    }

    // 16. Using cbegin and cend
    cout << "Using cbegin and cend:\n";
    for (auto it = myMultiset.cbegin(); it != myMultiset.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 17. Using rbegin and rend
    cout << "Using rbegin and rend:\n";
    for (auto it = myMultiset.rbegin(); it != myMultiset.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 18. Using crbegin and crend (constant reverse iteration)
    cout << "Using crbegin and crend:\n";
    for (auto it = myMultiset.crbegin(); it != myMultiset.crend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

// Contents of the multiset:
// 10 10 20 30 40 50       
// Found element: 20       
// Count of element 10: 2  
// Equal range for element 10:
// 10 10
// All elements with value 10 erased.
// Element 30 erased by iterator.
// Size of multiset: 3     
// Maximum size of multiset: 230584300921369395    
// Multiset is not empty.  
// Multiset cleared.       
// Swapped with another multiset. Contents of the current multiset:        
// 70 80 90
// Lower bound for 80: 80  
// Upper bound for 80: 90  
// Using cbegin and cend:  
// 70 80 90
// Using rbegin and rend:  
// 90 80 70
// Using crbegin and crend:
// 90 80 70