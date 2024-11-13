// 1. The Rule of Five (C++11):
// The Rule of Five is an extension of the Rule of Three introduced in C++11. It suggests that if your class defines one of the special member functions for resource management, it is likely to need all five of the following special functions(destructor, copy constructor, copy assignment operator, move copy constructor, move copy assignment) :
 
//    - Extension of Rule of Three
//    - Required when class manages resources

// 2. Five Special Member Functions:
//    a) Destructor
//       - Cleans up owned resources
//       - Called when object goes out of scope

//    b) Copy Constructor
//       - Creates new object as copy
//       - Performs deep copy for resources

//    c) Copy Assignment Operator
//       - Assigns between initialized objects
//       - Handles proper resource management
//       - Prevents shallow copying/double frees

//    d) Move Constructor (C++11)
//       - Transfers resource ownership
//       - Optimizes function returns
//       - Avoids unnecessary copying

//    e) Move Assignment Operator (C++11)
//       - Transfers ownership during assignment
//       - Similar to move constructor

// 3. Purpose:
//    - Optimizes performance with move semantics
//    - Essential for classes with dynamic resources
//    - Ensures efficient resource transfer
//    - Prevents unnecessary copying

#include <iostream>
#include <cstring>

using namespace std;

class RuleOfFive {
private:
    char* data;

public:
    // Constructor
    RuleOfFive(const char* str) {
        data = new char[strlen(str) + 1];  // strlen is defined in <cstring>
        strcpy(data, str);
    }

    // Destructor
    ~RuleOfFive() {
        delete[] data;
    }

    // Copy Constructor
    RuleOfFive(const RuleOfFive& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy Assignment Operator
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (this != &other) {
            delete[] data;  // Free the existing resource
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move Constructor
    RuleOfFive(RuleOfFive&& other) noexcept : data(other.data) {
        other.data = nullptr;  // Leave the moved-from object in a valid state
    }

    // Move Assignment Operator
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (this != &other) {
            delete[] data;  // Free the existing resource
            data = other.data;
            other.data = nullptr;  // Leave the moved-from object in a valid state
        }
        return *this;
    }

    // Method to display data
    void display() const {
        cout << data << endl;
    }
};

int main() {
    RuleOfFive obj1("Hello, world!");  // Constructor
    RuleOfFive obj2 = obj1;             // Copy constructor
    RuleOfFive obj3("Temp");
    obj3 = obj1;                        // Copy assignment

    RuleOfFive obj4 = move(obj1);  // Move constructor
    RuleOfFive obj5("Another string");
    obj5 = move(obj4);             // Move assignment

    obj2.display(); // Outputs: Hello, world!
    obj3.display(); // Outputs: Hello, world!
    obj5.display(); // Outputs: Hello, world!

    return 0;
}

// Hello, world!
// Hello, world!
// Hello, world!

