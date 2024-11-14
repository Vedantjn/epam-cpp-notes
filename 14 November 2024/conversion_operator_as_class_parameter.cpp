#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
class MyString;

class MyInt {
private:
    int value;

public:
    // Constructor
    MyInt(int v) : value(v) {}

    // Conversion operator: Convert MyInt to MyString
    operator MyString() const;

    // Getter
    int getValue() const { return value; }
};

class MyString {
private:
    string str;

public:
    // Constructor
    MyString(const string& s) : str(s) {}

    // Conversion operator: Convert MyString to MyInt
    operator MyInt() const {
        return MyInt(stoi(str)); // Convert string to int
    }

    // Getter
    string getStr() const { return str; }
};

// Definition of MyInt's conversion operator to MyString
MyInt::operator MyString() const {
    return MyString(to_string(value)); // Convert int to string
}

// Test functions
void printConversion(const MyString& myStr) {
    cout << "MyString: " << myStr.getStr() << endl;
}

void printConversion(const MyInt& myInt) {
    cout << "MyInt: " << myInt.getValue() << endl;
}

int main() {
    // Instantiate MyInt and convert it to MyString
    MyInt myInt(42);
    MyString myStr = myInt; // Uses MyInt's conversion to MyString
    printConversion(myStr);

    // Instantiate MyString and convert it to MyInt
    MyString myStr2("123");
    MyInt myInt2 = myStr2; // Uses MyString's conversion to MyInt
    printConversion(myInt2);

    return 0;
}

// MyString: 42
// MyInt: 123