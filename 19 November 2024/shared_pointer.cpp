// shared_ptr
// • std::shared_ptr is a smart pointer that allows shared ownership of a dynamically allocated resource. Multiple std::shared_ptr instances can own the same resource, and the resource is destroyed when the last std::shared_ptr owning it is destroyed.

// Key Features:
// • Shared Ownership: Multiple std::shared_ptr objects can own the same resource.
// • Reference Counting: Maintains a reference count to track the number of owners.
// • Automatic Deletion: Deletes the resource when the last owner goes out of scope.

#include <iostream>
#include <memory> // For std::shared_ptr

using namespace std;

int main() {
    // Create a shared_ptr
    shared_ptr<int> sptr1 = make_shared<int>(42);
    cout << "Value: " << *sptr1 << "\n";

    // Share ownership with another shared_ptr
    shared_ptr<int> sptr2 = sptr1;
    cout << "Value from sptr2: " << *sptr2 << "\n";

    shared_ptr<int> sptr3 = sptr1;

    // Check reference count
    cout << "Reference count: " << sptr1.use_count() << "\n";

    return 0; // Resource is destroyed after the last shared_ptr is destroyed
}
