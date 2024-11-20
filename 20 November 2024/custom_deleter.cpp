// 1. Custom deleters in C++ provide control over resource cleanup when smart pointers go out of scope.

// 2. Key features:
//    - Define specific cleanup logic for dynamically allocated resources
//    - Work with std::unique_ptr and std::shared_ptr
//    - Handle memory, file handles, sockets, and other resources

// 3. Use cases:
//    - Managing non-standard resource types
//    - Implementing custom cleanup requirements
//    - Ensuring proper resource deallocation

// 4. Benefits:
//    - Automatic resource management
//    - Prevention of resource leaks
//    - Clean and maintainable code

// Why Use a Custom Deleter?
// Custom Resource Management:

// Clean up resources other than memory, such as file handles, network sockets, or mutexes.
// Integration with Non-standard APIs:

// Handle APIs that require special cleanup procedures.
// Logging or Debugging:

// Log resource deallocation for debugging purposes.
// Avoiding Memory Leaks:

// Ensure proper cleanup in complex scenarios.

#include <iostream>
#include <memory>

using namespace std;

void c_del(int* ptr) {
    cout << "Custom deleter called for integer array\n";
    delete[] ptr;
}

class BB {
public:
    BB() {
        cout << "BB's Constructor called\n";
    }

    ~BB() {
        cout << "BB's Destructor called\n";
    }
};

void bb_del(BB* ptr) {
    cout << "Custom deleter called for BB array\n";
    delete[] ptr;
}

int main() {
    unique_ptr<int[], decltype(&c_del)> ptr1(new int[10], c_del);
    ptr1[0] = 3; 
    ptr1[9] = 42;
    cout << "ptr1[0] = " << ptr1[0] << ", ptr1[9] = " << ptr1[9] << "\n";

    unique_ptr<BB[], decltype(&bb_del)> ptr2(new BB[3], bb_del);
    cout << "BB array is being managed by ptr2\n";

    return 0;
}


// -----------------------------------------------

#include <iostream>
#include <memory>
#include <cstdio>
using namespace std;

// Custom deleter to close a file
void close_file(FILE* file) {
    cout << "Closing file...\n";
    fclose(file);
}
 
int main() {
    // Open a file and manage it with a unique_ptr and custom deleter
    unique_ptr<FILE, decltype(&close_file)> file(fopen("example.txt", "w"), close_file);
 
    // Use the file (writing, etc.)
    if (file) {
        fprintf(file.get(), "Hello, World!");
    }
 
    // The file will be automatically closed when file goes out of scope
    return 0;
}