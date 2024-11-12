#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("output.txt");
    streambuf *original = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());

    // Your output statements would go here
    cout << "This text will be written to the file" << endl;

    // restore
    cout.rdbuf(original);
    outFile.close();

    return 0;
}
