// Rule of Zero

// Key Points:
// 1. Design classes without manual resource management
// 2. Avoid writing:
//    - Destructors
//    - Copy constructors
//    - Copy assignment operators

// 3. Instead use:
//    - Smart pointers (std::unique_ptr, std::shared_ptr)
//    - Standard containers (std::vector, std::string)

// 4. Benefits:
//    - Automatic resource management through RAII
//    - Cleaner, more maintainable code
//    - Reduced risk of memory leaks

// 5. Core principle:
//    - Let standard library components handle resource management
//    - Focus on business logic rather than memory management

// Remember: If you don't need to manually manage resources, don't write special member functions.

#include<bits/stdc++.h>
  using namespace std;

  class MyClass {
      unique_ptr<int> data;  // Smart pointer automatically manages memory
  public:
      MyClass(int value) : data(make_unique<int>(value)) {}
      int getData() const { return *data; }
  };

  int main() {
      MyClass obj(10);  // No need for manual resource management
      // obj will be destroyed when it goes out of scope
  }
