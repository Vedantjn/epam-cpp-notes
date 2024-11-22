#include <bits/stdc++.h>

using namespace std;

/*
 * Iterators in C++ STL
 * 
 * Iterators provide a way to traverse containers and access their elements. Different types of iterators
 * are designed for specific container types, allowing for functionality such as random access, bidirectional traversal, etc.
 * 
 * Key Iterator Types:
 * 1. iterator: Basic iterator for mutable containers.
 * 2. const_iterator: Read-only iterator.
 * 3. reverse_iterator: For reverse traversal.
 * 4. const_reverse_iterator: Read-only reverse traversal.
 * 5. Stream iterators: For input/output with streams.
 */

int main() {
    // 1. Example: set<int>::iterator
    set<int> mySet = {10, 20, 30};
    cout << "set<int> traversal using iterator:\n";
    for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // 2. Example: vector<int>::iterator
    vector<int> myVector = {1, 2, 3};
    cout << "vector<int> traversal using iterator:\n";
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // 3. Example: list<int>::iterator
    list<int> myList = {1, 2, 3};
    cout << "list<int> traversal using iterator:\n";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // 4. Example: map<int, string>::iterator
    map<int, string> myMap = {{1, "One"}, {2, "Two"}};
    cout << "map<int, string> traversal using iterator:\n";
    for (map<int, string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }
    cout << "\n";

    // 5. Example: multimap<int, string>::iterator
    multimap<int, string> myMultimap = {{1, "A"}, {1, "B"}, {2, "C"}};
    cout << "multimap<int, string> traversal using iterator:\n";
    for (multimap<int, string>::iterator it = myMultimap.begin(); it != myMultimap.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }
    cout << "\n";

    // 6. Example: deque<int>::iterator
    deque<int> myDeque = {1, 2, 3};
    cout << "deque<int> traversal using iterator:\n";
    for (deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // 7. Example: unordered_set<int>::iterator
    unordered_set<int> myUnorderedSet = {3, 1, 2};
    cout << "unordered_set<int> traversal using iterator:\n";
    for (unordered_set<int>::iterator it = myUnorderedSet.begin(); it != myUnorderedSet.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // 8. Special Case: priority_queue<int> does not support direct iteration
    priority_queue<int> myPQ;
    myPQ.push(3);
    myPQ.push(1);
    myPQ.push(2);
    cout << "priority_queue<int> traversal using top and pop:\n";
    while (!myPQ.empty()) {
        cout << myPQ.top() << " ";
        myPQ.pop();
    }
    cout << "\n\n";

    // 9. Example: const_iterator for read-only access
    cout << "set<int> traversal using const_iterator:\n";
    for (set<int>::const_iterator it = mySet.cbegin(); it != mySet.cend(); ++it) {
        cout << *it << " "; // Cannot modify *it
    }
    cout << "\n\n";

    // 10. Example: reverse_iterator for reverse traversal
    cout << "vector<int> traversal using reverse_iterator:\n";
    for (vector<int>::reverse_iterator rit = myVector.rbegin(); rit != myVector.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << "\n\n";

    // 11. Example: Stream iterators
    cout << "Input stream iterator example (enter integers, Ctrl+D to stop):\n";
    istream_iterator<int> in(cin), eos;
    vector<int> data(in, eos);

    cout << "Output stream iterator:\n";
    ostream_iterator<int> out(cout, " ");
    copy(data.begin(), data.end(), out);
    cout << "\n";

    return 0;
}

// set<int> traversal using iterator:
// 10 20 30

// vector<int> traversal using iterator:
// 1 2 3

// list<int> traversal using iterator:
// 1 2 3

// map<int, string> traversal using iterator:
// 1: One
// 2: Two

// multimap<int, string> traversal using iterator:
// 1: A
// 1: B
// 2: C

// deque<int> traversal using iterator:
// 1 2 3

// unordered_set<int> traversal using iterator:
// 2 1 3

// priority_queue<int> traversal using top and pop:
// 3 2 1

// set<int> traversal using const_iterator:
// 10 20 30

// vector<int> traversal using reverse_iterator:
// 3 2 1

// Input stream iterator example (enter integers, Ctrl+D to stop):
