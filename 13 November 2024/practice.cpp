#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class divideByZeroException : public exception {
public:
    // divideByZeroException() : exception("divideByZeroException exception thrown") {}

    const char* what() const noexcept override {
        return "divideByZeroException exception thrown";
    }
};

class myClass {
public:
    myClass() {}

    void myFunct(int x, int y) {
        try {
            // Example 1: Test divide by zero exception
            if (y == 0) {
                throw divideByZeroException();
            }

            // Example 2: Divide numbers
            int k = x / y;

            // Example 3: Out of range exception on vector access
            vector<int> intVector;
            cout << intVector.at(5); // This will throw out_of_range exception

        } catch (out_of_range& ex) {
            cout << "Inside out of range exception: " << ex.what() << endl;
        } catch (bad_alloc& ex) {
            cout << "Exception thrown is: " << ex.what() << endl;
            cout << "Inside bad_alloc exception.." << endl;
        } catch (divideByZeroException& ex) {
            cout << "Inside custom Exception Handler: " << ex.what() << endl;
        } catch (exception& ex) {
            cout << "Exception is: " << ex.what() << endl;
        } catch (...) {
            cout << "Exception caught in default catch block" << endl;
        }

        cout << "Outside try-catch block" << endl;
    }
};

int main() {
    myClass obj;
    obj.myFunct(5, 0);  // Test divide by zero exception
    // obj.myFunct(5, 2);  // Uncomment to test divide with valid numbers
    // obj.myFunct(5, 10); // Uncomment to test out of range exception

    return 0;
}
