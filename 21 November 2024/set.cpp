#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> st;

    // 1. Inserting elements
    st.insert(10);
    st.insert(20);
    st.insert(30);
    st.insert(20); // Duplicate elements are ignored
    cout << "Inserted elements 10, 20, 30 into the set.\n";

    // 2. Checking if an element exists using find
    if (st.find(20) != st.end()) {
        cout << "Element 20 found in the set.\n";
    } else {
        cout << "Element 20 not found in the set.\n";
    }

    // 3. Erasing an element by value
    st.erase(10);
    cout << "Element 10 erased from the set.\n";

    // 4. Erasing an element by iterator
    auto it = st.find(20);
    if (it != st.end()) {
        st.erase(it);
        cout << "Element 20 erased using an iterator.\n";
    }

    // 5. Iterating through the set
    cout << "Elements in the set: ";
    for (const auto& element : st) {
        cout << element << " ";
    }
    cout << endl;

    // 6. Getting the size of the set
    cout << "Size of the set: " << st.size() << endl;

    // 7. Clearing the set
    st.clear();
    cout << "Set cleared.\n";

    // 8. Checking if the set is empty
    if (st.empty()) {
        cout << "Set is empty.\n";
    }

    // 9. Inserting multiple elements using initializer list
    st.insert({40, 50, 60});
    cout << "Inserted elements 40, 50, 60 into the set.\n";

    // 10. Lower bound
    auto lower = st.lower_bound(50); // First element >= 50
    if (lower != st.end()) {
        cout << "Lower bound for 50: " << *lower << endl;
    }

    // 11. Upper bound
    auto upper = st.upper_bound(50); // First element > 50
    if (upper != st.end()) {
        cout << "Upper bound for 50: " << *upper << endl;
    }

    // 12. Maximum size
    cout << "Maximum size of the set: " << st.max_size() << endl;

    // 13. Swapping two sets
    set<int> anotherSet = {70, 80};
    st.swap(anotherSet);
    cout << "Swapped the set with another set containing {70, 80}.\n";

    cout << "Current elements in st: ";
    for (const auto& element : st) {
        cout << element << " ";
    }
    cout << endl;

    // 14. Count method (always returns 0 or 1 in std::set)
    int count = st.count(70);
    cout << "Count of element 70: " << count << endl;

    // 15. Equal range (returns a pair of iterators: lower_bound and upper_bound)
    st = {100, 200, 300}; // Reset set
    auto range = st.equal_range(200);
    cout << "Equal range for 200: ";
    if (range.first != st.end()) {
        cout << "Lower bound: " << *range.first << " ";
    }
    if (range.second != st.end()) {
        cout << "Upper bound: " << *range.second << endl;
    }

    // 16. Emplace method (directly constructs elements in-place)
    st.emplace(400);
    st.emplace(300); // Duplicate, will be ignored
    cout << "After emplace, elements in st: ";
    for (const auto& element : st) {
        cout << element << " ";
    }
    cout << endl;

    // 17. Key comparison function
    auto keyComp = st.key_comp();
    cout << "Comparing 200 and 300 using key_comp: ";
    if (keyComp(200, 300)) {
        cout << "200 is less than 300.\n";
    } else {
        cout << "200 is not less than 300.\n";
    }

    // 18. Value comparison function
    auto valueComp = st.value_comp();
    cout << "Comparing 200 and 300 using value_comp: ";
    if (valueComp(200, 300)) {
        cout << "200 is less than 300.\n";
    } else {
        cout << "200 is not less than 300.\n";
    }

    return 0;
}

// Inserted elements 10, 20, 30 into the set.
// Element 20 found in the set.
// Element 10 erased from the set.
// Element 20 erased using an iterator.
// Elements in the set: 30
// Size of the set: 1
// Set cleared.
// Set is empty.
// Inserted elements 40, 50, 60 into the set.
// Lower bound for 50: 50
// Upper bound for 50: 60
// Maximum size of the set: 230584300921369395
// Swapped the set with another set containing {70, 80}.      
// Current elements in st: 70 80
// Count of element 70: 1
// Equal range for 200: Lower bound: 200 Upper bound: 300     
// After emplace, elements in st: 100 200 300 400
// Comparing 200 and 300 using key_comp: 200 is less than 300.
// Comparing 200 and 300 using value_comp: 200 is less than 300.