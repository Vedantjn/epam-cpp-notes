// Deep Copy vs Shallow Copy

// 1. Shallow Copy
// • Definition: Copies references/pointers only, not actual data
// • Creates bitwise copy of object's fields
// • Shares same memory locations

// 2. Key Characteristics of Shallow Copy
// • Shares memory with original object
// • Changes affect both objects
// • Default copy behavior in C++

// 3. Shallow Copy Advantages
// • Faster execution
// • Simple implementation
// • Direct field value copying

// 4. Shallow Copy Disadvantages
// • Resource sharing issues
// • Risk of double deletion
// • Memory management problems


#include <iostream>
#include <cstring>

using namespace std;

class ShallowCopy {
    char* data;
public:
    ShallowCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    ~ShallowCopy() {
        delete[] data; // Releases the memory
    }
    void display() const {
        cout << "Data: " << data << "\n";
    }
};

int main() {
    ShallowCopy obj1("Hello");
    ShallowCopy obj2 = obj1; // Default copy constructor (shallow copy)

    obj1.display();
    obj2.display(); // Shares the same memory as `obj1`
    return 0; // Double deletion occurs, leading to a crash
}


// 1. Deep Copy
// • Definition: Duplicates both object and its data
// • Creates independent copy
// • Allocates new memory

// 2. Key Characteristics of Deep Copy
// • Independent memory allocation
// • Changes don't affect original
// • Requires custom implementation

// 3. Deep Copy Advantages
// • Complete independence
// • Safe memory management
// • No resource sharing issues

// 4. Deep Copy Disadvantages
// • Slower performance
// • Complex implementation
// • More memory usage

// # Implementation Requirements
// • Shallow Copy: Uses default compiler behavior
// • Deep Copy: Needs custom copy constructors/operators

// # Best Use Cases
// • Shallow Copy: Simple objects, intentional sharing
// • Deep Copy: Resource-managing objects, independence needed

#include <iostream>
#include <cstring>

class DeepCopy {
    char* data;
public:
    DeepCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Custom copy constructor
    DeepCopy(const DeepCopy& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~DeepCopy() {
        delete[] data; // Releases the memory
    }

    void display() const {
        cout << "Data: " << data << "\n";
    }
};

int main() {
    DeepCopy obj1("Hello");
    DeepCopy obj2 = obj1; // Custom copy constructor (deep copy)

    obj1.display();
    obj2.display(); // Independent copy of `obj1`
    return 0;
}