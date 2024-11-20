// This code demonstrates a thread-safe Singleton pattern implemented 
// using std::shared_ptr in C++. A Singleton ensures that only
//  one instance of a class is created and provides a global access 
//  point to that instance. This implementation includes thread safety 
//  for use in multithreaded environments.

#include<iostream>
#include<memory>
#include<mutex>
using namespace std;

class Singleton {
private:
    static shared_ptr<Singleton> instance;
    static mutex mtx;

    Singleton() {
        cout << "Singleton instance created\n";
    }
    Singleton(const Singleton&) = delete;
    Singleton operator=(const Singleton&) = delete;

public:
    static shared_ptr<Singleton> getInstance() {
        // First check if instance exists - not thread safe but quick
        if(instance == nullptr) {
            // If instance might be null, lock mutex for thread safety
            lock_guard<mutex> lock(mtx);
            // Double-check instance is still null after getting lock
            if(instance == nullptr) {
                // Create new instance using shared_ptr
                instance = shared_ptr<Singleton>(new Singleton());
            }
        }
        // Return the single instance
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton\n";
    }
};

shared_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::mtx;

int main(){

    shared_ptr<Singleton> s1 = Singleton::getInstance();
    s1->showMessage();

    shared_ptr<Singleton> s2 = Singleton::getInstance();
    s2->showMessage();

    if(s1 == s2) {
        cout << "Both instances are same.\n";
    }
    else {
        cout << "Different instances exist!.\n";
    }
    
    return 0;
}

// Singleton instance created.
// Hello from Singleton!
// Hello from Singleton!
// Both instances are the same.
