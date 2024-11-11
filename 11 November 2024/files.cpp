#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // For remove and rename functions
using namespace std;

int main() {
    // Create and write to a text file
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "This is the initial text stored in output.txt.\n";
        outFile.close();
    } else {
        cout << "Error opening output.txt for writing!" << endl;
    }

    // Check if file exists
    ifstream fileCheck("output.txt");
    if (fileCheck) {
        cout << "File output.txt exists." << endl;
        fileCheck.close();
    } else {
        cout << "File output.txt does not exist." << endl;
    }

    // Append additional content to the file
    ofstream appendFile("output.txt", ios::app);
    if (appendFile.is_open()) {
        appendFile << "This text is appended to output.txt.\n";
        appendFile.close();
    } else {
        cout << "Error opening output.txt for appending!" << endl;
    }

    // Rename the file
    if (rename("output.txt", "renamed_output.txt") != 0) {
        perror("Error renaming file");
    } else {
        cout << "File successfully renamed to renamed_output.txt." << endl;
    }

    // Read the renamed file's contents
    ifstream inFile("renamed_output.txt");
    string content;
    if (inFile.is_open()) {
        cout << "\nContents of renamed_output.txt:\n";
        while (getline(inFile, content)) {
            cout << content << endl;
        }
        inFile.close();
    } else {
        cout << "Error opening renamed_output.txt for reading!" << endl;
    }

    // Binary file write operation
    ofstream binaryFile("binary_file.bin", ios::binary);
    if (binaryFile.is_open()) {
        int data[] = {1, 2, 3, 4, 5};
        binaryFile.write(reinterpret_cast<char*>(data), sizeof(data)); // reinterpret_cast<char*>(data): Converts the int* (pointer to the integer array) to char*. This reinterpret cast is necessary because write() expects a char* pointer, which points to raw bytes.
        binaryFile.close();
        cout << "\nBinary data written to binary_file.bin." << endl;
    } else {
        cout << "Error creating binary_file.bin for writing!" << endl;
    }

    // Binary file read operation
    ifstream binaryRead("binary_file.bin", ios::binary);
    if (binaryRead.is_open()) {
        int readData[5];
        binaryRead.read(reinterpret_cast<char*>(readData), sizeof(readData));
        binaryRead.close();
        cout << "Data read from binary_file.bin: ";
        for (int i : readData) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "Error opening binary_file.bin for reading!" << endl;
    }

    // Delete the renamed text file
    if (remove("renamed_output.txt") != 0) {
        perror("Error deleting file");
    } else {
        cout << "File renamed_output.txt successfully deleted." << endl;
    }

    return 0;
}

// File output.txt exists.
// File successfully renamed to renamed_output.txt.

// Contents of renamed_output.txt:
// This is the initial text stored in output.txt.
// This text is appended to output.txt.

// Binary data written to binary_file.bin.
// Data read from binary_file.bin: 1 2 3 4 5
// File renamed_output.txt successfully deleted.