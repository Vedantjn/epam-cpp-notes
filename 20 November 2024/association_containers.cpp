
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    // Map - ordered key-value pairs (Red-Black Tree)
    // Time: Insert/Delete/Search - O(log n), Space: O(n)
    map<string, int> scores;
    scores["Vedant"] = 95;
    scores["Vanshika"] = 89;
    scores["Samyak"] = 92;

    // Accessing map elements
    cout << "Map demonstration:\n";
    for (const auto& pair : scores) {  // Time: O(n)
        cout << pair.first << ": " << pair.second << endl;
    }

    // Set - ordered unique elements (Red-Black Tree)
    // Time: Insert/Delete/Search - O(log n), Space: O(n)
    set<int> uniqueNumbers;
    uniqueNumbers.insert(5);
    uniqueNumbers.insert(3);
    uniqueNumbers.insert(5); // Duplicate won't be added
    uniqueNumbers.insert(1);

    cout << "\nSet demonstration:\n";
    for (int num : uniqueNumbers) {  // Time: O(n)
        cout << num << " ";
    }
    cout << endl;

    // Unordered Map - hash table implementation
    // Time: Insert/Delete/Search - O(1) average, O(n) worst case
    // Space: O(n)
    unordered_map<string, double> prices;
    prices["apple"] = 0.99;
    prices["banana"] = 0.59;
    prices["orange"] = 0.79;

    cout << "\nUnordered Map demonstration:\n";
    for (const auto& item : prices) {  // Time: O(n)
        cout << item.first << ": $" << item.second << endl;
    }

    // Unordered Set - hash table of unique elements
    // Time: Insert/Delete/Search - O(1) average, O(n) worst case
    // Space: O(n)
    unordered_set<string> fruits;
    fruits.insert("apple");
    fruits.insert("banana");
    fruits.insert("apple"); // Duplicate won't be added
    fruits.insert("orange");

    cout << "\nUnordered Set demonstration:\n";
    for (const auto& fruit : fruits) {  // Time: O(n)
        cout << fruit << " ";
    }
    cout << endl;

    // Multimap - allows duplicate keys (Red-Black Tree)
    // Time: Insert/Delete/Search - O(log n), Space: O(n)
    multimap<string, int> grades;
    grades.insert({"Ved", 85});
    grades.insert({"Ved", 92});
    grades.insert({"Dev", 88});

    cout << "\nMultimap demonstration:\n";
    for (const auto& grade : grades) {  // Time: O(n)
        cout << grade.first << ": " << grade.second << endl;
    }

    return 0;
}