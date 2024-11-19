// weak_ptr in C++

// • std::weak_ptr is a smart pointer in C++ that is part of the <memory> header and works alongside std::shared_ptr.
// • It provides a non-owning reference to a resource managed by a std::shared_ptr.
// • The key advantage of std::weak_ptr is that it avoids cyclic dependencies in shared ownership scenarios.

// Key Characteristics:
// • Non-Owning: Does not contribute to the reference count of the managed object.
// • Cyclic Dependency Resolution: Helps break circular references that occur with std::shared_ptr.
// • Requires Locking: To access the managed object, std::weak_ptr must be converted to std::shared_ptr using lock().

// How It Works:
// • A std::weak_ptr is initialized from a std::shared_ptr.
// • The std::weak_ptr keeps a "weak reference" to the resource, which does not affect the resource's lifecycle.
// • If the resource is destroyed (when the last owning std::shared_ptr is destroyed), the std::weak_ptr becomes expired.

#include <iostream>
#include <memory>

using namespace std;

class Resource {
public:
    Resource() { cout << "Resource Acquired\n"; }
    ~Resource() { cout << "Resource Released\n"; }
};

int main() {
    shared_ptr<Resource> sharedRes = make_shared<Resource>();
    weak_ptr<Resource> weakRes(sharedRes); // Create weak_ptr from shared_ptr

    if (auto lockedRes = weakRes.lock()) { // Convert weak_ptr to shared_ptr
        cout << "Resource is still available.\n";
    } else {
        cout << "Resource is no longer available.\n";
    }

    sharedRes.reset(); // Destroy the resource
    if (auto lockedRes = weakRes.lock()) {
        cout << "Resource is still available.\n";
    } else {
        cout << "Resource is no longer available.\n";
    }

    return 0;
}

// Resource Acquired
// Resource is still available.
// Resource Released
// Resource is no longer available.


// Breaking Circular References

// Problem with std::shared_ptr
// When two objects hold std::shared_ptr references to each other, they create a circular dependency, preventing proper deallocation.

#include <iostream>
#include <memory>

using namespace std;
class B; // Forward declaration

class A {
public:
    shared_ptr<B> bptr; // Shared reference to B
    ~A() { cout << "A destroyed\n"; }
};

class B {
public:
    shared_ptr<A> aptr; // Shared reference to A
    ~B() { cout << "B destroyed\n"; }
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->bptr = b;
    b->aptr = a;

    // Memory leak occurs because of cyclic dependency
    return 0;
}

// Solution with std::weak_ptr
// Using std::weak_ptr, we can break the circular dependency:


#include <iostream>
#include <memory>

using namespace std;

class B; // Forward declaration

class A {
public:
    weak_ptr<B> bptr; // Weak reference to B
    ~A() { cout << "A destroyed\n"; }
};

class B {
public:
    shared_ptr<A> aptr; // Shared reference to A
    ~B() { cout << "B destroyed\n"; }
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->bptr = b;
    b->aptr = a;

    // Proper destruction occurs
    return 0;
}

// B destroyed
// A destroyed


// Advantages of std::weak_ptr
// Prevents Memory Leaks: Solves cyclic dependency problems that occur with std::shared_ptr.
// Efficient Memory Management: Ensures resources are properly released when no longer needed.
// Non-Intrusive: Does not affect the resource's lifetime.

// Limitations
// Not Owning: Cannot directly access or modify the resource without converting to std::shared_ptr.
// Requires Careful Use: Accessing an expired std::weak_ptr using lock() can lead to runtime errors if not checked.

// Best Practices
// Use std::weak_ptr when:
// You need a temporary or optional reference to a shared resource.
// You want to avoid circular dependencies between std::shared_ptr instances.
// Always check expired() or the result of lock() before accessing the resource.