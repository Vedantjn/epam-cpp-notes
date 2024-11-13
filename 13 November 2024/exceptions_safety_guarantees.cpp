// 1. No Guarantee
// In the no exception safety guarantee, there are no assurances about the state of the program or object if an exception is thrown. This could lead to partially modified or inconsistent states.

#include <iostream>
#include <vector>

class MyClass {
public:
    void riskyOperation() {
        // No exception handling here, just a risky division
        int x = 5, y = 0;
        int z = x / y;  // Division by zero, no guarantee provided
    }
};

int main() {
    MyClass obj;
    obj.riskyOperation();  // This may cause an undefined state
    return 0;
}

// If y is zero, this will cause a division-by-zero error. Since there's no exception handling, the program may terminate or exhibit undefined behavior.

// ---------------------------------------------------------------

// 2. Basic Guarantee
// The basic exception safety guarantee ensures that if an exception is thrown, no resources are leaked, and the program or object remains in a valid but possibly modified state.

// Example: If an exception occurs during a container operation, the container remains valid, but it might be partially modified.

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void addElement(vector<int>& vec, int value) {
    if (value < 0) throw invalid_argument("Negative value not allowed");
    vec.push_back(value);  // Basic guarantee: if push_back fails, no elements are leaked
}

int main() {
    vector<int> numbers = {1, 2, 3};
    try {
        addElement(numbers, -1);  // Throws exception, vector remains unchanged
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << '\n';
    }
    // Vector is still in a valid state even though the addition failed
    for (int num : numbers) {
        cout << num << " ";  // Output: 1 2 3
    }
    return 0;
}

// Caught exception: Negative value not allowed
// 1 2 3

// Here, vector provides the basic guarantee. If push_back throws, numbers remains valid, though it won’t contain the new element.

// ---------------------------------------------------------------

// 3. Strong Guarantee
// The strong exception safety guarantee (or "commit-or-rollback") ensures that if an exception is thrown, the program or object remains in the exact same state as before the operation began.

// This is commonly achieved through temporary copies or rollback mechanisms.

// Example with string (Copy and Swap Idiom)

#include <iostream>
#include <string>
using namespace std;

class StrongGuaranteeExample {
    string data;

public:
    StrongGuaranteeExample(const string& str) : data(str) {}

    void safeOperation(const string& newData) {
        string temp = newData;  // Create a temporary copy
        data = temp;                 // Only assign after temp is successful
    }

    void display() const {
        cout << data << endl;
    }
};

int main() {
    StrongGuaranteeExample example("Initial data");
    try {
        example.safeOperation("New data");  // Safe operation, strong guarantee
    } catch (...) {
        cerr << "An error occurred\n";
    }
    example.display();  // Output: New data
    return 0;
}

// If an exception occurs during temp creation, data is unchanged, preserving the original state.

// ---------------------------------------------------------------

// 4. No-Throw Guarantee (noexcept)
// The no-throw guarantee ensures that a function will not throw any exceptions. In modern C++, this is marked using the noexcept specifier, which allows the compiler to optimize the code.

// Example Use Cases: Move constructors and destructors are commonly marked noexcept to allow efficient container operations.

#include <iostream>
#include <vector>
using namespace std;

class NoThrowExample {
    int* data;

public:
    // Constructor
    NoThrowExample(int value) : data(new int(value)) {}

    // Move constructor with noexcept
    NoThrowExample(NoThrowExample&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Destructor
    ~NoThrowExample() {
        delete data;
    }

    // Method to display data
    void display() const {
        if (data) cout << *data << endl;
    }
};

int main() {
    vector<NoThrowExample> vec;
    vec.push_back(NoThrowExample(10));  // No-throw move allows optimizations
    vec[0].display();  // Output: 10
    return 0;
}

// Because NoThrowExample has a move constructor that is noexcept, vector can safely move elements without needing to handle exceptions, improving performance.