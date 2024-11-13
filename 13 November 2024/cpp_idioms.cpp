/*
C++ Idioms - Common programming patterns and best practices in C++

1. RAII (Resource Acquisition Is Initialization)
   - Ensures resources are properly managed through object lifetime
   - Resources are acquired in constructor and released in destructor
   - Example: smart pointers(std::unique_ptr and std::shared_ptr) , lock guards 

2. Pimpl (Pointer to Implementation)
   - Hides implementation details in source file
   - Reduces compilation dependencies
   - Maintains binary compatibility

3. CRTP (Curiously Recurring Template Pattern)
   - Static polymorphism without virtual functions
   - Base class is templated with derived class type
   - Used for compile-time polymorphism

4. Rule of Three/Five/Zero
   - Rule of Three: If you define destructor, copy constructor, or copy assignment, define all three
   - Rule of Five: Adds move constructor and move assignment
   - Rule of Zero: Let compiler handle special members

5. SFINAE (Substitution Failure Is Not An Error)
   - Template metaprogramming technique
   - Enables/disables function overloads based on type properties
   - Used for compile-time type traits

6. Tag Dispatching
   - Selects different implementations based on types
   - Uses empty tag types for overload resolution
   - Compile-time polymorphism

7. Type Erasure
   - Hides type details behind common interface
   - Enables polymorphic behavior without inheritance
   - Example: std::function

8. RAII Lock Guard
   - Automatically manages mutex locking/unlocking
   - Prevents deadlocks and resource leaks
   - Exception-safe synchronization

9. Singleton Pattern
   - Ensures single instance of class
   - Thread-safe implementation in modern C++
   - Lazy initialization

10. Factory Method
    - Creates objects without exposing creation logic
    - Delegates object creation to derived classes
    - Flexible object creation

11. Smart Pointers
    - Automatic memory management
    - unique_ptr, shared_ptr, weak_ptr
    - Prevents memory leaks

12. Copy-and-Swap
    - Exception-safe assignment operators
    - Implements strong exception guarantee
    - Clean resource management
*/
