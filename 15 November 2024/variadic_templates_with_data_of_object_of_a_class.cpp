
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    float gpa;

public:
    Student(string n, int a, float g) : name(n), age(a), gpa(g) {}
    
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

template<typename T>
void printStudents(T student) {
    student.display();
}

template<typename T, typename... Args>
void printStudents(T firstStudent, Args... remainingStudents) {
    firstStudent.display();
    printStudents(remainingStudents...);
}

int main() {
    Student s1("Vedant", 20, 3.8);
    Student s2("Vanshika", 21, 3.9);
    Student s3("Paridhi", 19, 3.7);
    Student s4("Kartik", 22, 3.6);

    cout << "Student Information:" << endl;
    printStudents(s1, s2, s3, s4);

    return 0;
}

// Student Information:
// Name: Vedant, Age: 20, GPA: 3.8
// Name: Vanshika, Age: 21, GPA: 3.9
// Name: Paridhi, Age: 19, GPA: 3.7
// Name: Kartik, Age: 22, GPA: 3.6

