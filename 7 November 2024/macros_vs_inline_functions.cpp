// // Inline Functions vs Macros in C++ - Key Differences

// 1. Definition:
//     - Inline functions: Functions with 'inline' keyword, compiler inserts code at call site
//     - Macros: Preprocessor directives using #define for text replacement

// 2. Key Differences:
//     - Type Safety: Inline functions are type-checked, macros are not
//     - Argument Evaluation: Inline functions evaluate once, macros may evaluate multiple times
//     - Debugging: Inline functions easier to debug, macros harder due to preprocessing
//     - Scope: Inline functions respect scope rules, macros don't
//     - Performance: Both avoid function call overhead, but inline functions get compiler optimizations
//     - Memory: Inline functions may have slight overhead, macros are pure text replacement

// 3. Best Uses:
//     - Inline Functions: Small, frequent functions needing type safety
//     - Macros: Simple constants, platform-specific code, conditional compilation

// 4. Recommendation:
//     Prefer inline functions in modern C++ for better safety and maintainability.
//     Use macros only for preprocessor-specific tasks.