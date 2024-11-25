#include <iostream>
#include <functional>  // For std::function

using namespace std;

int main() {
    // Recursive lambda function to calculate factorial
    function<int(int)> factorial = [&](int n) -> int {
        if (n <= 1) {
            return 1; // Base case
        } else {
            return n * factorial(n - 1); // Recursive case
        }
    };

    int num = 5;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    return 0;
}

// Factorial of 5 is: 120

// ------------------------------------------

#include <iostream>
#include <functional>

using namespace std;

int main() {
    function<int(int, int, int)> fibonacci = [&](int n, int a, int b) -> int {
        if (n == 0) {
            return a;  // Base case: return first number (a)
        } else if (n == 1) {
            return b;  // Base case: return second number (b)
        } else {
            return fibonacci(n - 1, b, a + b);  // Recursive case: move to the next pair
        }
    };

    int n = 6;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n, 0, 1) << endl;

    return 0;
}

// Fibonacci(6) = 8
