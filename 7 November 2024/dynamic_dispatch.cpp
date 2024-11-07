// 1. Dynamic Dispatch Overview:
//     - Runtime mechanism in C++ for function call resolution
//     - Used with polymorphic (virtual) functions
//     - Works through base class references/pointers

// 2. Implementation Components:
//     - vtable (Virtual Table)
//     - vptr (Virtual Pointer)
//     - Runtime function resolution

// 3. vtable Details:
//     - Contains function pointers
//     - One table per class with virtual functions
//     - Stores addresses of virtual functions
//     - Updated when derived classes override functions

// 4. vptr Details:
//     - Each object has a virtual pointer
//     - Points to class's vtable
//     - Set during object creation
//     - Used for runtime function lookup

// 5. Dynamic Dispatch Process:
//     - Access object's vptr
//     - Locate correct vtable
//     - Find function address
//     - Execute appropriate function

// 6. Implementation Example:
//     - Base class (Animal) with virtual function
//     - Derived class (Dog) with override
//     - Base pointer to derived object
//     - Runtime resolution of correct function

// 7. Key Benefits:
//     - Runtime polymorphism
//     - Flexible object behavior
//     - Enhanced encapsulation
//     - Type-independent programming

// 8. Usage Conditions:
//     - Virtual function calls
//     - Base class pointer/reference
//     - Runtime resolution required
//     - Derived class overrides present

// 9. Performance Considerations:
//     - Small overhead from vtable lookup
//     - Memory cost for vtable and vptr
//     - Trade-off for flexibility



// vtable: Each class with virtual functions has a virtual table containing pointers to the virtual functions it defines or inherits.

// If a derived class overrides a virtual function, its vtable entry for that function will point to the derived class’s version of the function.
// vptr: Each object of a class with virtual functions has a vptr, which points to its class’s vtable.

// When you create an object of a derived class, the vptr in that object is set to point to the derived class’s vtable.


// The Process of Dynamic Dispatch
// When a virtual function is called through a base class reference or pointer, here’s what happens:

// The compiler uses the vptr in the object to look up the correct vtable.
// Using the vtable, it finds the address of the function to be called (either from the base class or the overridden function in the derived class).
// The program then calls the function at the address obtained from the vtable.



// Dynamic dispatch happens when:

// You call a virtual function on an object via a base class pointer or reference.
// The function is resolved at runtime to account for any overridden implementations in derived classes.