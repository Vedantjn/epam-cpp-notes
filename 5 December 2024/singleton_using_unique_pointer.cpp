#include <iostream>
#include <memory>  // For std::unique_ptr
#include <mutex>   // For std::mutex

using namespace std;

class Singleton {
private:
    static unique_ptr<Singleton> instance; // Unique pointer for singleton instance
    static mutex mtx;                      // Mutex for thread safety

    // Private constructor
    Singleton() {
        cout << "Singleton created!" << endl;
    }

public:
    // Static method to get the singleton instance
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx); // Ensure thread safety
        if (!instance) {
            instance = unique_ptr<Singleton>(new Singleton());
            // instance = make_unique<Singleton>();
        }
        return instance.get();
    }

    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }

    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Initialize static members
unique_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    // Both pointers should point to the same instance
    cout << "Are both pointers equal? " 
         << (singleton1 == singleton2 ? "Yes" : "No") 
         << endl;

    return 0;
}
