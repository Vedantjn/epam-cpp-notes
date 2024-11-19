// • auto_ptr was deprecated in C++11 and removed in C++17 due to problematic behavior and better alternatives

// • Key reasons for deprecation:
//    1. Ownership transfer issues
//       - Transfer of ownership during assignment/copy
//       - Original pointer becomes nullptr
//       - Led to confusion and bugs

//    2. Container compatibility problems
//       - Unsafe in standard containers (vector, map)
//       - Caused dangling pointers and resource leaks

//    3. Thread safety concerns
//       - Not thread-safe for modern programming

//    4. Better alternatives introduced in C++11
//       - std::unique_ptr: Exclusive ownership
//       - std::shared_ptr: Shared ownership with reference counting

// • Comparison with std::unique_ptr:
//    - auto_ptr: Implicit ownership transfer
//    - unique_ptr: Explicit transfer via std::move
//    - auto_ptr: Unsafe in containers
//    - unique_ptr: Safe container usage
//    - auto_ptr: Not thread-safe
//    - unique_ptr: Thread-safe

// • Recommendation:
//    - Use std::unique_ptr or std::shared_ptr for modern C++ development
//    - Avoid std::auto_ptr in all new code
