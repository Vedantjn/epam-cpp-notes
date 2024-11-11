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

// Usage Example
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

// Usage Example
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