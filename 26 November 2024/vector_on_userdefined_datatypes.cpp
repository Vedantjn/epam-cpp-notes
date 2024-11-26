#include<iostream>
#include<vector>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    void display() const {
        cout << "Name : " << name << " and Age : " << age << endl;
    }

};

int main(){
    vector<Person> people;
    people.emplace_back(Person("Vedant", 22));
    people.emplace_back(Person("Vanshika", 21));
    people.emplace_back(Person("Meenal", 24));
    people.emplace_back("Priyal", 23);
    for(const auto& person : people) {
        person.display();
    }
    
    return 0;
}

// Same with list