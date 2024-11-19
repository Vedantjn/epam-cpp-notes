// 1. std::unique_ptr
//    - Smart pointer in C++ providing exclusive ownership of dynamically allocated resources
//    - Ensures exactly one owner of the resource at any time

// 2. Key Features:
//    - Exclusive Ownership: Only one std::unique_ptr can own the resource
//    - Non-Copyable: Cannot be copied but can be moved using std::move
//    - Automatic Deletion: Automatically deletes managed object when going out of scope

// 3. std::make_unique (C++14 and later)
//    - Factory function that creates a unique_ptr
//    - Safer than raw new as it prevents memory leaks in expressions
//    - Exception safe memory allocation
//    - Syntax: auto ptr = make_unique<Type>(args...);

#include<iostream>
#include<memory>
using namespace std;

int main(){
    
    // Old way using new
    unique_ptr<int> uptr(new int(43));
    cout << "Value : " << *uptr << endl;

    // Modern way using make_unique
    auto uptr1 = make_unique<int>(100);
    cout << "Value from make_unique: " << *uptr1 << endl;

    // with array
    auto arr = make_unique<int[]>(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    cout << "Array values: " << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    unique_ptr<int> uptr2 = move(uptr);

    cout << "Value uptr2 move: " << *uptr2 << endl;
    if(!uptr) {
        cout << "uptr is now null after transfer" << endl;
    }

    cout << "Value after transfer: " << *uptr2 << endl;

    return 0;
}

// Advantages:
// Efficiency: No reference counting overhead.
// Safety: Prevents memory leaks as the destructor automatically deletes the resource.
// make_unique provides exception safety and cleaner syntax.

// Disadvantages:
// Cannot be shared or copied, making it unsuitable for shared ownership scenarios.