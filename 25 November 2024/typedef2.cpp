#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <tuple>

using namespace std;

// Typedefs for complex data types
typedef map<int, vector<tuple<int, char>>> MyMap;         // A map where values are vectors of tuples
typedef set<pair<int, string>> MySet;                    // A set of pairs (int, string)

int main() {
    // Example 1: Using typedef with map<int, vector<tuple<int, char>>>
    MyMap myMap;

    // Adding elements
    myMap[1].push_back(make_tuple(10, 'A'));
    myMap[1].push_back(make_tuple(20, 'B'));
    myMap[2].push_back(make_tuple(30, 'C'));

    cout << "Contents of MyMap:\n";
    for (const auto& [key, valueVec] : myMap) {
        cout << "Key: " << key << "\nValues:\n";
        for (const auto& [num, ch] : valueVec) {
            cout << "  (" << num << ", " << ch << ")\n";
        }
    }

    // Example 2: Using typedef with set<pair<int, string>>
    MySet mySet;

    // Adding elements
    mySet.insert({1, "One"});
    mySet.insert({2, "Two"});
    mySet.insert({3, "Three"});

    cout << "\nContents of MySet:\n";
    for (const auto& [num, str] : mySet) {
        cout << "(" << num << ", " << str << ")\n";
    }

    return 0;
}

// Contents of MyMap:
// Key: 1
// Values:
//   (10, A)
//   (20, B)
// Key: 2
// Values:
//   (30, C)

// Contents of MySet:
// (1, One)
// (2, Two)
// (3, Three)