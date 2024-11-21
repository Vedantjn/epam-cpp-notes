// In C++, functors (or function objects) are objects that can be called like functions. 
// They are implemented by overloading the function call operator (operator()).

// Functors are primarily used in scenarios like custom logic in algorithms, callbacks, 
// or any situation where an object needs to behave like a function.  

// Advantages of Functors
// - Stateful Objects: 
//   Functors can store state.
//   Functions cannot store state between calls unless using external mechanisms like static variables.
// - Custom Behavior: 
//   They allow you to define custom logic for algorithms, particularly for use with STL functions.
// - Reusability: 
//   Functors can be reused and are easier to extend compared to traditional functions.


#include<iostream>
using namespace std;

class Multiply {
private:
    int factor;
public:
    Multiply(int f) : factor(f) {}
    int operator()(int x) const {
        return x*factor;
    } 
};

int main(){
    Multiply multiply(7);
    cout << multiply(3) << endl;
    cout << multiply(4) << endl;
    cout << multiply(2) << endl;

    return 0;
}


// Functors with STL Algorithms
// Functors are often used with STL algorithms like std::sort, std::for_each, etc., 
// where custom behavior is required.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class isOdd {
public:
    bool operator()(int x) {
        return x%2 != 0;
    }
};

int main(){
    vector<int>numbers = {3, 65, 2, 55, 22, 455};
    auto oddCount = count_if(numbers.begin(), numbers.end(), isOdd());
    cout << "Number of odd numbers : " << oddCount << endl;
    return 0;
}


// Types of Functors
// - Unary Functors: Operate on a single argument (e.g., increment, negate, etc.).
// - Binary Functors: Operate on two arguments (e.g., addition, multiplication, etc.).

// Standard Library Functors
// The C++ Standard Library provides pre-defined functors in <functional> for common operations, such as:
// - std::plus: Adds two values.
// - std::minus: Subtracts one value from another.
// - std::greater: Compares if one value is greater than another.

#include <iostream>
#include <functional>
using namespace std;

int main() {
    plus<int> add; // Standard library functor
    cout << add(10, 20) << endl; // 30

    return 0;
}


// Conclusion
// Functors are an essential tool in C++, providing callable objects that encapsulate state and custom behavior. 
// While lambdas are often more concise, functors shine in reusable, stateful, and object-oriented designs.