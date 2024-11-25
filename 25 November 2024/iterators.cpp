#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <numeric>
#include <algorithm> // For reverse, distance, advance

using namespace std;

void demonstrateIterators() {
    // Random Access Iterator
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Random Access Iterator: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Demonstrating random access operations
    auto randomAccessIt = vec.begin();
    randomAccessIt += 2; // Move iterator 2 positions ahead
    cout << "Random Access (vec.begin() + 2): " << *randomAccessIt << endl;

    // Distance between iterators
    cout << "Distance between vec.begin() and vec.end(): " << distance(vec.begin(), vec.end()) << endl;

    // Bidirectional Iterator
    list<int> lst = {10, 20, 30, 40, 50};
    cout << "Bidirectional Iterator: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Demonstrating bidirectional iterator methods
    auto bidirectionalIt = lst.end();
    --bidirectionalIt; // Move iterator back by one position
    cout << "Bidirectional (--lst.end()): " << *bidirectionalIt << endl;

    // Forward Iterator
    vector<int> forwardVec = {1, 2, 3, 4, 5};
    cout << "Forward Iterator: ";
    for (auto it = forwardVec.begin(); it != forwardVec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Demonstrating forward iterator with advance
    auto forwardIt = forwardVec.begin();
    advance(forwardIt, 3); // Move iterator 3 steps forward
    cout << "Forward Iterator (advance by 3): " << *forwardIt << endl;

    // Input Iterator
    cout << "Input Iterator: Enter numbers (Ctrl+D to end): ";
    istream_iterator<int> inputIt(cin), end;
    vector<int> inputVec(inputIt, end);
    for (auto it : inputVec) {
        cout << it << " ";
    }
    cout << endl;

    // Demonstrating input iterator's construction of a container
    cout << "Sum of input numbers: ";
    cout << accumulate(inputVec.begin(), inputVec.end(), 0) << endl;

    // Output Iterator
    cout << "Output Iterator: ";
    ostream_iterator<int> outputIt(cout, " ");
    for (int i = 1; i <= 5; ++i) {
        *outputIt = i;
    }
    cout << endl;

    // Demonstrating output iterator by writing to a container
    list<int> outputList;
    copy(vec.begin(), vec.end(), back_inserter(outputList)); // Back inserter as output iterator
    cout << "List after using back_inserter: ";
    for (auto it : outputList) {
        cout << it << " ";
    }
    cout << endl;

    // Reverse Iterator
    cout << "Reverse Iterator (vector): ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Demonstrating reverse iterator with distance
    auto reverseIt = vec.rbegin();
    advance(reverseIt, 2);
    cout << "Reverse Iterator (vec.rbegin() + 2): " << *reverseIt << endl;
}

int main() {
    demonstrateIterators();
    return 0;
}

// Random Access Iterator: 1 2 3 4 5 
// Random Access (vec.begin() + 2): 3
// Distance between vec.begin() and vec.end(): 5
// Bidirectional Iterator: 10 20 30 40 50
// Bidirectional (--lst.end()): 50
// Forward Iterator: 1 2 3 4 5
// Forward Iterator (advance by 3): 4
// Input Iterator: Enter numbers (Ctrl+D to end): 1
// 2
// 3
// 4^D
// 1 2 3 4
// Sum of input numbers: 10
// Output Iterator: 1 2 3 4 5
// List after using back_inserter: 1 2 3 4 5
// Reverse Iterator (vector): 5 4 3 2 1
// Reverse Iterator (vec.rbegin() + 2): 3



// Random Access Iterator (vector):
// Demonstrates basic traversal.
// Performs +=, distance, and direct indexing.

// Bidirectional Iterator (list):
// Traverses bidirectionally using ++ and --.
// Demonstrates moving backward using --.

// Forward Iterator (vector):
// Uses advance to move forward by a specific number of steps.
// Displays elements in the container.

// Input Iterator (istream_iterator):
// Reads values from the user and constructs a vector from the input stream.
// Demonstrates summing all input numbers.

// Output Iterator (ostream_iterator):
// Writes values to the output stream.
// Uses back_inserter to copy elements into a list.

// Reverse Iterator (vector):
// Traverses the vector in reverse order.
// Moves reverse iterators using advance.