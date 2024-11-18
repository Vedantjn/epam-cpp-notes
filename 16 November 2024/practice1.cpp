
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