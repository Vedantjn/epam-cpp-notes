// The Singleton Design Pattern ensures that only one instance of a class exists 
// during the lifetime of an application and provides a global point of access to 
// that instance. In a multithreaded environment, we ensure thread safety using 
// either the Meyers Singleton pattern (which is thread-safe by default) or by 
// using a mutex to synchronize access to the instance creation.


#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    // Private constructor to prevent instantiation
    Singleton() {
        cout << "Singleton instance created!" << endl;
    }

public:
    // Deleting the copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public static method to access the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx);  // Lock the mutex to ensure thread safety
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    // Example method
    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }
};

// Initialize the static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    // Attempt to get the singleton instance and call its method
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    // Attempt to get the singleton instance again and call its method
    Singleton* singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    // Checking if both instances are the same
    if (singleton1 == singleton2) {
        cout << "Both instances are the same!" << endl;
    }

    return 0;
}

// Singleton instance created!
// Hello from Singleton!
// Hello from Singleton!
// Both instances are the same!