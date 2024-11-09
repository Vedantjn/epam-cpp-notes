// implementing string functions
#include <bits/stdc++.h>
using namespace std;

class MyString {
    char* p;
    public:
        MyString() {
            p = nullptr;
            cout << "Inside default constructor" << endl;
        }

        MyString(const char* arg) {
            p = new char[strlen(arg) + 1]; // +1 for null terminator
            cout << "Inside parameterised constructor" << endl;
            strcpy(p, arg);
        }

        MyString(const MyString& obj) {
            this->p = new char[strlen(obj.p) + 1];
            strcpy(p, obj.p);
            cout << "Inside copy constructor" << endl;
        }

        MyString& operator=(const MyString& obj) {
            if(this != &obj) { // Self-assignment Check: First checks if this (current object) and obj (object being assigned) are the same. If yes, it skips the assignment to avoid deleting p.
                delete[] p;
                p = new char[strlen(obj.p) + 1];
                strcpy(p, obj.p);
            }
            cout << "Inside assignment operator" << endl;
            return *this;
        }

        ~MyString() {
            delete[] p;
        }

        int lengthOfString() const {
            if (p == nullptr) {
                return 0;
            }
            return strlen(p);
        }

        int numberOfSpecialCharacters() const {
            if (p == nullptr) {
                return 0;
            }
            int count = 0;
            for(int i = 0; i < lengthOfString(); i++) {
                if(!isalnum(p[i])) {
                    count++;
                }
            }
            return count;
        }

        char* reverseString() const {
            if (p == nullptr) {
                return nullptr;
            }
            int len = lengthOfString();
            char* reversedStr = new char[len + 1];
            for(int i = 0; i < len; i++) {
                reversedStr[i] = p[len - i - 1];
            }
            reversedStr[len] = '\0';
            return reversedStr;
        }

        void toUpperCase() {
            if (p == nullptr) {
                return;
            }
            for(int i = 0; i < lengthOfString(); i++) {
                if(p[i] >= 'a' && p[i] <= 'z') {
                    p[i] = p[i] - 'a' + 'A';
                }
            }
        }

        void toLowerCase() {
            if (p == nullptr) {
                return;
            }
            for(int i = 0; i < lengthOfString(); i++) {
                if(p[i] >= 'A' && p[i] <= 'Z') {
                    p[i] = p[i] - 'A' + 'a';
                }
            }
        }

        const char* getString() const {
            return p;
        }
};


int main() {
    MyString str1;
    MyString str2("Hello");
    MyString str3(str2);
    MyString str4("oalngoal#@ngf123");
    
    str1 = str2;

    cout << "Length of string is : " << str1.lengthOfString() << endl;
    cout << "Number of special characters in string : " << str4.numberOfSpecialCharacters() << endl;
    
    char* reversed = str1.reverseString();
    cout << "Reversed string : " << reversed << endl;
    delete[] reversed;

    str2.toUpperCase();
    cout << "Uppercase string : " << str2.getString() << endl;
    
    str2.toLowerCase();
    cout << "Lowercase string : " << str2.getString() << endl;

    str1 = str2 = str3 = str4;
    
    return 0;
}