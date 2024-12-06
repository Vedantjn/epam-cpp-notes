#include <iostream>
#include <memory> // For std::unique_ptr

class Singleton {
private:
    // Nested class responsible for managing the Singleton instance
    class SingletonHolder {
    public:
        static Singleton& getInstance() {
            static Singleton instance; // Guaranteed to be destroyed at program termination
            return instance;
        }

        static void cleanup() {
            // If additional cleanup logic is needed
            std::cout << "Performing cleanup tasks.\n";
        }
    };

    // Private constructor
    Singleton() {
        std::cout << "Singleton instance created.\n";
    }

    // Destructor
    ~Singleton() {
        std::cout << "Singleton instance destroyed.\n";
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Public method to access the Singleton instance
    static Singleton& getInstance() {
        return SingletonHolder::getInstance();
    }

    // Static cleanup method
    static void cleanup() {
        SingletonHolder::cleanup();
    }

    // Example method
    void doWork() {
        std::cout << "Singleton is doing work.\n";
    }
};

int main() {
    // Access Singleton instance
    Singleton& singleton1 = Singleton::getInstance();
    singleton1.doWork();

    // Access Singleton instance again
    Singleton& singleton2 = Singleton::getInstance();
    singleton2.doWork();

    // Verify both references point to the same instance
    std::cout << "Are singleton1 and singleton2 the same instance? "
              << (&singleton1 == &singleton2 ? "Yes" : "No") << std::endl;

    // Perform cleanup explicitly if needed
    Singleton::cleanup();

    return 0;
}

// Singleton instance created.
// Singleton is doing work.
// Singleton is doing work.
// Are singleton1 and singleton2 the same instance? Yes
// Performing cleanup tasks.
// Singleton instance destroyed.