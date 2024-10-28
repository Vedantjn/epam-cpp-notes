#include<iostream>
#include<string>
#include<cstring>  // for strlen and strcat
using namespace std;

int main() {
    string str = "";
    char str2[50];

    cout << "Enter the string using getline: \n";
    getline(cin, str);
    cout << "You entered " << str << endl;
    cout << "Length of string using length(): " << str.length() << endl;
    cout << "Length of string using size(): " << str.size() << endl;

    cout << "Enter the string using cin.getline: \n";
    cin.getline(str2, 50);
    cout << "You entered " << str2 << endl;

    // c_str() converts a C++ string object to a C-style string (const char*)
    // This allows compatibility with functions expecting C-style strings
    const char* charPtr = str.c_str();
    cout << "String using c_str(): " << charPtr << endl;
    
    char cstr[100] = "Hello";
    cout << "C-string example: " << cstr << endl;
    cout << "Length of C-string: " << strlen(cstr) << endl;
    strcat(cstr, " World");
    cout << "After concatenation: " << cstr << endl;

    // getline with delimiter
    string str3;
    cout << "Enter text (stops at 'x'): ";
    getline(cin >> ws, str3, 'x');
    cout << "You entered: " << str3 << endl;

    // ws is an I/O manipulator that consumes any leading whitespace
    // (spaces, tabs, or newlines) in the input stream (cin) before 
    // reading the actual content. This ensures that if there are leftover
    // spaces or newlines from previous input, they are ignored.
    // Here, cin >> ws makes sure that getline starts reading directly after
    // any whitespace is skipped.
    
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << endl;

    cout << "This is cout example" << endl;
    cout << "Multiple values: " << 42 << " " << 3.14 << " " << "Hello" << endl;

    cerr << "This is an error message" << endl;
    
    return 0;
}
// Enter the string using getline: 
// My name is Vedant
// You entered My name is Vedant
// Length of string using length(): 17
// Length of string using size(): 17
// Enter the string using cin.getline:
// I am Vednt
// You entered I am Vednt

// String using c_str(): My name is Vedant
// C-string example: Hello
// Length of C-string: 5
// After concatenation: Hello World