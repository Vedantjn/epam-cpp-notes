// The double-checked locking pattern is a common approach in implementing a thread-safe singleton in C++. 
// It ensures that the singleton instance is created only once and avoids the overhead of locking every time 
// the instance is accessed.

// First Check: The singleton instance is checked without locking to avoid overhead when it is already initialized.
// Locking: If the instance is not initialized, the code acquires a lock to ensure only one thread can initialize the instance.
// Second Check: After acquiring the lock, the instance is checked again to ensure another thread hasn’t already created it.

#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance; // Pointer to the singleton instance
    static mutex mtx;      // Mutex for thread safety

    // Private constructor to prevent external instantiation
    Singleton() {
        cout << "Singleton instance created.\n";
    }

public:
    // Deleted copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public method to get the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) { // First check (without locking)
            lock_guard<mutex> lock(mtx); // Acquire the lock
            if (instance == nullptr) {            // Second check (with locking)
                instance = new Singleton();
            }
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton!\n";
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->showMessage();
    s2->showMessage();

    cout << "Are s1 and s2 the same? " << (s1 == s2 ? "Yes" : "No") << endl;

    return 0;
}

// Singleton instance created.
// Hello from Singleton!
// Hello from Singleton!
// Are s1 and s2 the same? Yes