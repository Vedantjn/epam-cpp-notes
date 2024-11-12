// This program demonstrates redirecting cout to write to a file
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Create an output file stream
    ofstream outFile("outputFromFiles1.txt");
    
    // Save the original cout buffer
    streambuf *original = cout.rdbuf();
    
    // Redirect cout to write to the file
    cout.rdbuf(outFile.rdbuf());

    // Any cout statements here will write to the file instead of console
    cout << "This text will be written to the file" << endl;

    // Restore cout to write to console again
    cout.rdbuf(original);
    
    // Close the file
    outFile.close();

    return 0;
}
