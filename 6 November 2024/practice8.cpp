// Name mangling is a process where C++ compiler creates unique names for 
// functions and variables to handle features like function overloading. 
// Unlike C, C++ needs to differentiate between functions with same names 
// but different parameters.

// Example:
// void func(int x);    // might become func_i
// void func(double x); // might become func_d

// The compiler adds special characters and identifiers to create unique 
// names based on parameters, scope, and return type. This process varies between
// different compilers.