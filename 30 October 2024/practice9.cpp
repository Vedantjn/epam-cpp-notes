// Constructors cannot be static because:

// 1. Static members belong to the class itself, not instances
// 2. Constructors are called to initialize object instances
// 3. Constructors need to access non-static members
// 4. Static functions cannot access 'this' pointer
// 5. Constructor's purpose is to create and initialize objects

class Example {
    // This is not allowed:
    // static Example() { } // Error: Constructor cannot be static
    
    // Correct way:
    Example() { } // Regular constructor
};
