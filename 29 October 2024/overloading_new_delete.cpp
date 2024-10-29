// The size in the output is determined by:

// 1. For single object (size 40):
// - sizeof(Student) which includes:
//   - int age (4 bytes)
//   - string name (32 bytes typically on most systems - includes string capacity and internal buffers)
//   - potential padding bytes for alignment
// Total comes to 40 bytes on most modern 64-bit systems

// 2. For array (size 128):
// - sizeof(Student) * 3 = 120 bytes (for 3 objects)
// - Additional bytes for array bookkeeping (usually 8 bytes on 64-bit systems)
// Total comes to 128 bytes

// We can verify this by adding sizeof checks:

#include <iostream>
using namespace std;

class Student {
    int age;
    string name;
public:
    Student() {
        age = 0;
        name = "";
    }
    
    Student(int a, string n) {
        age = a;
        name = n;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    void* operator new(size_t size) {
        cout << "Overloaded new operator with size: " << size << endl;
        cout << "Size of Student class: " << sizeof(Student) << endl;
        void* ptr = malloc(size);
        return ptr;
    }

    void operator delete(void* ptr) {
        cout << "Overloaded delete operator" << endl;
        free(ptr);
    }

    void* operator new[](size_t size) {
        cout << "Overloaded new[] operator with size: " << size << endl;
        cout << "Size of Student class * 3: " << sizeof(Student) * 3 << endl;
        void* ptr = malloc(size);
        return ptr;
    }

    void operator delete[](void* ptr) {
        cout << "Overloaded delete[] operator" << endl;
        free(ptr);
    }
};

int main() {
    Student* s1 = new Student(20, "John");
    s1->display();
    delete s1;

    Student* arr = new Student[3];
    delete[] arr;

    return 0;
}

// Overloaded new operator with size: 40
// Name: John, Age: 20
// Overloaded delete operator
// Overloaded new[] operator with size: 128
// Overloaded delete[] operator