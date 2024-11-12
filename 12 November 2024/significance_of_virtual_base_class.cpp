/*
    Significance of virtual base class

                    Animal
                      ^
                      |
            +---------+---------+
            |                   |
         Mammal               Bird
         virtual             virtual
            |                   |
            +---------+---------+
                      |
                     Bat

Inheritance flowchart shows:
1. Animal is the base class
2. Mammal and Bird virtually inherit from Animal
3. Bat inherits from both Mammal and Bird
4. Virtual inheritance prevents duplicate Animal instances
*/

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    Animal() { cout << "Animal constructor called\n"; }
    virtual ~Animal() { cout << "Animal destructor called\n"; }
    virtual void eat() { cout << "Animal eating\n"; }
};

// Derived class 1
class Mammal : virtual public Animal {
public:
    Mammal() { cout << "Mammal constructor called\n"; }
    ~Mammal() { cout << "Mammal destructor called\n"; }
};

// Derived class 2
class Bird : virtual public Animal {
public:
    Bird() { cout << "Bird constructor called\n"; }
    ~Bird() { cout << "Bird destructor called\n"; }
};

// Multiple inherited class
class Bat : public Mammal, public Bird {
public:
    Bat() { cout << "Bat constructor called\n"; }
    ~Bat() { cout << "Bat destructor called\n"; }
};

int main() {
    cout << "Creating a Bat object...\n";
    Bat bat;
    
    // Without virtual inheritance, this would be ambiguous
    // With virtual inheritance, there's only one Animal instance
    bat.eat();
    
    cout << "\nSize of classes:\n";
    cout << "Animal: " << sizeof(Animal) << " bytes\n";
    cout << "Mammal: " << sizeof(Mammal) << " bytes\n";
    cout << "Bird: " << sizeof(Bird) << " bytes\n";
    cout << "Bat: " << sizeof(Bat) << " bytes\n";
    
    return 0;
}