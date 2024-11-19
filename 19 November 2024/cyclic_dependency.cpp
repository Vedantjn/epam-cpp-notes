
#include <iostream>
#include <memory>
using namespace std;

// Forward declarations
class B;
class A {
public:
    shared_ptr<B> b_ptr;
    ~A() { cout << "A destroyed\n"; }
};

class B {
public:
    weak_ptr<A> a_ptr;  // Using weak_ptr to break the cycle
    ~B() { cout << "B destroyed\n"; }
};

int main() {
    // Create shared_ptr of A
    shared_ptr<A> a = make_shared<A>();

    // Create shared_ptr of B
    shared_ptr<B> b = make_shared<B>();

    // Create circular reference
    a->b_ptr = b;
    b->a_ptr = a;

    cout << "a use count: " << a.use_count() << endl;
    cout << "b use count: " << b.use_count() << endl;

    return 0;
}
