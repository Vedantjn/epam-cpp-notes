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

// For std::list and std::forward_list, insertion never invalidates iterators, and for 
// std::deque, insertion/deletion at the front or back may preserve iterator validity, 
// provided no reallocation occurs. For middle operations in std::deque, however, iterators 
// may become invalid.

// This behavior arises because std::list is a linked list, and std::deque stores elements 
// in a block-wise, non-contiguous manner.

// Reallocation in std::vector, std::deque, or std::unordered_map is the primary cause of iterator invalidation during insertion.
// Node-based containers (std::list, std::set, etc.) are generally safer with respect to iterator validity.

// Container                               Insertion                                                                    Deletion
// std::vector                             May invalidate all iterators (reallocation) or iterators after insertion.    Iterators after deletion are invalidated.
// std::deque                              Front/back: usually safe; middle: iterators after may be invalid.            Iterators after deletion are invalidated.
// std::list                               Iterators are never invalidated.                                             Only the iterator pointing to the deleted element is invalidated.
// std::set, std::multiset                 Iterators are never invalidated.                                             Only the iterator pointing to the deleted element is invalidated.
// std::map, std::multimap                 Iterators are never invalidated.                                             Only the iterator pointing to the deleted element is invalidated.
// std::unordered_map, std::unordered_set  Safe unless rehashing occurs.                                                Only the iterator pointing to the deleted element is invalidated.