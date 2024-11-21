// The initializer list STL in C++ refers to the std::initializer_list type, introduced in C++11, which allows containers and objects to be initialized using a brace-enclosed list of values.

// What is std::initializer_list?
// A lightweight proxy object that provides access to an array of objects.
// It allows convenient initialization of standard containers and user-defined classes with a fixed set of values.

// Key Features:
// 1. Automatic Type Deduction: The compiler automatically deduces the type of the elements.
// 2. Read-Only Access: Elements in an initializer list are constant and cannot be modified.
// 3. Efficient Initialization: Provides a compact and efficient way to initialize objects or containers.

// Syntax and Usage
// The std::initializer_list type is used as a parameter in constructors or functions to enable initialization with a list of values.

// Constructor Example with std::initializer_list

#include <iostream>
#include <initializer_list>

using namespace std;

class MyClass {
public:
    MyClass(initializer_list<int> values) {
        cout << "Initialized with values: ";
        for (auto val : values) {
            cout << val << " ";
        }
        cout << "\n";
    }
};

int main() {
    MyClass obj = {1, 2, 3, 4, 5}; // Brace-enclosed initialization
    return 0;
}

// Output:
// Initialized with values: 1 2 3 4 5

// Using std::initializer_list with STL Containers

#include<iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    // Vector initialization
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Vector: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << "\n";

    // Set initialization
    set<string> s = {"apple", "banana", "cherry"};
    cout << "Set: ";
    for (const auto& fruit : s) {
        cout << fruit << " ";
    }
    cout << "\n";

    // Map initialization
    map<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
    cout << "Map:\n";
    for (const auto& pair : m) {
        cout << pair.first << " -> " << pair.second << "\n";
    }

    return 0;
}

// // Output:
// // Vector: 1 2 3 4 5 
// // Set: apple banana cherry 
// // Map:
// // 1 -> one
// // 2 -> two
// // 3 -> three

// // std::initializer_list API
// // Key Methods:
// // 1. .begin(): Returns a pointer to the first element.
// // 2. .end(): Returns a pointer to one past the last element.
// // 3. .size(): Returns the number of elements in the initializer list.

#include <iostream>
#include <initializer_list>

using namespace std;

void printList(initializer_list<int> values) {
    cout << "List size: " << values.size() << "\n";
    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main() {
    printList({10, 20, 30, 40, 50});
    return 0;
}

// // Output:
// // List size: 5
// // 10 20 30 40 50

// // Advantages of std::initializer_list
// // 1. Simplifies the initialization of containers and custom types.
// // 2. Provides a clean and concise syntax.
// // 3. Eliminates the need for overloaded constructors for different parameter counts.

// // Limitations of std::initializer_list
// // 1. Read-Only: The elements of an initializer_list are immutable.
// // 2. Fixed Size: The size of an initializer list cannot be modified once created.
// // 3. Performance Overhead: In some cases, using initializer lists can involve unnecessary copies if not handled efficiently.

// // When to Use std::initializer_list?
// // 1. To create user-friendly constructors for custom types.
// // 2. When initializing containers with a predefined list of values.
// // 3. For lightweight and read-only data structures.

