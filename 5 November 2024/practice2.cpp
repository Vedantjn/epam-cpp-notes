// usecases of strlen, const char* syntax
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // 1: Basic string length
    // Using const char* declares a pointer to a string literal stored in read-only memory
    // We don't need [] here because string literals automatically manage their own memory
    const char* str1 = "Hello World";
    cout << "Length of str1: " << strlen(str1) << endl;
    // 2: Empty string
    const char* str2 = "";
    cout << "Length of empty string: " << strlen(str2) << endl;

    // 3: String with spaces
    char str3[] = "C++ Programming";
    cout << "Length of str3: " << strlen(str3) << endl;

    // 4: String with special characters
    const char* str4 = "Hello\nWorld!";
    cout << "Length of str4: " << strlen(str4) << endl;

    // 5: Character array
    char str5[20] = "Testing strlen";
    cout << "Length of str5: " << strlen(str5) << endl;

    return 0;
}

// Length of str1: 11
// Length of empty string: 0
// Length of str3: 15
// Length of str4: 12
// Length of str5: 14



// The const char* syntax in C++ is used to declare a
//  pointer to a constant character array (a C-style string)

// const char* str = "Hello World";

// const means the characters that str points to are constant and cannot be modified.
// char* means str is a pointer to a character.
// str points to the first character of the string "Hello World", which is stored in 
// read-only memory. Attempting to modify it results in undefined behavior.