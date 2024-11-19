// # Move and Copy Semantics in C++

// ## Introduction
// In C++, copy semantics and move semantics define how objects are transferred or duplicated. These mechanisms determine how resources are handled when objects are copied or moved. Introduced in C++11, move semantics optimize the transfer of resources, particularly for temporary objects.

// ## Copy Semantics
// Copy semantics involve duplicating an object, creating a new object that is an exact replica of the original.

// ### Key Points:
// - Copy Constructor: Creates a new object as a copy of an existing one.
// - Copy Assignment Operator: Assigns the contents of one object to an existing object.

// ### Example of Copy Semantics:

#include<iostream>
#include<cstring>

using namespace std;

class MyClass {
private:
    char* data;

public:
    // Constructor
    MyClass(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy Constructor called.\n";
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this; // Self-assignment check
        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy Assignment Operator called.\n";
        return *this;
    }

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    void display() const {
        cout << data << "\n";
    }
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2 = obj1; // Copy Constructor
    MyClass obj3("World");
    obj3 = obj1;         // Copy Assignment Operator

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}

// ### Output:

// Copy Constructor called.
// Copy Assignment Operator called.
// Hello
// Hello
// Hello


// ## Move Semantics
// Move semantics allow the ownership of resources to be transferred from one object to another instead of duplicating the resources.

// ### Key Points:
// - Move Constructor: Transfers resources from a source object to a new object.
// - Move Assignment Operator: Transfers resources from one object to another, deallocating existing resources.

// ### Why Move Semantics?
// - To avoid unnecessary deep copies.
// - To improve performance, especially for temporary objects or large data structures.

// ### Example of Move Semantics:

#include<iostream>
#include<cstring>

using namespace std;

class MyClass {
private:
    char* data;

public:
    // Constructor
    MyClass(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;     // Transfer ownership
        other.data = nullptr;  // Nullify the source pointer
        cout << "Move Constructor called.\n";
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other) return *this; // Self-assignment check
        delete[] data;                    // Free existing resources
        data = other.data;                // Transfer ownership
        other.data = nullptr;             // Nullify the source pointer
        cout << "Move Assignment Operator called.\n";
        return *this;
    }

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    void display() const {
        if (data) {
            cout << data << "\n";
        } else {
            cout << "Empty\n";
        }
    }
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2 = move(obj1); // Move Constructor
    MyClass obj3("World");
    obj3 = move(obj2);         // Move Assignment Operator

    obj1.display(); // Empty
    obj2.display(); // Empty
    obj3.display(); // Hello

    return 0;
}


// ### Output:

// Move Constructor called.
// Move Assignment Operator called.
// Empty
// Empty
// Hello


// ## Key Differences: Copy vs Move Semantics
//
// | Aspect        | Copy Semantics                | Move Semantics                      |
// |--------------|------------------------------|-------------------------------------|
// | Mechanism    | Duplicates resources         | Transfers ownership of resources    |
// | Performance  | Slower, involves deep copies | Faster, avoids unnecessary duplication |
// | Constructors | Copy Constructor: T(const T&) | Move Constructor: T(T&&)           |
// | Assignment   | Copy Assignment: T& operator=(const T&) | Move Assignment: T& operator=(T&&) |
// | Use Case     | When duplicate needed        | When original no longer needed      |
// | Introduced In| Pre-C++11                   | C++11 and later                     |

// ## Rule of Five
// If a class manages dynamic memory or other resources, it should implement:
// 1. Destructor
// 2. Copy Constructor
// 3. Copy Assignment Operator
// 4. Move Constructor
// 5. Move Assignment Operator

// ### Complete Example:

#include <iostream>
#include <cstring>

using namespace std;

class MyClass {
private:
    char* data;

public:
    // Constructor
    MyClass(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    // Copy Constructor
    MyClass(const MyClass& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy Constructor called.\n";
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this;
        delete[] data;
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy Assignment Operator called.\n";
        return *this;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        cout << "Move Constructor called.\n";
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other) return *this;
        delete[] data;
        data = other.data;
        other.data = nullptr;
        cout << "Move Assignment Operator called.\n";
        return *this;
    }

    void display() const {
        if (data) {
            cout << data << "\n";
        } else {
            cout << "Empty\n";
        }
    }
};

int main() {
    MyClass obj1("Hello");
    MyClass obj2 = obj1;           // Copy Constructor
    MyClass obj3 = move(obj1);     // Move Constructor

    obj2 = obj3;                   // Copy Assignment
    obj3 = MyClass("World");       // Move Assignment

    obj1.display(); // Empty
    obj2.display(); // Hello
    obj3.display(); // World

    return 0;
}


// ### Best Practices
// 1. Use move semantics whenever possible to improve performance
// 2. For simple classes without dynamic resources, rely on compiler-generated functions
// 3. Use smart pointers (std::unique_ptr, std::shared_ptr) instead of raw pointers