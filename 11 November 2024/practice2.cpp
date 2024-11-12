// This code converts employee data from a text file to a binary file
#include <iostream>     // For input/output operations
#include <fstream>      // For file handling
#include <sstream>      // For string stream processing
#include <cstring>      // For string manipulation functions
using namespace std;

// Structure to hold employee information
// Each employee has a name, salary, designation, and qualification
struct Employee {
    char name[50];          // Fixed-size array for name (50 characters)
    float salary;           // Floating-point number for salary
    char designation[50];   // Fixed-size array for job title
    char qualification[50]; // Fixed-size array for education/qualifications
};

int main() {
    // Open the input text file (employee.txt) for reading
    // Open the output binary file (employee.dat) for writing
    ifstream inFile("employee.txt");
    ofstream outFile("employee.dat", ios::binary);
    
    // Check if both files opened successfully
    if (!inFile || !outFile) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    // Read the text file line by line
    string line;
    while (getline(inFile, line)) {
        // cout << line << endl;
        Employee emp;               // Create an Employee object
        stringstream ss(line);      // Create a string stream for parsing // // stringstream is used to break down the comma-separated line into individual fields
            // For example, if line = "Vedant,50000,Manager,Btech"
            // stringstream will help extract: name="Vedant", salary=50000, designation="Manager", qualification="Btech"
        string temp;                // Temporary string to hold values
        
        // cout << ss << endl;

        // Parse name (reads until comma)
        // Read characters from stringstream 'ss' until a comma is encountered and store in 'temp'
        getline(ss, temp, ',');
        // Copy the string from 'temp' into emp.name array, leaving space for null terminator
        strncpy(emp.name, temp.c_str(), sizeof(emp.name) - 1);  // c_str() converts C++ string to C-style char array
        emp.name[sizeof(emp.name) - 1] = '\0';  // Ensure null termination        
        // Parse salary (reads until comma)
        getline(ss, temp, ',');
        emp.salary = stof(temp);    // Convert string to float
        
        // Parse designation (reads until comma)
        getline(ss, temp, ',');
        strncpy(emp.designation, temp.c_str(), sizeof(emp.designation) - 1);
        emp.designation[sizeof(emp.designation) - 1] = '\0';
        
        // Parse qualification (reads rest of line)
        getline(ss, temp);
        strncpy(emp.qualification, temp.c_str(), sizeof(emp.qualification) - 1);
        emp.qualification[sizeof(emp.qualification) - 1] = '\0';
        
        // Write the employee record to binary file
        outFile.write(reinterpret_cast<char*>(&emp), sizeof(Employee));        
        // reinterpret_cast<char*>(&emp) converts the memory address of the Employee struct 
        // to a char pointer, which is required by the write() function. It allows writing 
        // the binary data of the struct directly to the file.  
    }
       
    // Close both files
    inFile.close();
    outFile.close();
    
    cout << "Binary file created successfully!" << endl;
    return 0;
}