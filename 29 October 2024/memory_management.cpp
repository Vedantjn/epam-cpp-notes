// Basic Memory Management in C++
#include <iostream>
using namespace std;

// Part 1: Basic Single Value Memory Management
void basicMemoryDemo() {
    int* ptr = new int;
    *ptr = 10;
    cout << "Value stored: " << *ptr << endl;
    delete ptr;
}

// Part 2: Array Memory Management
void arrayMemoryDemo() {
    int* arr = new int[5];
    for(int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    cout << "Array values: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
}

// Part 3: Object Memory Management
class Sample {
    public:
        Sample() { cout << "Constructor called" << endl; }
        ~Sample() { cout << "Destructor called" << endl; }
};

void objectMemoryDemo() {
    Sample* obj = new Sample();
    delete obj;
}

// Part 4: C-style vs C++ Memory Management
void compareCAndCppMemory() {
    // C-style memory management
    int* ptr1 = (int*)malloc(sizeof(int));
    *ptr1 = 10;
    cout << "Value stored using malloc: " << *ptr1 << endl;
    free(ptr1);

    // C++ style memory management
    int* ptr2 = new int;
    *ptr2 = 10;
    cout << "Value stored using new: " << *ptr2 << endl;
    delete ptr2;
}

// Part 5: Array Memory Management Comparison
void compareArrayAllocation() {
    // C-style array allocation
    int* arr1 = (int*)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++) {
        arr1[i] = i + 1;
    }
    cout << "Array values (malloc): ";
    for(int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    free(arr1);

    // C++ style array allocation
    int* arr2 = new int[5];
    for(int i = 0; i < 5; i++) {
        arr2[i] = i + 1;
    }
    cout << "Array values (new): ";
    for(int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    delete[] arr2;
}

// Part 6: Object Construction Comparison
void compareObjectAllocation() {
    // malloc doesn't call constructor
    Sample* obj1 = (Sample*)malloc(sizeof(Sample));
    free(obj1);

    // new calls constructor and delete calls destructor
    Sample* obj2 = new Sample();
    delete obj2;
}

// Part 7: Common Memory Management Pitfalls
void demonstrateCorrectArrayDeletion() {
    // Correct way to handle array memory
    int* ptr = new int[10];
    ptr[0] = 5;  // Set first element
    delete[] ptr;  // Correct way to delete array
}

int main() {
    cout << "=== Basic Memory Management ===" << endl;
    basicMemoryDemo();
    
    cout << "\n=== Array Memory Management ===" << endl;
    arrayMemoryDemo();
    
    cout << "\n=== Object Memory Management ===" << endl;
    objectMemoryDemo();
    
    cout << "\n=== C vs C++ Memory Management ===" << endl;
    compareCAndCppMemory();
    
    cout << "\n=== Array Allocation Comparison ===" << endl;
    compareArrayAllocation();
    
    cout << "\n=== Object Allocation Comparison ===" << endl;
    compareObjectAllocation();
    
    cout << "\n=== Correct Array Deletion Demo ===" << endl;
    demonstrateCorrectArrayDeletion();
    
    return 0;
}


// Output:

// === Basic Memory Management ===
// Value stored: 10

// === Array Memory Management ===
// Array values: 1 2 3 4 5

// === Object Memory Management ===
// Constructor called
// Destructor called

// === C vs C++ Memory Management ===
// Value stored using malloc: 10
// Value stored using new: 10

// === Array Allocation Comparison ===
// Array values (malloc): 1 2 3 4 5
// Array values (new): 1 2 3 4 5

// === Object Allocation Comparison ===
// Constructor called
// Destructor called

// === Correct Array Deletion Demo ===




/*
Key Differences between new and malloc:
1. new is an operator, malloc() is a function
2. new returns exact data type, malloc returns void*
3. new calls constructor, malloc doesn't
4. new throws bad_alloc exception, malloc returns NULL
5. new can be overloaded, malloc cannot
6. Memory allocated from 'new' can only be deleted by 'delete'
7. Memory allocated from 'malloc' can only be freed by 'free'

Use malloc when:
- Working with C code or C APIs
- Need to reallocate memory (realloc)
- Need to allocate memory of size 0
- Want explicit control over memory alignment
- Exception handling is not desired

Use new when:
- Writing modern C++ code
- Working with objects that need constructors
- Need type safety
- Want exception handling
- Need to override memory allocation behavior
- Working with STL containers and smart pointers
*/