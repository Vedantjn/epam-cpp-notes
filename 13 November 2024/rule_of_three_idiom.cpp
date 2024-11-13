// 1. The Rule of Three in C++ is a fundamental guideline for classes that manage resources, such as dynamic memory or file handles. It states that if a class needs to implement one of the following special member functions, it likely needs to implement all three(copy constructor, copy assignment, destructor) :

// 2. Special Member Functions:
//    - Destructor: The class needs a destructor to clean up resources it allocates during its lifetime (e.g., freeing memory with delete or closing a file).
//    - Copy Constructor: The class needs a copy constructor if it needs to handle the copying of an object correctly, especially when dealing with resources. A shallow copy (the default copy constructor) can cause issues like double deletion (when both the original and the copy try to free the same memory).
//    - Copy Assignment Operator: The class also needs a copy assignment operator to correctly handle assignment of one object to another, ensuring proper resource management.

// 3. Detailed Explanation:
//    - Destructor: The destructor is responsible for releasing resources acquired by the object. If a class allocates memory or other resources (like file handles or sockets), the destructor ensures that they are freed when the object is destroyed.
//    - Copy Constructor: If you define a custom copy constructor, it should create a deep copy of any dynamically allocated resources, ensuring the copied object has its own separate copy of the resource, not just a pointer to the original resource.
//    - Copy Assignment Operator: Similar to the copy constructor, the copy assignment operator handles the assignment of one object to another. It must ensure that any existing resources in the destination object are freed before the resources from the source object are copied over.

#include <bits/stdc++.h>
using namespace std;

class RuleOfThree {
private:
    int* data;

public:
    // Constructor
    RuleOfThree(int value) : data(new int(value)) {}

    // Destructor
    ~RuleOfThree() {
        delete data;  // Free the allocated memory
    }

    // Copy Constructor (deep copy)
    RuleOfThree(const RuleOfThree& other) : data(new int(*other.data)) {}

    // Copy Assignment Operator (deep copy)
    RuleOfThree& operator=(const RuleOfThree& other) {
        if (this != &other) {  // Self-assignment check
            delete data;  // Free existing resource
            data = new int(*other.data);  // Allocate new memory and copy data
        }
        return *this;
    }

    // Method to get data
    int getData() const {
        return *data;
    }
};

int main() {
    RuleOfThree obj1(10);  // Create an object with data 10
    RuleOfThree obj2 = obj1;  // Copy constructor is called
    RuleOfThree obj3(5);
    obj3 = obj1;  // Copy assignment operator is called

    cout << "obj1 data: " << obj1.getData() << endl;
    cout << "obj2 data: " << obj2.getData() << endl;
    cout << "obj3 data: " << obj3.getData() << endl;

    return 0;
}


// obj1 data: 10
// obj2 data: 10
// obj3 data: 10


// Constructor: The constructor allocates memory for an integer.
// Destructor: The destructor ensures that the dynamically allocated memory is freed when the object is destroyed.
// Copy Constructor: It creates a deep copy of the object, ensuring that the data pointer points to a new memory location rather than just copying the pointer.
// Copy Assignment Operator: It first deletes the existing data in the current object and then allocates new memory, copying the value from the source object.