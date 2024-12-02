#include <iostream>
#include <thread>
 
using namespace std;
 
void printMessage(const string& message) {
    cout << message << endl;
}
 
int main() {
    // Create a thread to execute the printMessage function
    thread thrd1(printMessage, "Hello from a thread!");
 
    // Wait for the thread to complete
    thrd1.join();
 
    return 0;
}