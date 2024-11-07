#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function to allow overriding
    virtual void sound() const {
        cout << "Some generic animal sound\n";
    }

    // Non-virtual function (cannot be overridden)
    void eat() const {
        cout << "Animal is eating\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    // Overriding the sound function
    void sound() const override {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    // Overriding the sound function
    void sound() const override {
        cout << "Cat meows\n";
    }
};

int main() {
    Animal *animalPtr;

    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->sound();  // Calls Dog's sound function

    animalPtr = &cat;
    animalPtr->sound();  // Calls Cat's sound function

    return 0;
}