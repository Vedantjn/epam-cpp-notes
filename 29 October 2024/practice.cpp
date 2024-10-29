#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s1 = "World!";
    s1.resize(15, '*');
    cout << "After resizing to 15 with '*': " << s1 << " (Size: " << s1.size() << ")" << endl;
    // After resizing to 15 with '*': World!********* (Size: 15)

    // Basic string to stringstream
    stringstream ss1;      // Create a stringstream object named ss
    ss1 << "Hello" << " " << 42 << " " << 3.14;    // Insert multiple values into stream: text, number, and float
    string result;        // Create string to store extracted value
    ss1 >> result;        // Extract first word from stream into result
    cout << "First word: " << result << endl;      // Print only "Hello" since >> operator reads until whitespace
    // First word: Hello

    // Basic string to stringstream
    stringstream ss2;      // Create a stringstream object named ss
    ss2 << "Hello" << " " << 42 << " " << 3.14;    // Insert multiple values into stream: text, number, and float
    string word;         // Create string to store extracted value
    while (ss2 >> word) { // Extract each word until stream is empty
        cout << "Word: " << word << endl;
    }
    // Word: Hello
    // Word: 42
    // Word: 3.14
    
    // Converting numbers to string
    stringstream converter;
    int num = 123;
    converter << num;
    string str = converter.str();
    cout << "Number to string: " << str << endl;
    // Number to string: 123
    
    // String to number conversion
    stringstream parser;
    parser.str("456");
    int value;
    parser >> value;
    cout << "String to number: " << value << endl;
    // String to number: 456
    
    // Multiple extractions
    stringstream multi("Apple Orange 42 3.14");
    string fruit1, fruit2;
    int number;
    double pi;
    multi >> fruit1 >> fruit2 >> number >> pi;
    cout << "Parsed values: " << fruit1 << ", " << fruit2 << ", " << number << ", " << pi << endl;
    // Parsed values: Apple, Orange, 42, 3.14
    
    // Clearing stringstream
    multi.clear();
    multi.str("");
    
    // Format manipulation
    stringstream formatter;
    formatter << hex << 255;
    string hexStr = formatter.str();
    cout << "Hex value: " << hexStr << endl;
    // Hex value: ff
    // The hexadecimal value FF represents the decimal value 255.
    
    // Line by line processing
    stringstream lines;
    lines.str("Line1\nLine2\nLine3");
    string line;
    while(getline(lines, line)) {
        cout << "Line: " << line << endl;
    }
    // Line: Line1
    // Line: Line2
    // Line: Line3


    // Demonstrating length(), capacity(), and max_size()
        string text = "Hello World";
        
        // length(): Returns the number of characters in the string
        cout << "Length: " << text.length() << endl;        // Output: 11
        
        // capacity(): Returns the size of storage space currently allocated for the string
        cout << "Capacity: " << text.capacity() << endl;    // Output: 15 (or similar, implementation-dependent)
        
        // max_size(): Returns the maximum length the string can reach
        cout << "Max size: " << text.max_size() << endl;    // Output: Very large number

        // Length: 11
        // Capacity: 15
        // Max size: 4611686018427387903
        
        // How capacity grows
        string dynamic;
        cout << "\nInitial capacity: " << dynamic.capacity() << endl;
        
        for(int i = 0; i < 100; i++) {
            dynamic += 'a';
            if(i % 20 == 0) {
                cout << "Length: " << dynamic.length() 
                     << ", Capacity: " << dynamic.capacity() << endl;
            }
        }
        
        // Shrinking capacity to fit actual content
        dynamic.shrink_to_fit();
        cout << "After shrink_to_fit - Length: " << dynamic.length() 
             << ", Capacity: " << dynamic.capacity() << endl;
    
    // Initial capacity: 15
    // Length: 1, Capacity: 15
    // Length: 21, Capacity: 30
    // Length: 41, Capacity: 60
    // Length: 61, Capacity: 120
    // Length: 81, Capacity: 120
    // After shrink_to_fit - Length: 100, Capacity: 100

    return 0;
}