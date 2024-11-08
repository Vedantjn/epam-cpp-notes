#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char* p = "kjsdnfgkjsngf";
    
    cout << "Length of string literal p points to: " << strlen(p) << " characters" << endl;

    p = new char[strlen("hello") + 1];  // +1 for the null terminator
    // strcpy(const_cast<char*>(p), "hello");

    cout << "Length of new string: " << strlen(p) << " characters" << endl;

    delete[] p;

    return 0;
}

// Length of string literal p points to: 13 characters
// Length of new string: 5 characters
