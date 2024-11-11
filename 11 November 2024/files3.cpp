
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Various fstream operations
    
    // 1. Basic file creation and writing
    fstream file("file3_file.txt", ios::out);
    if (file.is_open()) {
        file << "Hello, this is line 1" << endl;
        file << "This is line 2" << endl;
        file << "This is line 3" << endl;
        file.close();
    }

    // 2. Appending to file
    fstream appendFile("file3_file.txt", ios::app);
    if (appendFile.is_open()) {
        appendFile << "This line is appended" << endl;
        appendFile.close();
    }

    // 3. Reading from file
    fstream readFile("file3_file.txt", ios::in);
    if (readFile.is_open()) {
        string line;
        cout << "Reading file contents:" << endl;
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    }

    // 4. Combined reading and writing with positioning
    fstream rwFile("file3_file.txt", ios::in | ios::out);
    if (rwFile.is_open()) {
        // Move to end of file to append
        rwFile.seekp(0, ios::end);
        rwFile << "New line added at end" << endl;

        // Move back to beginning to read
        rwFile.seekg(0, ios::beg);
        string line;
        cout << "\nReading updated contents:" << endl;
        while (getline(rwFile, line)) {
            cout << line << endl;
        }

        // Demonstrate file state checking
        cout << "\nFile State Information:" << endl;
        cout << "EOF reached: " << (rwFile.eof() ? "Yes" : "No") << endl;
        cout << "File is good: " << (rwFile.good() ? "Yes" : "No") << endl;
        
        rwFile.close();
    }

    // 5. Binary file operations
    fstream binFile("binary.dat", ios::binary | ios::out);
    if (binFile.is_open()) {
        int numbers[] = {1, 2, 3, 4, 5};
        binFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
        binFile.close();
    }

    // Reading binary file
    fstream readBin("binary.dat", ios::binary | ios::in);
    if (readBin.is_open()) {
        int numbers[5];
        readBin.read(reinterpret_cast<char*>(numbers), sizeof(numbers));
        cout << "\nBinary file contents:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        readBin.close();
    }

    return 0;
}


// Reading file contents:
// Hello, this is line 1
// This is line 2
// This is line 3
// This line is appended

// Reading updated contents:
// Hello, this is line 1
// This is line 2
// This is line 3
// This line is appended
// New line added at end

// File State Information:
// EOF reached: Yes
// File is good: No

// Binary file contents:
// 1 2 3 4 5


/*
fstream Library in C++
=====================

fstream is a C++ class for file input/output operations, part of the <fstream> header.
It combines capabilities of both reading and writing to files in a single object.

Key Components:
--------------
1. Main Classes:
   - ifstream: Input file operations
   - ofstream: Output file operations
   - fstream: Combined input/output operations

2. File Opening Modes:
   - ios::in    - Reading
   - ios::out   - Writing (truncates existing file)
   - ios::app   - Append mode
   - ios::trunc - Truncate existing file
   - ios::binary - Binary mode

3. File Operations:
   - Opening: file.open("filename", mode)
   - Writing: file << "data"
   - Reading: getline(file, string) or file >> variable
   - Closing: file.close()

4. Position Functions:
   - seekg() - Set input position
   - seekp() - Set output position
   - tellg() - Get input position
   - tellp() - Get output position

seekg(offset, direction): Sets the position of the get pointer (read pointer).
seekp(offset, direction): Sets the position of the put pointer (write pointer).
tellg(): Returns the current position of the get pointer.
tellp(): Returns the current position of the put pointer.

5. State Checking:
   - is_open() - Check if file is open
   - eof() - Check for end of file
   - fail() - Check for operation failure
   - good() - Check if operations successful
   - bad() - Check for fatal errors

Best Practices:
--------------
1. Always check if file opened successfully
2. Close files after operations
3. Use appropriate modes for operations
4. Handle errors appropriately
5. Use binary mode for non-text files
*/
