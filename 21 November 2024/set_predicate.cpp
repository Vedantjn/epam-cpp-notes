#include <iostream>
#include <set>

using namespace std;

// Custom comparator class
class myClass {
public:
    // Predicate function to order elements in descending order
    bool operator()(int a, int b) const {
        return a > b; // Descending order
    }
};

int main() {
    // Declare a set with custom comparator
    set<int, myClass> st;

    // Insert elements into the set
    st.insert(10);
    st.insert(20);
    st.insert(5);
    st.insert(15);

    // Output the contents of the set
    cout << "Elements in the set (custom ordering):" << endl;
    for (const auto& element : st) {
        cout << element << " ";
    }
    cout << endl;

    // Find an element in the set
    int key = 15;
    auto it = st.find(key);
    if (it != st.end()) {
        cout << "Element " << key << " found in the set." << endl;
    } else {
        cout << "Element " << key << " not found in the set." << endl;
    }

    // Erase an element
    st.erase(20);
    cout << "Element 20 erased from the set." << endl;

    // Output the updated set
    cout << "Updated set:" << endl;
    for (const auto& element : st) {
        cout << element << " ";
    }
    cout << endl;

    // Insert another element and check size
    st.insert(25);
    cout << "Size of the set: " << st.size() << endl;

    return 0;
}

// Elements in the set (custom ordering):
// 20 15 10 5 
// Element 15 found in the set.
// Element 20 erased from the set.
// Updated set:
// 15 10 5 
// Size of the set: 4