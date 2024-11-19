// This code demonstrates different types of typecasting in C++

// 1. Static Cast - Compile time casting, used for implicit conversions
// 2. Dynamic Cast - Runtime casting, used with polymorphic types
// 3. Const Cast - Used to remove or add const qualifier
// 4. Reinterpret Cast - Low-level casting, reinterprets bit pattern

#include <iostream>
using namespace std;

class myClass
{
public:
    myClass()
    {
    }
    // Const member function 
    void memFunc() const
    {
        cout << "Inside const memFunc" << endl;
    }

    void NonConstMemFunc() 
    {
        cout << "Inside Non const memFunc" << endl;
    }

    void memfunc3(myClass& ref)
    {
        cout << "Inside memFunc3" << endl;
    }
};

// static_cast with arithmetic
int someFunc()
{
    int x = 25;
    int y = 15;
    // static_cast is safer than C-style cast
    return static_cast<int> (x / y);
}

// Base class for demonstrating dynamic_cast
class B {
public:
    B() {
    }
    void bFunc() {
        cout << "Inside Base Function" << endl;
    }
    // Virtual function for runtime polymorphism
    virtual void memFunc()
    {
        cout << "Inside Base Virtual Function" << endl;
    }
};

// Derived class for polymorphic behavior
class D :public B {
public:
    D(){
    }
    void dFunc() {
        cout << "Inside Der Function" << endl;
    }
    // Override virtual function
    void memFunc()
    {
        cout << "Inside Der Virtual Function" << endl;
    }
};

int main()
{
    // Dynamic Cast Example
    B* basePtr = new D();
    basePtr->bFunc(); 
    basePtr->memFunc();
    
    // Safe downcasting using dynamic_cast
    if (D* derPtr = dynamic_cast<D*>(basePtr)) {
        derPtr->memFunc();
        cout << "Dynamic cast Passed" << endl;
    }
    else {
        cout << "Dynamic cast failed" << endl;
    }

    D dObj;
    B& baseRef = dObj;
    
    // Dynamic cast with references and exception handling
    try {
        // reinterpret_cast is used for low-level casting
        D& derRef = reinterpret_cast<D&>(baseRef);
        derRef.memFunc();
    }
    catch (std::bad_cast& ex) {
        cout << "Exception thrown is: " << ex.what() << endl;
    }
    catch(...)
    {
        cout << "Dynamic cast Exception" << endl;
    }

    // Const Cast Examples (commented out for reference)
    /*
    const myClass constObj;
    myClass nonConstObj;

    // Remove const using const_cast
    const myClass& obj2 = const_cast<myClass&>(nonConstObj);
    nonConstObj.memFunc();
    constObj.memFunc();

    // Add const using const_cast
    myClass& nonConstObj2 = const_cast<myClass&>(constObj);
    nonConstObj2.NonConstMemFunc();
    */

    return 0;
}

// Inside Base Function
// Inside Der Virtual Function
// Inside Der Virtual Function
// Dynamic cast Passed
// Inside Der Virtual Function