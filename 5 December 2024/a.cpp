#include <iostream>
#include <memory>  // For std::unique_ptr
#include <mutex>   // For std::mutex
using namespace std;
class Singleton {
private:
    static unique_ptr<Singleton> instance;
    static mutex mtx;  // Mutex for thread safety
    // Private constructor
    Singleton() {
        cout << "Singleton created!" << endl;
    }
public:
    // Static method to get the Singleton instance
    static unique_ptr<Singleton> &getInstance() {
        // Lock the mutex to ensure thread safety during initialization
        lock_guard<mutex> lock(mtx);
        if (instance == nullptr) {
            instance.reset(new Singleton()); //  Use reset with new instead of make_unique
            // instance = make_unique<Singleton>();
        }
        // return instance.get(); // Return raw pointer as requested
        return instance; 
    }
    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }
    // Delete copy constructor and copy assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
// Initialize static members
unique_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    unique_ptr<Singleton> singleton(Singleton::getInstance());

    singleton->showMessage();
    // No need to manually delete the instance, unique_ptr will take care of that
    return 0;
}