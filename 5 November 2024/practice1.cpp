// Method Chaining

#include <iostream>
using namespace std;

class Calculator {
private:
    int value;

public:
    Calculator() : value(0) {}

    Calculator(int initial) : value(initial) {}

    Calculator& add(int num) {
        // Return type Calculator& means this method returns a reference to the Calculator object
        // This enables method chaining by returning the current object
        value += num;  
        return *this;  // Return reference to current object using 'this' pointer
                      // '*this' dereferences the pointer to return the actual object
    }

    Calculator& subtract(int num) {
        value -= num;
        return *this;
    }

    Calculator& multiply(int num) {
        value *= num;
        return *this;
    }

    Calculator& divide(int num) {
        if (num != 0) {
            value /= num;
        }
        return *this;
    }

    int getResult() const {
        return value;
    }
};

int main() {
    Calculator calc(10);
    
    int result = calc.add(5)
                    .multiply(2)
                    .subtract(8)
                    .divide(2)
                    .getResult();
    
    cout << "Result: " << result << endl; // 11
    
    return 0;
}
