
#include <iostream>
using namespace std;

void handleException() {
    try {
        throw "Original exception";
    }
    catch (const char* ex) {
        cout << "Caught in handleException: " << ex << endl;
        throw; // rethrowing the same exception
    }
}

int main() {
    try {
        // 1: Simple throwing
        cout << "1: Simple throwing" << endl;
        throw runtime_error("This is a runtime error");
    }
    catch (const runtime_error& e) {
        cout << "Caught runtime error: " << e.what() << endl;
    }

    cout << "\2: Rethrowing demonstration" << endl;
    try {
        handleException();
    }
    catch (const char* ex) {
        cout << "Caught in main: " << ex << endl;
    }

    // 3: Multiple exception types
    try {
        cout << "\3: Multiple exception types" << endl;
        int choice;
        cout << "Enter 1 for int exception, 2 for char exception: ";
        cin >> choice;

        if (choice == 1) {
            throw 42;
        } else {
            throw 'X';
        }
    }
    catch (int e) {
        cout << "Integer exception caught: " << e << endl;
    }
    catch (char c) {
        cout << "Character exception caught: " << c << endl;
    }
    catch (...) {
        cout << "Default exception handler" << endl;
    }

    return 0;
}
