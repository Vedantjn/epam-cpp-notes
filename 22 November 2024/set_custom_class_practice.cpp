#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    void display() const {
        cout << name << " (" << age << ")" << endl;
    }
};

// sorting Person objects by age
class CompareByAge {
public:
    bool operator()(const Person& p1, const Person& p2) const {
        // Sort by age in ascending order; if ages are equal, sort by name
        if (p1.age == p2.age) {
            return p1.name < p2.name;
        }
        return p1.age < p2.age;
    }
};

int main() {
    // set of Person objects with a custom comparator
    set<Person, CompareByAge> people;

    people.insert(Person("Vedant", 30));
    people.insert(Person("Vanshika", 25));
    people.insert(Person("Samyak", 35));
    people.insert(Person("Meenal", 30)); // Same age as Vedant, but different name

    cout << "People in the set (sorted by age, then name):" << endl;
    for (const auto& person : people) {
        person.display();
    }

    // Try inserting a duplicate (same age and name)
    cout << "\nTrying to insert a duplicate (Vanshika, 25):" << endl;
    auto result = people.insert(Person("Vanshika", 25));
    if (!result.second) {
        cout << "Duplicate not inserted." << endl;
    }

    cout << "\nInserting a new person (Eve, 28):" << endl;
    people.insert(Person("Priyal", 28));

    cout << "\nUpdated set of people:" << endl;
    for (const auto& person : people) {
        person.display();
    }

    return 0;
}

// People in the set (sorted by age, then name):   
// Bob (25)
// Alice (30)
// David (30)
// Charlie (35)

// Trying to insert a duplicate (Bob, 25):
// Duplicate not inserted. 

// Inserting a new person (Eve, 28):

// Updated set of people:  
// Bob (25)
// Eve (28)
// Alice (30)
// David (30)
// Charlie (35)