// Iterator invalidation in C++ refers to the situation where iterators become invalid because of changes made to the container they are iterating over. 

// - When an iterator is invalidated, using it further can lead to undefined behavior. 
// - The invalidation typically happens when the underlying container's structure changes, such as through insertions, deletions, or resizing.

#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    auto it = vec.begin(); // Points to 1

    vec.push_back(4); // May reallocate
    // Now `it` might be invalidated.

    cout << *it; // Undefined behavior if `it` is invalidated
    return 0;
}

// --------------------------------------------

// Revalidate Iterators: If an operation might invalidate iterators, get new valid iterators after the operation.
// Avoid Storing Iterators: Minimize long-term storage of iterators when modifying containers.
// Use Stable Containers: If you need stable iterators, consider using std::list or std::map.

#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    auto it = vec.begin(); // Points to 1

    vec.push_back(4); // May reallocate
    // Now `it` might be invalidated.

    // Demonstrating iterator invalidation
    cout << "Value before potential invalidation: " << *it << endl; // Undefined behavior if `it` is invalidated

    // Revalidate the iterator after modification
    it = vec.begin(); // Reassign `it` to a valid iterator
    cout << "Value after revalidation: " << *it << endl; // Now it is safe to use

    return 0;
}

// -------------------------------------

// For deque, list, insertion won't be invalidated, since it is not contigous memory.

// List
// Inserting elements does not invalidate iterators, as the memory for existing elements remains unaffected (linked lists do not store data contiguously).
// Deleting an element invalidates the iterator pointing to that element, but other iterators remain valid.

// Deque
// Iterators remain valid if no reallocation occurs (reallocation happens when the internal block structure changes).
// Deques are not stored in a single contiguous block of memory but in multiple smaller blocks, so front/back operations do not always affect iterators.