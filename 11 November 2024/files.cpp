#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream outFile("output.txt");
    outFile << "This is the text that I want to store in output.txt";
    outFile.close();

    ifstream inFile("output.txt");
    string content;
    if(inFile.is_open()) {
        while(getline(inFile, content)) {
            cout << content << endl;
        }
        inFile.close();
    }

    return 0;
}