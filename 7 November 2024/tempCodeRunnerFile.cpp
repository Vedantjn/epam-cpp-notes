n C++:
//     - Functions in base class that can be overridden in derived classes
//     - Used for runtime polymorphism
//     - Defined using 'virtual' keyword

// 2. Purpose:
//     - Enables dynamic binding/runtime polymorphism
//     - Allows function overriding in derived classes
//     - Function call depends on actual object type, not pointer type

// 3. Working Mechanism:
//     - Compiler creates virtual table (vtable) for classes with virtual functions
//     - Objects contain virtual pointer (vptr) to vtable
//     - Dynamic dispatch occurs at runtime through vtable

// 4. Key Features:
//     - Virtual keyword used in base class
//     - Override keyword used in derived class
//     - Supports polymorphic behavior
//     - Base class destructor should be virtual

// 5. Implementation Benefits:
//     - Runtime polymorphism through base class pointers
//     - Flexible and maintainable code
//     - Common interface with specific implementations

// 6. Considerations:
//     - Memory overhead due to vtable and vptr
//     - Slightly slower execution than non-virtual functions
//     - Pure virtual functions create abstract classes
//     - Proper cleanup requires virtual destructors