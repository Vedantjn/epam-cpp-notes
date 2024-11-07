#include <iostream>
using namespace std;

class BaseWithoutVirtual {
    int x;
    int y;
public:
    void print() { cout << "Base" << endl; }
};

class DerivedWithoutVirtual : public BaseWithoutVirtual {
    int z;
public:
    void print() { cout << "Derived" << endl; }
};

class BaseWithVirtual {
    int x;      // 4 bytes
    int y;      // 4 bytes
    // vptr     // 8 bytes - compiler adds a virtual pointer for virtual function table
public:
    virtual void print() { cout << "Base" << endl; }
};

class DerivedWithVirtual : public BaseWithVirtual {
    int z;      
public:
    void print() override { cout << "Derived" << endl; }
};

int main() {
    cout << "Size of BaseWithoutVirtual: " << sizeof(BaseWithoutVirtual) << " bytes" << endl;
    cout << "Size of DerivedWithoutVirtual: " << sizeof(DerivedWithoutVirtual) << " bytes" << endl;
    cout << "Size of BaseWithVirtual: " << sizeof(BaseWithVirtual) << " bytes" << endl;
    cout << "Size of DerivedWithVirtual: " << sizeof(DerivedWithVirtual) << " bytes" << endl;
    
    return 0;
}

// Size of BaseWithoutVirtual: 8 bytes
// Size of DerivedWithoutVirtual: 12 bytes
// Size of BaseWithVirtual: 16 bytes
// Size of DerivedWithVirtual: 24 bytes
