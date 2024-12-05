#include <iostream>

using namespace std;
 
class Singleton {
private:
    Singleton() {
        cout << "Singleton created!" << endl;
    }
 
public:
    static Singleton& getInstance() {
        static Singleton instance;  // Static local variable ensures a single instance
        return instance;
    }
 
    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }
 
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
 
int main() {
    Singleton& obj1 = Singleton::getInstance();
    Singleton& obj2 = Singleton::getInstance();
 
    obj1.showMessage();
    obj2.showMessage();
 
    cout << "Are both instances the same? " << (&obj1 == &obj2 ? "Yes" : "No") << endl;
 
    return 0;
}

// Singleton created!
// Hello from Singleton!
// Hello from Singleton!
// Are both instances the same? Yes