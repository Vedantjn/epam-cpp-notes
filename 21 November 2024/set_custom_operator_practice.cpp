#include <iostream>
#include <set>
using namespace std;

class MyClass {
public:
    int value;

    MyClass(int v) : value(v) {}

    // Define the '<' operator for ordering
    bool operator<(const MyClass& other) const {
        return value < other.value; // Order by the value member
    }
};

int main() {
    // Declare a set of MyClass objects
    set<MyClass> st;

    // Insert objects into the set
    st.insert(MyClass(5));
    st.insert(MyClass(1));
    st.insert(MyClass(3));

    // Display the set elements
    for (const auto& obj : st) {
        cout << obj.value << " ";
    }

    return 0;
}

// 1 3 5 