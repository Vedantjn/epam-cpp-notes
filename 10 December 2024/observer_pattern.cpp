// The Observer Pattern is a behavioral design pattern where one object (the subject) maintains a list of 
// dependents (observers) and notifies them of any state changes, usually by calling one of their methods. 
// This pattern is often used to implement distributed event-handling systems.

// Key Concepts:

// Subject:
// The object being observed.
// Maintains a list of observers and notifies them when its state changes.

// Observer:
// The objects that observe the subject.
// Implement an interface or method that gets called when the subject updates.

// Decoupling:
// Observers and the subject are loosely coupled. The subject doesn't know the concrete implementation of the observers.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer {
public:
    virtual void notify() = 0;
    virtual ~Observer() = default; // Virtual destructor for polymorphism
};

class ConcreteObjectA : public Observer { 
public:
    void notify() override {
        cout << "Overriding notify in ConcreteObjectA" << endl;
    }
};

class ConcreteObjectB : public Observer {
public:
    void notify() override {
        cout << "Overriding notify in ConcreteObjectB" << endl;
    }
};

class Subject {
    vector<Observer*> observerCollection; // Vector of pointers to Observer
public:
    void notifyObservers() {
        for (Observer* observer : observerCollection) {
            observer->notify(); // Call notify on each observer
        }
    }

    void registerObserver(Observer* observer) {
        observerCollection.push_back(observer); // Add observer to the collection
    }

    void unregisterObserver(Observer* observer) {
        observerCollection.erase(
            remove(observerCollection.begin(), observerCollection.end(), observer),
            observerCollection.end()
        ); // Remove observer from the collection
    }
};

int main() {
    Subject subject;

    ConcreteObjectA objA;
    ConcreteObjectB objB;

    // Register observers
    subject.registerObserver(&objA);
    subject.registerObserver(&objB);

    // Notify all observers
    cout << "Notifying all observers:" << endl;
    subject.notifyObservers();

    // Unregister one observer and notify again
    cout << "\nUnregistering ConcreteObjectA and notifying observers again:" << endl;
    subject.unregisterObserver(&objA);
    subject.notifyObservers();

    return 0;
}

// Notifying all observers:
// Overriding notify in ConcreteObjectA
// Overriding notify in ConcreteObjectB

// Unregistering ConcreteObjectA and notifying observers again:
// Overriding notify in ConcreteObjectB