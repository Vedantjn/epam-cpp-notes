#include<iostream>
using namespace std;

template <typename A, typename B>
void swapItems(A a, B b) {
    B temp = b;
    b = a;
    a = temp;
}

int main(){
    int age = 22;
    string name = "Vedant's age is : ";

    cout << age << " " << name << endl;
    swapItems(age, name);
    cout << age << " " << name << endl;


    return 0;
}

// ---------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

template <typename T>
void swapItems(T& a, T& b) { 
    T temp = b;
    b = a;
    a = temp;
}

int main() {
    int age = 22;
    int num = 45;
    string name = "Vedant's age is : ";
    string text = "Hello World";

    cout << "Before swap:" << endl;
    cout << "age = " << age << ", num = " << num << endl;
    cout << "name = " << name << ", text = " << text << endl;

    swapItems(age, num);         
    swapItems(name, text);   

    cout << "After swap:" << endl;
    cout << "age = " << age << ", num = " << num << endl;
    cout << "name = " << name << ", text = " << text << endl;

    return 0;
}

// Before swap:
// age = 22, num = 45
// name = Vedant's age is : , text = Hello World
// After swap:
// age = 45, num = 22
// name = Hello World, text = Vedant's age is :