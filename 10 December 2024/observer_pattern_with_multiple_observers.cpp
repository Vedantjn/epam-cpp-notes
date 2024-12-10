#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Base Observer1 interface
class Observer1 {
public:
    virtual void notify1() = 0;  // Unique method for Observer1
    virtual ~Observer1() = default;
};

// Base Observer2 interface
class Observer2 {
public:
    virtual void notify2() = 0;  // Unique method for Observer2
    virtual ~Observer2() = default;
};

// Concrete implementation of Observer1
class ConcreteObserver1 : public Observer1 {
public:
    void notify1() override {
        cout << "ConcreteObserver1 received notify1!" << endl;
    }
};

// Concrete implementation of Observer2
class ConcreteObserver2 : public Observer2 {
public:
    void notify2() override {
        cout << "ConcreteObserver2 received notify2!" << endl;
    }
};

// Subject class managing multiple types of observers
class Subject {
    vector<Observer1*> observer1Collection; // Collection of Observer1 pointers
    vector<Observer2*> observer2Collection; // Collection of Observer2 pointers

public:
    // Notify all Observer1 instances
    void notifyObserver1() {
        for (Observer1* observer : observer1Collection) {
            observer->notify1();
        }
    }

    // Notify all Observer2 instances
    void notifyObserver2() {
        for (Observer2* observer : observer2Collection) {
            observer->notify2();
        }
    }

    // Register an Observer1
    void registerObserver1(Observer1* observer) {
        observer1Collection.push_back(observer);
    }

    // Register an Observer2
    void registerObserver2(Observer2* observer) {
        observer2Collection.push_back(observer);
    }

    // Unregister an Observer1
    void unregisterObserver1(Observer1* observer) {
        observer1Collection.erase(
            remove(observer1Collection.begin(), observer1Collection.end(), observer),
            observer1Collection.end()
        );
    }

    // Unregister an Observer2
    void unregisterObserver2(Observer2* observer) {
        observer2Collection.erase(
            remove(observer2Collection.begin(), observer2Collection.end(), observer),
            observer2Collection.end()
        );
    }
};

int main() {
    Subject subject;

    // Create instances of ConcreteObserver1 and ConcreteObserver2
    ConcreteObserver1 observer1_1, observer1_2;
    ConcreteObserver2 observer2_1, observer2_2;

    // Register observers with the Subject
    subject.registerObserver1(&observer1_1);
    subject.registerObserver1(&observer1_2);
    subject.registerObserver2(&observer2_1);
    subject.registerObserver2(&observer2_2);

    // Notify each type of observer
    cout << "Notifying all Observer1 instances:" << endl;
    subject.notifyObserver1();

    cout << "\nNotifying all Observer2 instances:" << endl;
    subject.notifyObserver2();

    // Unregister one observer from each type and notify again
    cout << "\nUnregistering one Observer1 and one Observer2:" << endl;
    subject.unregisterObserver1(&observer1_1);
    subject.unregisterObserver2(&observer2_1);

    cout << "Notifying all Observer1 instances again:" << endl;
    subject.notifyObserver1();

    cout << "\nNotifying all Observer2 instances again:" << endl;
    subject.notifyObserver2();

    return 0;
}

// Notifying all Observer1 instances:
// ConcreteObserver1 received notify1!
// ConcreteObserver1 received notify1!

// Notifying all Observer2 instances:
// ConcreteObserver2 received notify2!
// ConcreteObserver2 received notify2!

// Unregistering one Observer1 and one Observer2:
// Notifying all Observer1 instances again:
// ConcreteObserver1 received notify1!

// Notifying all Observer2 instances again:
// ConcreteObserver2 received notify2!