// shared_ptr
// • std::shared_ptr is a smart pointer that allows shared ownership of a dynamically allocated resource. Multiple std::shared_ptr instances can own the same resource, and the resource is destroyed when the last std::shared_ptr owning it is destroyed.

// Key Features:
// • Shared Ownership: Multiple std::shared_ptr objects can own the same resource.
// • Reference Counting: Maintains a reference count to track the number of owners.
// • Automatic Deletion: Deletes the resource when the last owner goes out of scope.

// make_shared:
// • std::make_shared is the recommended way to create a shared_ptr
// • It allocates memory for both the object and the control block in a single allocation
// • More efficient than using shared_ptr constructor which requires two allocations
// • Syntax: auto ptr = std::make_shared<Type>(constructor arguments);

#include <iostream>
#include <memory> // For std::shared_ptr

using namespace std;

class Person {
public:
    Person(string n, int a) : name(n), age(a) {
        cout << "Person created\n";
    }
    ~Person() {
        cout << "Person destroyed\n";
    }
    string name;
    int age;
};

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

    // make_shared with a class
    auto person = make_shared<Person>("Vedant", 22);
    cout << "Person name: " << person->name << ", age: " << person->age << "\n";
    cout << "Person reference count: " << person.use_count() << "\n";

    // Share the Person object
    auto person2 = person;
    cout << "Person reference count after sharing: " << person.use_count() << "\n";

    return 0; // Resource is destroyed after the last shared_ptr is destroyed
}

// Advantages:
// Allows multiple ownership, making it suitable for shared resources.
// Automatically deallocates the resource when the last owner is destroyed.

// Disadvantages:
// Overhead: Reference counting adds a slight performance overhead.
// Cyclic References: If std::shared_ptr objects form a cyclic reference, the memory may not be freed. Use std::weak_ptr to solve this issue.