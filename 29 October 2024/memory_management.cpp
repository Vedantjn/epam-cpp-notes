#include <iostream>
using namespace std;

int main() {
    // Using new to allocate memory for a single integer
    int* ptr = new int;
    *ptr = 10;
    cout << "Value stored: " << *ptr << endl;
    delete ptr;  // Deallocating memory

    // Using new[] for array allocation
    int* arr = new int[5];
    for(int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    cout << "Array values: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;  // Deallocating array memory

    // Dynamic allocation of objects
    class Sample {
        public:
            Sample() { cout << "Constructor called" << endl; }
            ~Sample() { cout << "Destructor called" << endl; }
    };

    Sample* obj = new Sample();
    delete obj;

    return 0;
}


// Demonstrating malloc/free vs new/delete

#include <iostream>
#include <cstdlib>  // for malloc and free
using namespace std;

int main() {
    // Using malloc (C-style)
    int* ptr1 = (int*)malloc(sizeof(int));
    *ptr1 = 10;
    cout << "Value stored using malloc: " << *ptr1 << endl;
    free(ptr1);  // C-style deallocation

    // Using new (C++ style)
    int* ptr2 = new int;
    *ptr2 = 10;
    cout << "Value stored using new: " << *ptr2 << endl;
    delete ptr2;  // C++ style deallocation

    // Array allocation with malloc
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

    // Array allocation with new
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

    // Key differences with objects:
    class Sample {
        public:
            Sample() { cout << "Constructor called" << endl; }
            ~Sample() { cout << "Destructor called" << endl; }
    };

    // malloc doesn't call constructor
    Sample* obj1 = (Sample*)malloc(sizeof(Sample));
    free(obj1);

    // new calls constructor and delete calls destructor
    Sample* obj2 = new Sample();
    delete obj2;

    return 0;
}

// new vs malloc:
// 1. new is an operator, malloc() is a function
// 2. new returns exact data type, malloc returns void*
// 3. new calls constructor, malloc doesn't
// 4. new throws bad_alloc exception, malloc returns NULL
// 5. new can be overloaded, malloc cannot
// 6. Memory allocated from 'new' can only be deleted by 'delete'
// 7. Memory allocated from 'malloc' can only be freed by 'free'

// When to use malloc:
// - When working with C code or C APIs
// - When you need to reallocate memory (realloc)
// - When you need to allocate memory of size 0
// - When you want explicit control over memory alignment
// - When exception handling is not desired

// When to use new:
// - In modern C++ code
// - When working with objects that need constructors
// - When you want type safety
// - When you want exception handling
// - When you need to override memory allocation behavior
// - When working with STL containers and smart pointers




int* ptr;
ptr = new int[10];  // Allocates array of 10 integers

*ptr = 5;  // Only sets first element to 5

delete ptr;  // MEMORY LEAK - Should use delete[] for arrays

// Correct version should be:
int* ptr;
ptr = new int[10];
*ptr = 5;
delete[] ptr;  // Use delete[] for arrays


