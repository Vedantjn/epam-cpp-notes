#include <iostream>
using namespace std;

class Base {
private:
    int private_var = 1;
protected:
    int protected_var = 2;
public:
    int public_var = 3;
    
    void display() {
        cout << "Private var: " << private_var << endl;
        cout << "Protected var: " << protected_var << endl;
        cout << "Public var: " << public_var << endl;
    }
};

class PublicDerived : public Base {
public:
    void access() {
        // Cannot access private_var
        cout << "Protected var in public derived: " << protected_var << endl;
        cout << "Public var in public derived: " << public_var << endl;
    }
};

class ProtectedDerived : protected Base {
public:
    void access() {
        // Cannot access private_var
        cout << "Protected var in protected derived: " << protected_var << endl;
        cout << "Public var (now protected) in protected derived: " << public_var << endl;
    }
};

class PrivateDerived : private Base {
public:
    void access() {
        // Cannot access private_var
        cout << "Protected var in private derived: " << protected_var << endl;
        cout << "Public var (now private) in private derived: " << public_var << endl;
    }
};

int main() {
    Base base;
    PublicDerived pub;
    ProtectedDerived prot;
    PrivateDerived priv;

    cout << "Base class:" << endl;
    base.display();
    
    cout << "\nPublic inheritance:" << endl;
    pub.access();
    pub.display();  // Accessible
    
    cout << "\nProtected inheritance:" << endl;
    prot.access();
    // prot.display();  // Not accessible
    
    cout << "\nPrivate inheritance:" << endl;
    priv.access();
    // priv.display();  // Not accessible
    
    return 0;
}

// Base class:
// Private var: 1
// Protected var: 2
// Public var: 3

// Public inheritance:
// Protected var in public derived: 2
// Public var in public derived: 3
// Private var: 1
// Protected var: 2
// Public var: 3

// Protected inheritance:
// Protected var in protected derived: 2
// Public var (now protected) in protected derived: 3

// Private inheritance:
// Protected var in private derived: 2
// Public var (now private) in private derived: 3




/*
Base Class       Public          Protected       Private
Access Level     Inheritance     Inheritance     Inheritance
-------------   ------------    -------------   -------------
public          public          protected       private
protected       protected       protected       private
private         inaccessible    inaccessible    inaccessible
*/