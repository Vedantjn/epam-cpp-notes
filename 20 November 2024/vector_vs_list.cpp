#include <iostream>
#include <vector>
#include <list>

using namespace std;

void compareVectorAndList() {
    // Vectors are dynamic arrays that provide fast access to elements,
    // while lists are doubly linked lists that allow for efficient insertions and deletions.

    // Vectors have a contiguous memory allocation which makes them cache-friendly,
    // whereas lists have non-contiguous memory allocation which can lead to more cache misses.
    
    // Additionally, vectors are generally faster for accessing elements by index,
    // while lists excel in scenarios where frequent insertions and deletions occur.

    // Using a vector
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector elements: ";
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    // Using a list
    list<int> lst = {1, 2, 3, 4, 5};
    cout << "List elements: ";
    for (const auto& elem : lst) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    compareVectorAndList();
    return 0;
}

// Vector elements: 1 2 3 4 5 
// List elements: 1 2 3 4 5