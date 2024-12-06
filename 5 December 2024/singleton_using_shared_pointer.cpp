#include <iostream>
#include <memory>  // For std::shared_ptr
#include <mutex>   // For std::mutex

using namespace std;

class Singleton {
private:
    static shared_ptr<Singleton> instance;
    static mutex mtx;                      

    Singleton() {
        cout << "Singleton created!" << endl;
    }

public:
    static shared_ptr<Singleton> getInstance() {
        lock_guard<mutex> lock(mtx); // Ensure thread safety
        if (!instance) {
            // instance = shared_ptr<Singleton>(new Singleton());
            instance = make_shared<Singleton>();
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }

    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Initialize static members
shared_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    auto singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    auto singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    // Both pointers should point to the same instance
    cout << "Are both pointers equal? " 
         << (singleton1 == singleton2 ? "Yes" : "No") 
         << endl;

    return 0;
}
