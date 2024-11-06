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
            p = new char[strlen(obj.p) + 1];
            strcpy(p, obj.p);
            cout << "Inside copy constructor" << endl;
        }

        MyString& operator=(const MyString& obj) {
            if(this != &obj) {
                delete[] p;
                p = new char[strlen(obj.p) + 1];
                strcpy(p, obj.p);
            }
            return *this;
        }

        ~MyString() {
            delete[] p;
        }

        int lengthOfString() {
            if (p == nullptr) {
                return 0;
            }
            int length = 0;
            while (p[length] != '\0') {
                length++;
            }
            return length;
        }

        int numberOfSpecialCharacters() {
            int count = 0;
            for(int i = 0; i < lengthOfString(); i++) {
                if(!isalnum(p[i])) {
                    count++;
                }
            }
            return count;
        }

        const char* reverseString() {
            int len = lengthOfString();
            char* reversedStr = new char[len + 1];
            for(int i = 0; i < len; i++) {
                reversedStr[i] = p[len - i - 1];
            }
            reversedStr[len] = '\0';
            return reversedStr;
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
    cout << "Reversed string : " << str1.reverseString() << endl;

    str1 = str2 = str3 = str4; // when this line gets executed, then all the strings should be updated with the value that is stored in str4, we have to take care of deep copy, make sure we are creating memory for each object whenver we are creating using copy constructor or assignment operator, don't make shallow copy

}