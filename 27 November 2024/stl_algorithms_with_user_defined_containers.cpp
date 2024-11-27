#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Person {
    public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}

    void print() const {
        cout << "Name: " << name << " and Age: " << age << endl;
    }

    bool operator<(const Person& obj) const {
        return age < obj.age;
    }
};

int main(){
    vector<Person> people = {
        Person("Vedant", 22),
        Person("Vanshika", 22),
        Person("Meenal", 24),
        Person("Vegeta", 23),
        Person("Goku", 14),
        Person("Varun", 26),
    };

    sort(people.begin(), people.end());

    for(auto it : people) {
        it.print();
    }
    cout << endl;

    sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
        return p1.name < p2.name;
    });

    for(auto it : people) {
        it.print();
    }
    cout << endl;

    auto it = find_if(people.begin(), people.end(), [](const Person& p) {
        return p.name == "Vegeta";
    });
    if (it != people.end()) {
        cout << "\nFound person: ";
        it->print();
    } else {
        cout << "\nPerson not found" << endl;
    }

    int count = count_if(people.begin(), people.end(), [](const Person& p) {
        return p.age > 25;
    });
    cout << "\nNumber of people older than 25: " << count << endl;

    auto oldest = max_element(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
        return p1.age < p2.age;
    });
    cout << "\nOldest person: ";
    oldest->print();

    int totalAge = accumulate(people.begin(), people.end(), 0, [](int sum, const Person& p) {
        return sum + p.age;
    });
    cout << "\nTotal age: " << totalAge << endl;

    sort(people.begin(), people.end());
    bool isPresent = binary_search(people.begin(), people.end(), Person("", 22), [](const Person& p1, const Person& p2) {
        return p1.age < p2.age;
    });
    cout << "\nIs someone aged 22 present? " << (isPresent ? "Yes" : "No") << endl;
    
    return 0;
}

// Name: Goku and Age: 14
// Name: Vedant and Age: 22
// Name: Vanshika and Age: 22
// Name: Vegeta and Age: 23
// Name: Meenal and Age: 24
// Name: Varun and Age: 26

// Name: Goku and Age: 14
// Name: Meenal and Age: 24
// Name: Vanshika and Age: 22
// Name: Varun and Age: 26
// Name: Vedant and Age: 22
// Name: Vegeta and Age: 23


// Found person: Name: Vegeta and Age: 23

// Number of people older than 25: 1

// Oldest person: Name: Varun and Age: 26

// Total age: 131

// Is someone aged 22 present? Yes