// Differences between static_cast and reinterpret_cast
#include <iostream>
using namespace std;

int main() {
    // 1. Type-safety demonstration
    double pi = 3.14159;
    int* ptr = &pi;

    // static_cast: Used for well-defined conversions
    int rounded = static_cast<int>(pi);  // OK: well-defined conversion
    // int* badPtr = static_cast<int*>(pi);  // Error: static_cast won't allow this unsafe conversion
    
    // reinterpret_cast: Used for low-level reinterpreting of bit patterns
    int* reinterpreted = reinterpret_cast<int*>(pi);  // Compiles but dangerous!
    
    // 2. Pointer conversions
    char* charPtr = new char[10];
    
    // static_cast is more restrictive with pointers
    // void* voidPtr = static_cast<void*>(charPtr);  // OK
    // int* intPtr = static_cast<int*>(voidPtr);     // Error: static_cast won't convert void* back to typed pointer
    
    // reinterpret_cast allows arbitrary pointer conversions
    void* voidPtr = reinterpret_cast<void*>(charPtr);
    int* intPtr = reinterpret_cast<int*>(voidPtr);    // OK but potentially dangerous
    
    // 3. Integer to pointer conversion
    long address = 0x1234567890;
    
    // static_cast won't allow integer to pointer conversion
    // int* ptr1 = static_cast<int*>(address);  // Error
    
    // reinterpret_cast allows integer to pointer conversion
    int* ptr2 = reinterpret_cast<int*>(address);  // OK but dangerous
    
    cout << "Key differences between static_cast and reinterpret_cast:" << endl;
    cout << "1. static_cast is for well-defined conversions (like int to float)" << endl;
    cout << "2. reinterpret_cast is for low-level reinterpretation of bit patterns" << endl;
    cout << "3. static_cast is more type-safe and won't allow dangerous conversions" << endl;
    cout << "4. reinterpret_cast allows pointer-to-integer and integer-to-pointer conversions" << endl;
    
    delete[] charPtr;
    return 0;
}
