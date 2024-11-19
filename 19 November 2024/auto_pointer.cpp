// Auto Pointer in C++

// 1. Definition:
//      - std::auto_ptr was a smart pointer in C++98 standard
//      - Manages lifecycle of dynamically allocated objects
//      - Automatically deletes managed object when out of scope
//      - Deprecated in C++11 and removed in C++17

// 2. Key Features of std::auto_ptr:
//      - Automatic Ownership
//        * Auto-deletes managed object when out of scope
//      - Transfer of Ownership
//        * Ownership transfers to new auto_ptr during assignment
//        * Old auto_ptr becomes nullptr after transfer

// 3. Usage:

#include <iostream>
#include <memory> // For auto_ptr (deprecated in modern C++)

using namespace std;

int main() {
    auto_ptr<int> p1(new int(10));  // Dynamically allocate memory
    cout << "p1 points to: " << *p1 << "\n";

    auto_ptr<int> p2 = p1;          // Ownership transferred to p2
    cout << "p2 points to: " << *p2 << "\n";

    // p1 no longer owns the memory
    if (p1.get() == nullptr) {
        cout << "p1 is now null.\n";
    }

    return 0;
}

// 4. Limitations:
//      - Ownership Transfer Issues
//        * Transfers ownership during assignment/copying
//        * Can lead to unexpected behavior and bugs
//        * Example:
        //  auto_ptr<int> p1(new int(20));
        //  auto_ptr<int> p2 = p1;  // Ownership transferred to p2
        //  cout << *p1;           // Undefined behavior! p1 is now null
//      - No Array Support
//        * Cannot manage arrays properly
//        * Special handling needed for memory deallocation

// 5. Deprecation and Replacement:
//      - C++11 Deprecation
//        * Introduced std::unique_ptr and std::shared_ptr
//        * unique_ptr provides exclusive ownership
//        * shared_ptr enables shared ownership with reference counting
//      - C++17 Removal
//        * Completely removed from the standard
//        * Encourages use of modern, safer alternatives