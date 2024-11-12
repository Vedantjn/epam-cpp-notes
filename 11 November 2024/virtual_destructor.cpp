// When a base class pointer is used to delete a derived class object, 
// a non-virtual destructor in the base class will cause only the base class 
// destructor to be called, leading to incomplete destruction of the derived 
// class object. This can cause resource leaks or undefined behavior because 
// the derived class members or dynamically allocated resources won't be 
// properly cleaned up.

// By making the destructor virtual, you ensure that the derived class 
// destructor is called correctly, allowing proper cleanup.#include <iostream>

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// Base class A with virtual function
class A{
public:
	// Constructor of A - calls virtual function
	A(){
		cout<<"Constructor A"<<endl;
		func();
	}
	// Virtual function that can be overridden by derived classes
	virtual void func(){
		cout<<"Base Class"<<endl;
	}
	// Non-virtual destructor - can cause memory leaks with polymorphic objects
	~A(){
		cout<<"Destructor A"<<endl;
		func();
	}
};

// Derived class B inheriting from A
class B : public A{
	int x;
public:
	// Constructor of B - calls overridden func()
	B(){
		cout<<"Constructor B"<<endl;
		func();
	}
	// Override of base class virtual function
	void func(){
		cout<<"Derived Class"<<endl;
	}
	// Destructor of B
	~B(){
		cout<<"Destructor B"<<endl;
		func();
	}
};

// Derived class C inheriting from B
class C : public B{
	// Private constructor - class cannot be instantiated
	C(){
		cout<<"Constructor C"<<endl;
		func();
	}
};

int main(){
	// Polymorphic behavior and potential memory leak
	// ptr is base class pointer pointing to derived class object
	A* ptr = new B; 
	B* ptr1 = new B;
	
	// Virtual function call - will call B's implementation
	ptr->func();
	ptr1->func();
	
	// Deleting objects - potential undefined behavior due to non-virtual destructor
	delete ptr;    // Only calls A's destructor due to non-virtual destructor
	delete ptr1;   // Properly calls B's destructor

	// Note: To fix the memory leak issue, A's destructor should be virtual:
	// virtual ~A() { ... }

	return 0;
}

// Constructor A
// Base Class
// Constructor B
// Derived Class
// Constructor A
// Base Class
// Constructor B
// Derived Class
// Derived Class
// Derived Class
// Destructor A
// Base Class
// Destructor B
// Derived Class
// Destructor A
// Base Class