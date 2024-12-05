// #include <iostream>
// #include <cstdlib> // For std::atexit

// using namespace std;

// class Singleton {
// private:
//     static Singleton* instance; // Pointer to the single instance

//     // Private constructor to prevent direct instantiation
//     Singleton() {
//         cout << "Singleton Instance Created.\n";
//     }

//     // Private destructor
//     ~Singleton() {
//         cout << "Singleton Instance Destroyed.\n";
//     }

// public:
//     // Delete copy constructor and assignment operator
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;

//     // Public static method to access the instance
//     static Singleton* getInstance() {
//         if (!instance) {
//             instance = new Singleton();
//             atexit(&cleanup); // Register cleanup at program exit
//         }
//         return instance;
//     }

//     // Method to perform cleanup (called by atexit)
//     static void cleanup() {
//         delete instance;
//         instance = nullptr;
//     }

//     void doWork() {
//         cout << "Singleton is doing work.\n";
//     }
// };

// // Initialize static member
// Singleton* Singleton::instance = nullptr;

// int main() {
//     Singleton* singleton = Singleton::getInstance();
//     singleton->doWork();

//     // Optional manual cleanup
//     // Singleton::cleanup();

//     return 0;
// }

// // Singleton Instance Created.
// // Singleton is doing work.
// // Singleton Instance Destroyed.

// // ----------------------------------------------
  
#include <iostream>
#include <memory>  // For std::unique_ptr
#include <mutex>   // For std::mutex
 
using namespace std;
 
class Singleton {
private:
    static unique_ptr<Singleton> instance;
    static mutex mtx;  // Mutex for thread safety
 
    Singleton() {
        cout << "Singleton created!" << endl;
    }
 
public:
    static Singleton* getInstance() {
        // Lock the mutex to ensure thread safety during initialization
        lock_guard<mutex> lock(mtx);
        if (instance == nullptr) {
            instance = make_unique<Singleton>();
        }
        return instance.get();  // Returning the raw pointer to the object because can't return unique ptr when return type is a raw pointer , by using unique ptr there may be chanches that it may transfer the ownership
    }
 
    void showMessage() {
       cout << "Hello from Singleton!" << endl;
    }
 
    Singleton(const Singleton&) = delete;  // Prevent copying
    Singleton& operator=(const Singleton&) = delete;  // Prevent assignment
};
 
// Initialize the static members
unique_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::mtx;
 
int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();
 
    // No need to manually delete the instance, unique_ptr will take care of that
    return 0;
}