#include <iostream>
#include <set>
#include <string>

using namespace std;

// User-defined class
class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string n, int a) : name(n), age(a) {}

    // Display function
    void display() const {
        cout << name << " (" << age << ")" << endl;
    }
};

// Custom comparator for sorting Person objects by age
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
    // Declare a set of Person objects with a custom comparator
    set<Person, CompareByAge> people;

    // Insert Person objects into the set
    people.insert(Person("Alice", 30));
    people.insert(Person("Bob", 25));
    people.insert(Person("Charlie", 35));
    people.insert(Person("David", 30)); // Same age as Alice, but different name

    // Display the elements in the set
    cout << "People in the set (sorted by age, then name):" << endl;
    for (const auto& person : people) {
        person.display();
    }

    // Try inserting a duplicate (same age and name)
    cout << "\nTrying to insert a duplicate (Bob, 25):" << endl;
    auto result = people.insert(Person("Bob", 25));
    if (!result.second) {
        cout << "Duplicate not inserted." << endl;
    }

    // Insert another unique person
    cout << "\nInserting a new person (Eve, 28):" << endl;
    people.insert(Person("Eve", 28));

    // Display the updated set
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