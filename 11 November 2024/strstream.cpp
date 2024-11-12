// strstream in C++
#include <iostream>
#include <strstream>
using namespace std;

/*
 * The strstream class provides in-memory string-based I/O operations
 * Part of <strstream> header (deprecated - prefer <sstream> in modern C++)
 */

// Main components of strstream:
class StrStream {
public:
    // 1. Output Operations
    void demonstrateOutput() {
        ostrstream outStream;
        int num = 42;
        double pi = 3.14159;
        outStream << "Number: " << num << ", Pi: " << pi << ends;
        
        char* str = outStream.str();
        cout << "Output string: " << str << endl;
        
        outStream.freeze(false);
        delete[] str;
    }
    
    // 2. Input Operations
    void demonstrateInput() {
        char inputData[] = "123 45.67";
        istrstream inStream(inputData);
        
        int intValue;
        double doubleValue;
        inStream >> intValue >> doubleValue;
        
        cout << "Extracted int: " << intValue << ", double: " << doubleValue << endl;
    }
};

int main() {
    StrStream str;
    
    cout << "=== Output Demo ===" << endl;
    str.demonstrateOutput();
    
    cout << "\n=== Input Demo ===" << endl;
    str.demonstrateInput();
    
    return 0;
}

/*
 * Key Points:
 * 1. Three main classes:
 *    - ostrstream: Output operations
 *    - istrstream: Input operations
 *    - strstream: Both input and output
 * 
 * 2. Memory Management:
 *    - Manual memory management required
 *    - Use freeze(false) before deallocation
 *    - Remember to delete[] dynamically allocated buffers
 * 
 * 3. Modern Alternative:
 *    - Use stringstream from <sstream>
 *    - Provides better memory management
 *    - More modern and safer approach
 */

// -----------------------------------------------------------------------

#include <iostream>
#include <sstream>
using namespace std;

class StrStream {
public:
    // 1. Output Operations
    void demonstrateOutput() {
        stringstream outStream;
        int num = 42;
        double pi = 3.14159;
        outStream << "Number: " << num << ", Pi: " << pi;
        
        // Get the output string directly without worrying about memory management
        string str = outStream.str();
        cout << "Output string: " << str << endl;
    }
    
    // 2. Input Operations
    void demonstrateInput() {
        string inputData = "123 45.67";
        stringstream inStream(inputData);
        
        int intValue;
        double doubleValue;
        inStream >> intValue >> doubleValue;
        
        cout << "Extracted int: " << intValue << ", double: " << doubleValue << endl;
    }
};

int main() {
    StrStream str;
    
    cout << "=== Output Demo ===" << endl;
    str.demonstrateOutput();
    
    cout << "\n=== Input Demo ===" << endl;
    str.demonstrateInput();
    
    return 0;
}

// === Output Demo ===
// Output string: Number: 42, Pi: 3.14159

// === Input Demo ===
// Extracted int: 123, double: 45.67

// --------------------------------------------------------

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // 1. Basic Input (String to Stream)
    stringstream ss1("Hello 42 3.14");
    string word;
    int number;
    double pi;
    ss1 >> word >> number >> pi;  // Extracts space-separated values
    cout << "Word: " << word << ", Number: " << number << ", Pi: " << pi << endl;

    // 2. Basic Output (Stream to String)
    stringstream ss2;
    ss2 << "Age: " << 25 << ", Name: " << "John";  // Writing to stream
    string result = ss2.str();  // Get the entire string
    cout << result << endl;

    // 3. Number to String Conversion
    int num = 123;
    stringstream ss3;
    ss3 << num;
    string str_num = ss3.str();
    cout << "Number as string: " << str_num << endl;

    // 4. String to Number Conversion
    string str_value = "456";
    stringstream ss4(str_value);
    int value;
    ss4 >> value;
    cout << "String as number: " << value << endl;

    // 5. Parsing Comma-Separated Values
    stringstream ss5("apple,banana,orange");
    string fruit;
    while(getline(ss5, fruit, ',')) {
        cout << "Fruit: " << fruit << endl;
    }

    // 6. Clearing and Reusing Stringstream
    stringstream ss6;
    ss6 << "First";
    cout << ss6.str() << endl;
    
    ss6.str("");  // Clear content
    ss6.clear();  // Clear error flags
    
    ss6 << "Second";
    cout << ss6.str() << endl;

    // 7. Mixed Data Types
    stringstream ss7;
    ss7 << "Score " << 95.5 << " Rank " << 1;
    string word1, word2;
    double score;
    int rank;
    ss7 >> word1 >> score >> word2 >> rank;
    cout << word1 << ": " << score << ", " << word2 << ": " << rank << endl;

    // 8. Check for Conversion Success
    string test = "123abc";
    stringstream ss8(test);
    int number2;
    if(ss8 >> number2) {
        cout << "Successfully converted: " << number2 << endl;
    }
    
    // 9. Reading Until Space vs getline
    stringstream ss9("Hello World! How are you?");
    string word3, line;
    ss9 >> word3;  // Reads just "Hello"
    cout << "Single word: " << word3 << endl;
    
    // Reset stream position
    ss9.seekg(0);
    getline(ss9, line);  // Reads entire line
    cout << "Entire line: " << line << endl;

    // 10. Formatting Numbers
    double value2 = 123.456789;
    stringstream ss10;
    ss10 << fixed << setprecision(2) << value2;
    cout << "Formatted number: " << ss10.str() << endl;

    return 0;
}

// Word: Hello, Number: 42, Pi: 3.14
// Age: 25, Name: John
// Number as string: 123
// String as number: 456
// Fruit: apple
// Fruit: banana
// Fruit: orange
// First
// Second
// Score: 95.5, Rank: 1
// Successfully converted: 123
// Single word: Hello
// Entire line: Hello World! How are you?
// Formatted number: 123.46