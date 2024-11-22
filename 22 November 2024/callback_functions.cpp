// A callback function is a function that is passed as an argument to another function or object 
// and is intended to be "called back" at a later point in time during the execution of the program. 
// Callbacks are widely used for event handling, asynchronous operations, or to customize the behavior 
// of a function or class.

// Types of Callback Functions in C++
// Function Pointers
// Functor (Function Object)
// Lambda Expressions
// std::function and std::bind

// 1). Callback using function pointers -> A function pointer can be passed to another function to act as a callback.

#include<iostream>
using namespace std;

void displayMessage(int num) {
    cout << "Callback called with number " << num << endl;
}

void processCallback(void (*callback)(int), int value) {
    cout << "Processing callback...\n";
    callback(value);
}

int main(){
    processCallback(displayMessage, 42);
    return 0;
}

// Processing callback...
// Callback called with number 42

// 2). Callback using Functors -> A functor is a class or struct that overloads the operator().

#include<iostream>
using namespace std;

class CallbackFunctor {
public:
    void operator()(int num) const {
        cout << "Functor callback with number : " << num << endl;
    } 
};

template<typename Callback>
void processCallback(Callback callback, int value) {
    cout << "Processing functor callback...\n";
    callback(value); 
}

int main(){
    CallbackFunctor functor1;
    processCallback(functor1, 99);

    return 0;
}

// Processing functor callback...
// Functor callback with number: 99


// 3. Callback Using Lambda Functions

#include <iostream>
using namespace std;

void processCallback(auto callback, int value) {
    cout << "Processing lambda callback...\n";
    callback(value);
}

int main() {
    processCallback([](int num) {
        cout << "Lambda callback with number: " << num << endl;
    }, 7);
    return 0;
}

// Processing lambda callback...
// Lambda callback with number: 7
