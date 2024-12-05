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
#include <memory> // For std::shared_ptr and std::unique_ptr

using namespace std;

class Singleton {
private:
    static shared_ptr<Singleton> instance; // Shared pointer to manage the instance

    // Private constructor to prevent direct instantiation
    Singleton() {
        cout << "Singleton Instance Created.\n";
    }

    // Private destructor
    ~Singleton() {
        cout << "Singleton Instance Destroyed.\n";
    }

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public static method to access the instance
    static shared_ptr<Singleton> getInstance() {
        if (!instance) {
            instance = shared_ptr<Singleton>(new Singleton());
        }
        return instance;
    }

    void doWork() {
        cout << "Singleton is doing work.\n";
    }
};

shared_ptr<Singleton> Singleton::instance = nullptr;

int main() {
    auto singleton = Singleton::getInstance();
    singleton->doWork();

    // Cleanup is handled automatically when the shared pointer goes out of scope
    return 0;
}
