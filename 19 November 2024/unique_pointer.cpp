// 1. std::unique_ptr
//    - Smart pointer in C++ providing exclusive ownership of dynamically allocated resources
//    - Ensures exactly one owner of the resource at any time

// 2. Key Features:
//    - Exclusive Ownership: Only one std::unique_ptr can own the resource
//    - Non-Copyable: Cannot be copied but can be moved using std::move
//    - Automatic Deletion: Automatically deletes managed object when going out of scope

#include<iostream>
#include<memory>
using namespace std;

int main(){
    
    unique_ptr<int> uptr(new int(43));
    cout << "Value : " << *uptr << endl;

    unique_ptr<int> uptr2 = move(uptr);

    cout << "Value uptr2 move: " << *uptr2 << endl;
    if(!uptr) {
        cout << "uptr is now null after transfet" << endl;
    }

    cout << "Value after transfer: " << *uptr2 << endl;

    return 0;
}

// Advantages:
// Efficiency: No reference counting overhead.
// Safety: Prevents memory leaks as the destructor automatically deletes the resource.

// Disadvantages:
// Cannot be shared or copied, making it unsuitable for shared ownership scenarios.