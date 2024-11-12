
#include <iostream>
#include <fstream>
#include <streambuf>

using namespace std;

int main() {
    // Redirect cerr to a log file
    ofstream logFile("error.log");
    streambuf* originalCerr = cerr.rdbuf();
    cerr.rdbuf(logFile.rdbuf());

    // Now cerr will write to the log file
    cerr << "This is an error message" << endl;
    cerr << "Another error occurred" << endl;

    // Example of using custom streambuf
    class CustomBuffer : public streambuf {
    protected:
        virtual int overflow(int c) {
            if (c != EOF) {
                // Convert to uppercase before output
                putchar(toupper(c));
            }
            return c;
        }
    };

    // Using custom buffer
    CustomBuffer customBuf;
    streambuf* oldCout = cout.rdbuf(&customBuf);
    
    cout << "this will be uppercase" << endl;

    // Restore original buffers
    cout.rdbuf(oldCout);
    cerr.rdbuf(originalCerr);

    // Example of reading entire file using streambuf
    ifstream file("sample.txt");
    string content;
    
    file.seekg(0, ios::end);
    content.reserve(file.tellg());
    file.seekg(0, ios::beg);

    content.assign((istreambuf_iterator<char>(file)),
                   istreambuf_iterator<char>());

    return 0;
}

// THIS WILL BE UPPERCASE
// terminate called after throwing an instance of 'std::length_error'
//   what():  basic_string::_M_create