#include<iostream>
using namespace std;

class MyInt {
private:
    int value;

public:
    MyInt(int v = 0) : value(v) {}

    // Assignment operator for int
    MyInt& operator=(int x) {
        value = x;
        return *this;
    }

    // Assignment operator for string
    MyInt& operator=(const string& s) {
        cout << "Inside string to int assignment\n";
        value = stoi(s);
        return *this;
    }

    // Getter
    int getValue() const { return value; }
};

int main() {
    string str = "42";
    int var = 20;
    MyInt a;

    str = to_string(20);
    a = str;
    cout << "Value: " << a.getValue() << endl;

    return 0;
}