// next : Returns an iterator that is advanced by a specified number of positions from the given iterator without modifying the original iterator.
// advance : Advances the given iterator by a specified number of positions but modifies the original iterator.

#include <iostream>
#include <vector>
#include <list>
#include <iterator> 

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // Using std::next
    auto it = vec.begin();
    auto nextIt = next(it, 2); // Advance the iterator by 2 positions (non-modifying)
    cout << "Element at position 2 using std::next: " << *nextIt << endl;

    // Using std::advance
    advance(it, 3); // Advance the iterator by 3 positions (modifies `it`)
    cout << "Element after advancing iterator by 3 using std::advance: " << *it << endl;

    // Example with std::list
    list<int> lst = {5, 15, 25, 35, 45};

    // Using std::next
    auto listIt = lst.begin();
    auto listNextIt = next(listIt, 4); // Advance by 4 positions
    cout << "Element at position 4 in list using std::next: " << *listNextIt << endl;

    // Using std::advance
    advance(listIt, 2); // Advance by 2 positions
    cout << "Element after advancing iterator in list by 2 using std::advance: " << *listIt << endl;

    // Demonstrating negative advancement
    listIt = lst.end();
    advance(listIt, -3); // Move back by 3 positions
    cout << "Element after moving back by 3 positions using std::advance: " << *listIt << endl;

    return 0;
}
