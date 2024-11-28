#include <iostream>
#include <functional> 

using namespace std;

template <typename T>
class SmartPointer {
private:
    T* ptr;
    function<void(T*)> customDeleter; 

public:
    explicit SmartPointer(T* p = nullptr, function<void(T*)> deleter = nullptr)
        : ptr(p), customDeleter(deleter) {}

    ~SmartPointer() {
        if (customDeleter) {
            cout << "SmartPointer: Using custom deleter\n";
            customDeleter(ptr);
        } else {
            cout << "SmartPointer: Using default deleter\n";
            delete ptr;
        }
    }

    SmartPointer(const SmartPointer&) = delete;

    SmartPointer& operator=(const SmartPointer&) = delete;

    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr), customDeleter(move(other.customDeleter)) {
        other.ptr = nullptr;
    }

    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            if (customDeleter) {
                customDeleter(ptr); 
            } else {
                delete ptr;
            }

            ptr = other.ptr;
            customDeleter = move(other.customDeleter);
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
};

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {
        cout << "MyClass Constructor: Initialized with value " << value << '\n';
    }

    ~MyClass() {
        cout << "MyClass Destructor: Object destroyed\n";
    }

    void display() const {
        cout << "Value: " << value << '\n';
    }
};

int main() {
    {
        cout << "Creating SmartPointer with default deleter\n";
        SmartPointer<MyClass> sp(new MyClass(42));
        sp->display();

        cout << "\nCreating SmartPointer with custom deleter\n";
        SmartPointer<MyClass> spCustom(new MyClass(84), [](MyClass* p) {
            cout << "Custom Deleter: Deleting MyClass object\n";
            delete p;
        });
        spCustom->display();
    } // sp and spCustom go out of scope here

    cout << "\nSmartPointer complete\n";
    return 0;
}

// Creating SmartPointer with default deleter
// MyClass Constructor: Initialized with value 42
// Value: 42

// Creating SmartPointer with custom deleter
// MyClass Constructor: Initialized with value 84
// Value: 84
// SmartPointer: Using custom deleter
// Custom Deleter: Deleting MyClass object
// MyClass Destructor: Object destroyed
// SmartPointer: Using default deleter
// MyClass Destructor: Object destroyed

// SmartPointer complete