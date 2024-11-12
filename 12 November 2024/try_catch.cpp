  #include <iostream>
  #include <vector>
  #include <stdexcept>
  using namespace std;

  // Custom divide by zero exception class
  class DivideByZeroException : public exception {
      public:
          const char* what() const throw() {
              return "Division by zero is not allowed!";
          }
  };

  int main() {
      // Theory:
      // try-catch blocks are used for exception handling in C++
      // try block contains code that might throw an exception
      // catch block handles the exception if it occurs
      // multiple catch blocks can handle different types of exceptions
      // throw keyword is used to throw an exception
    
      cout << "\n----- Basic Exception Handling -----\n";
      try {
          int numerator = 10;
          int denominator = 0;
          if (denominator == 0) {
              throw DivideByZeroException();
          }
          cout << "Result: " << numerator/denominator << endl;
      }
      catch (const DivideByZeroException& e) {
          cout << "Exception caught: " << e.what() << endl;
      }

      cout << "\n----- Multiple Exception Types -----\n";
      try {
          int choice;
          cout << "Enter 1 for int exception, 2 for double, 3 for string: ";
          cin >> choice;
        
          if (choice == 1) {
              throw 100;
          }
          else if (choice == 2) {
              throw 10.5;
          }
          else if (choice == 3) {
              throw "String exception";
          }
      }
      catch (int e) {
          cout << "Integer exception caught: " << e << endl;
      }
      catch (double e) {
          cout << "Double exception caught: " << e << endl;
      }
      catch (const char* e) {
          cout << "String exception caught: " << e << endl;
      }
      catch (...) {
          cout << "Default exception handler - catches all types" << endl;
      }

      cout << "\n----- Standard Exceptions -----\n";
      // Theory about standard exceptions:
      // 1. std::bad_alloc:
      //    - Thrown when dynamic memory allocation fails (new operator)
      //    - Usually occurs when system runs out of memory
      //    - Part of <new> header
      //    - Common in large array allocations or memory-intensive operations
      
      // 2. std::out_of_range:
      //    - Thrown when accessing elements beyond container bounds
      //    - Common with vector, string, and other STL containers
      //    - Part of <stdexcept>
      //    - Helps prevent buffer overflows and memory corruption
      
      // 3. std::runtime_error:
      //    - Base class for runtime-related errors
      //    - Used for errors that can only be detected during program execution
      //    - Part of <stdexcept>
      
      // 4. std::invalid_argument:
      //    - Thrown when an invalid argument is passed to a function
      //    - Used for parameter validation
      //    - Part of <stdexcept>
      //    - Common in input validation scenarios

      try {
          // Bad allocation example
          int* arr = new int[1000000000000];
      }
      catch (const bad_alloc& e) {
          cout << "Memory allocation failed: " << e.what() << endl;
      }

      try {
          // Out of range example
          vector<int> vec(5);
          vec.at(10) = 100;
      }
      catch (const out_of_range& e) {
          cout << "Out of range error: " << e.what() << endl;
      }

      try {
          // Generic exception
          throw runtime_error("A runtime error occurred");
      }
      catch (const exception& e) {
          cout << "Standard exception: " << e.what() << endl;
      }

      try {
          // Invalid argument
          throw invalid_argument("Invalid argument provided");
      }
      catch (const invalid_argument& e) {
          cout << "Invalid argument: " << e.what() << endl;
      }
      catch (const exception& e) {
          cout << "Generic exception: " << e.what() << endl;
      }
      catch (...) {
          cout << "Default exception handler" << endl;
      }
    //   Ellipsis (...) in a catch block catches any exception not explicitly handled by other catch blocks.

      return 0;
  }

//   ----- Basic Exception Handling -----
// Exception caught: Division by zero is not allowed!

// ----- Multiple Exception Types -----
// Enter 1 for int exception, 2 for double, 3 for string: kn

// ----- Standard Exceptions -----
// Memory allocation failed: std::bad_alloc
// Out of range error: vector::_M_range_check: __n (which is 10) >= this->size() (which is 5)
// Standard exception: A runtime error occurred
// Invalid argument: Invalid argument provided