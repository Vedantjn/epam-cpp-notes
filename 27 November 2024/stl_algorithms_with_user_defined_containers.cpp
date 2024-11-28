#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Person {
    public:
    string name;
    int age;
    string address; 
    string occupation; 
    Person(string n, int a, string addr, string occ) : name(n), age(a), address(addr), occupation(occ) {}

    void print() const {
        cout << "Name: " << name << ", Age: " << age << ", Address: " << address << ", Occupation: " << occupation << endl;
    }

    bool operator<(const Person& obj) const {
        return age < obj.age;
    }
};

int main(){
    vector<Person> people = {
        Person("Vedant", 22, "123 Street A", "Engineer"),
        Person("Vanshika", 22, "456 Street B", "Doctor"),
        Person("Meenal", 24, "789 Street C", "Artist"),
        Person("Vegeta", 23, "101 Street D", "Warrior"),
        Person("Goku", 14, "202 Street E", "Student"),
        Person("Varun", 26, "303 Street F", "Teacher"),
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
    bool isPresent = binary_search(people.begin(), people.end(), Person("", 22, "", ""), [](const Person& p1, const Person& p2) {
        return p1.age < p2.age;
    });
    cout << "\nIs someone aged 22 present? " << (isPresent ? "Yes" : "No") << endl;
    
    return 0;
}