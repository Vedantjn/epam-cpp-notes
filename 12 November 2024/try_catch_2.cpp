#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept> // Required for std::out_of_range
#include <cmath>

using namespace std;

// Custom exception class inheriting from std::exception
class divideByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "divideByZeroException: Division by zero attempted";
    }
};

class divideByZeroException1 {};

class myClass {
public:
    myClass() {}

    void memFunc1(int x, int y) {
        try {
            if (y == 0) {
                throw divideByZeroException1();
            }
            int k = x / y;
        } 
        catch (bad_alloc& ex) {
            cout << "Memory allocation failed: " << ex.what() << endl;
        }
        catch (out_of_range& ex) {
            cout << "Out of range exception: " << ex.what() << endl;
        }
        catch (divideByZeroException1&) {
            cout << "Custom exception: Division by zero detected." << endl;
        }
        catch (...) {
            cout << "Exception caught in default catch block." << endl;
        }
        cout << "Outside try-catch in memFunc1." << endl;
    }

    void memFunc2() {
        try {
            throw runtime_error("Error in memFunc2");
        } 
        catch (const exception& e) {
            cout << "Caught in memFunc2: " << e.what() << endl;
        }
    }
    
    void memFunc3() {
        try {
            vector<int> intVector;
            cout << intVector.at(5);
        }
        catch (out_of_range& ex) {
            cout << "Inside MemFunc3. Exception: " << ex.what() << endl;
            cout << "Re-throwing exception from MemFunc3." << endl;
            throw; // Re-throwing exception
        }
    }
};

class A {
    int* p;
public:
    A() : p(nullptr) { // Initialize pointer to nullptr
        cout << "Inside A's constructor" << endl;
    }
    ~A() {
        cout << "Inside A's destructor" << endl;
        delete[] p; // Ensure p is deleted if allocated
    }
};

class B {
public:
    B() {
        try {
            cout << "Inside B's constructor" << endl;
            vector<int> intVector;
            cout << intVector.at(5); // Trigger out_of_range exception
        }
        catch (const exception& ex) {
            cout << "Exception inside B constructor: " << ex.what() << endl;
            throw; // Re-throwing exception to calling code
        }
    }
    ~B() {
        cout << "Inside B's destructor" << endl;
    }
    void memFunc() {}
};

void globalFunc() {
    try {
        B obj;
    }
    catch (const exception& ex) {
        cout << "Caught in globalFunc: " << ex.what() << endl;
    }
}

void tempFunc() {
    try {
        vector<int> intVector;
        cout << intVector.at(5); // Out of range access
    }
    catch (const out_of_range& e) {
        cout << "Out of range in tempFunc: " << e.what() << endl;
    }
}

class A1 {
    int* p;
public:
    A1() : p(new int[10]) { // Allocate memory for array
        cout << "A1's constructor" << endl;
    }
    ~A1() {
        delete[] p; // Release allocated memory
        cout << "Inside A1's destructor" << endl;
    }
};

class B1 {
    A1 aObj1;
    A1 aObj2;
public:
    B1() {
        try {
            vector<int> intVector;
            cout << intVector.at(5); // Trigger out_of_range exception
        }
        catch (const exception& ex) {
            cout << "Exception in B1's constructor: " << ex.what() << endl;
        }
    }
    void BMemFunc() {
        try {
            vector<int> intVector;
            cout << intVector.at(5); // Out of range access
        }
        catch (const out_of_range& e) {
            cout << "Out of range in BMemFunc: " << e.what() << endl;
        }
    }
};

int main() {
    B1 objB;

    // Demonstrate other functions
    myClass obj;
    obj.memFunc1(5, 0); // Trigger division by zero
    obj.memFunc2();

    try {
        obj.memFunc3();
    }
    catch (const exception& ex) {
        cout << "Caught in main: " << ex.what() << endl;
    }

    tempFunc();
    globalFunc();

    return 0;
}

// A1's constructor
// A1's constructor
// Exception in B1's constructor: vector::_M_range_check: __n (which is 5) >= this->size() (which is 0)
// Custom exception: Division by zero detected.
// Outside try-catch in memFunc1.
// Caught in memFunc2: Error in memFunc2
// Inside MemFunc3. Exception: vector::_M_range_check: __n (which is 5) >= this->size() (which is 0)
// Re-throwing exception from MemFunc3.
// Caught in main: vector::_M_range_check: __n (which is 5) >= this->size() (which is 0)
// Out of range in tempFunc: vector::_M_range_check: __n (which is 5) >= this->size() (which is 0)
// Inside B's constructor
// Exception inside B constructor: vector::_M_range_check: __n (which is 5) >= this->size() (which is 0)
// Caught in globalFunc: vector::_M_range_check: __n (which is 5) >= this->size() (which is 0)
// Inside A1's destructor
// Inside A1's destructor