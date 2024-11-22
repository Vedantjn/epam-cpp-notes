// Lambda functions, introduced in C++11, are anonymous (unnamed) 
// functions that are often used as short-term callbacks or to simplify 
// code where a full function declaration would be cumbersome. They 
// allow defining and using functions inline, usually for single-use 
// or concise operations.

// [capture_clause] (parameters) -> return_type {
//     function_body
// };


// capture_clause	Specifies variables captured from the enclosing scope.
// (parameters)	Specifies the parameters of the lambda function.
// -> return_type	Specifies the return type (optional, inferred if omitted).
// function_body	The code block of the lambda function.

#include<iostream>
using namespace std;

int main(){
    auto greet = []() {
        cout << "Hello from lambda function...\n" << endl;
    };
    greet(); // Hello from lambda function...
    return 0;
}

// -------------------------------------

#include<iostream>
using namespace std;

int main(){
    auto add = [](int a, int b) {
        return a+b;
    };
    cout << "Sum : " << add(3, 4) << endl;
    return 0;
}

// -------------------------------------

// Captures allow lambdas to access variables from the enclosing scope.

#include<iostream>
using namespace std;

int main(){
    int x = 10;
    int y = 20;

    auto printSum = [x, y]() {
        cout << "Sum: " << x + y << endl;
    };
    printSum();

    return 0;
}

// -------------------------------------

#include <iostream>
using namespace std;

int main() {
    int x = 10;

    auto increment = [&x]() { // Capture x by reference
        x++;
    };

    increment();
    cout << "Modified x: " << x << endl;

    return 0;
}

// Modified x: 11

// -------------------------------------

#include <iostream>
using namespace std;

int main() {
    auto multiply = [](int a, int b) -> double {
        return a * b / 2.0;
    };

    cout << "Result: " << multiply(10, 5) << endl;

    return 0;
}

// -------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {3, 5, 2, 8, 6};

    // Sort in descending order
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });

    for (int n : nums) {
        cout << n << " ";
    }
    return 0;
}
