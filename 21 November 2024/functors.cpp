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


// Sorting a vector in descending order using functor
#include<iostream>
using namespace std;

class Sort {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main(){
    vector<int>numbers = {34, 35, 23, 46, 2};
    sort(numbers.begin(), numbers.end(), Sort());
    for(int num : numbers) {
        cout << num << " ";
    }
    return 0;
}

// Comparison for sorting strings

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CompareByLength {
public:
    bool operator()(const string& a, const string& b) {
        return a.size() < b.size();
    }
};

int main() {
    vector<string> words = {"apple", "kiwi", "banana", "cherry"};

    // Sort strings by length using the functor
    sort(words.begin(), words.end(), CompareByLength());

    for (const string& word : words) {
        cout << word << " ";
    }
    return 0;
}

// transforming elements

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Square {
public:
    int operator()(int x) {
        return x * x;
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> squares(numbers.size());

    // Transform the numbers into their squares
    transform(numbers.begin(), numbers.end(), squares.begin(), Square());

    for (int num : squares) {
        cout << num << " ";
    }
    return 0;
}

// Counting values in range:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IsInRange {
    int low, high;
public:
    IsInRange(int l, int h) : low(l), high(h) {}
    bool operator()(int x) {
        return x >= low && x <= high;
    }
};

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50, 60};

    // Count numbers in the range [20, 50]
    int count = count_if(numbers.begin(), numbers.end(), IsInRange(20, 50));

    cout << "Count of numbers in range [20, 50]: " << count << endl;
    return 0;
}

// Functor with Stateful behaviour

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Counter {
    int count;
public:
    Counter() : count(0) {}
    bool operator()(int x) {
        count++;
        return x % 2 == 0; // Return true if even
    }
    int getCount() const { return count; }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6};

    Counter counter;
    remove_if(numbers.begin(), numbers.end(), Counter());

    cout << "Functor was called " << counter.getCount() << " times." << endl;
    return 0;
}


// Doubt: Why is the counter not incrementing (it is showing garbage value)?

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Sort {
    int count;
public:
    bool operator()(int a, int b) {
        count++;
        return a > b;
    }
    int getCount() {
        return count;
    }
};

int main(){
    vector<int>numbers = {34, 35, 23, 46, 2};
    Sort obj;
    sort(numbers.begin(), numbers.end(), obj);
    for(int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << obj.getCount() << endl;
    
    return 0;
}