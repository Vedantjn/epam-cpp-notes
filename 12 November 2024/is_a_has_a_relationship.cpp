#include <iostream>
using namespace std;

// Theory: Is-A and Has-A Relationships in OOP
/*
In Object-Oriented Programming (OOP), there are two fundamental relationships:

1. Is-A Relationship (Inheritance):
   - Represents inheritance between classes
   - A subclass inherits from a base class
   - Example: Dog is an Animal

2. Has-A Relationship (Composition):
   - Represents composition/aggregation
   - A class contains instance(s) of another class
   - Example: Car has an Engine
*/

// Is-A Relationship
class Animal {
public:
    void eat() {
        cout << "Eating" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking" << endl;
    }
};

// Has-A Relationship
class Engine {
public:
    void start() {
        cout << "Engine started" << endl;
    }
};

class Car {
private:
    Engine engine; // Car has an Engine
public:
    void startCar() {
        engine.start();
        cout << "Car started" << endl;
    }
};

int main() {
    // Is-A relationship
    cout << "\nDemonstrating Is-A Relationship:" << endl;
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.bark(); // Dog's own method

    // Has-A relationship
    cout << "\nDemonstrating Has-A Relationship:" << endl;
    Car car;
    car.startCar();

    return 0;
}

// Demonstrating Is-A Relationship:
// Eating
// Barking

// Demonstrating Has-A Relationship:
// Engine started
// Car started