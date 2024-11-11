#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee {
    char name[50];
    int id;
    double salary;
};

int main() {
    Employee emp = {"Vedant Jain", 101, 55000.00};

    // Writing to a binary file
    fstream file("employeee.dat", ios::out | ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        file.close();
    } else {
        cout << "Error opening file for writing!" << endl;
    }

    // Reading from a binary file
    Employee readEmp;
    file.open("employee.dat", ios::in | ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&readEmp), sizeof(readEmp));
        file.close();
        cout << "Name: " << readEmp.name << ", ID: " << readEmp.id << ", Salary: $" << readEmp.salary << endl;
    } else {
        cout << "Error opening file for reading!" << endl;
    }

    return 0;
}

// Name: Vedant Jain, ID: 101, Salary: $55000