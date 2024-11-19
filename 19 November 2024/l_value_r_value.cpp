// L-Value and R-Value References in C++

// 1. L-Values
//      - Definition: An L-value (locator value) represents an object that persists beyond a single expression
//      - Has an identifiable location in memory
//      - Can take its address
//      - Characteristics:
//        * Can appear on left-hand side of assignment
//        * Represent variables, objects, or expressions referring to modifiable memory locations
//        * Always have an address
    //  - Example:
       int x = 10;   // `x` is an L-value
       x = 20;       // Assigning a new value to `x`
       int* ptr = &x; // Valid, `x` has an address

// 2. R-Values
//      - Definition: An R-value (read value) represents temporary objects or values
//      - Does not persist beyond the expression
//      - No identifiable memory location
//      - Characteristics:
//        * Can appear on right-hand side of assignment
//        * Usually literals, temporary objects, or return values of functions
//        * No directly accessible address
//      - Example:
       int y = 10 + 20; // `10 + 20` is an R-value
       int x = 42;      // `42` is an R-value

// 3. L-Value Reference
//      - Definition: Binds to an L-value, allowing modification or access to original object
//      - Characteristics:
//        * Used to alias variables or objects
//        * Cannot bind to R-values directly
//      - Example:
       int x = 42;
       int& ref = x;  // L-value reference binds to L-value `x`
       ref = 50;      // Modifies the original `x`
       cout << x; // Outputs `50`

// 4. R-Value Reference
//      - Definition: Binds to R-values, enables operations on temporary objects
//      - Characteristics:
//        * Introduced in C++11
//        * Declared using &&
//        * Used in move semantics and perfect forwarding
//      - Example:
       int&& temp = 10; // R-value reference binds to R-value `10`
       temp = 20;       // Modifies the value of `temp`
       cout << temp; // Outputs `20`

// 5. Use Cases
//      - L-Value Reference:
//        * Modifying variables
//        * Passing large objects by reference to avoid copies
//      - R-Value Reference:
//        * Move Semantics: Transfer resources from temporary object
//        * Perfect Forwarding: Preserve value category in function forwarding

// 6. Differences Between L-Value and R-Value References
//      - Binding:
//        * L-Value Reference: Binds to L-values only
//        * R-Value Reference: Binds to R-values only
//      - Syntax:
//        * L-Value Reference: T&
//        * R-Value Reference: T&&
//      - Use Case:
//        * L-Value Reference: Aliasing or modifying existing objects
//        * R-Value Reference: Manipulating temporary objects
//      - Mutability:
//        * Both can modify bound objects

// 7. Practical Example: Move Semantics
     #include <iostream>
     #include <vector>

     class MyClass {
         std::vector<int> data;

     public:
         MyClass(size_t n) : data(n, 0) {
             std::cout << "Constructed\n";
         }

         // Move constructor
         MyClass(MyClass&& other) noexcept : data(std::move(other.data)) {
             std::cout << "Move Constructor\n";
         }

         // Copy constructor
         MyClass(const MyClass& other) : data(other.data) {
             std::cout << "Copy Constructor\n";
         }
     };

     int main() {
         MyClass obj1(10);         // Constructed
         MyClass obj2 = obj1;      // Copy Constructor
         MyClass obj3 = std::move(obj1); // Move Constructor
         return 0;
     }

// 8. Summary
//      - L-Values: Persistent objects with memory address
//      - R-Values: Temporary objects or literals without identifiable memory location
//      - L-Value Reference (T&): Binds to L-values
//      - R-Value Reference (T&&): Binds to R-values, used for move semantics and resource management