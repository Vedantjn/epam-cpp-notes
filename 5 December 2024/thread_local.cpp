// thread_local keyword is used to declare variables that are local to each thread. 
// It ensures that each thread gets its own instance of the variable, which is crucial 
// in multithreaded environments where you want different threads to have separate copies 
// of a variable, rather than sharing a single instance.

#include <iostream>
#include <thread>
using namespace std;

thread_local int counter = 0;  // Thread-local variable

void incrementCounter() {
    counter++;
    cout << "Thread-local counter: " << counter << endl;
}

void threadFunction() {
    for (int i = 0; i < 5; ++i) {
        incrementCounter();
    }
}

int main() {
    thread t1(threadFunction);
    thread t2(threadFunction);

    t1.join();
    t2.join();

    return 0;
}
