// RAII (Resource Acquisition Is Initialization)
/*
Key points:
1. Resource Management:
   - Resources are acquired in constructor
   - Resources are released in destructor
   - Automatic cleanup when object goes out of scope

2. Common Use Cases:
   - Memory management (smart pointers)
   - File handling
   - Database connections
   - Network sockets
   - Thread locks/mutexes

3. Benefits:
   - Exception safety
   - Prevents resource leaks
   - Clean, predictable cleanup
   - Scope-based management

4. Implementation Pattern:
   class RAIIExample {
   private:
       Resource* resource;
   public:
       RAIIExample() : resource(acquire_resource()) {}  // Constructor acquires
       ~RAIIExample() { release_resource(resource); }   // Destructor releases
   };
*/

#include <bits/stdc++.h>

using namespace std;

class File {
private:
    FILE* fp;
public:
    File(const string& filename) {
        fp = fopen(filename.c_str(), "r");
        if (!fp) {
            throw runtime_error("Could not open file");
        }
    }

    ~File() {
        if (fp) fclose(fp);
    }

    // Prevent copying
    File(const File&) = delete;
    File& operator=(const File&) = delete;

    bool read(char* buffer, size_t size) {
        return fread(buffer, 1, size, fp) == size;
    }

    bool eof() const {
        return feof(fp) != 0;
    }
};

int main() {
    try {
        File file("example.txt");
        char buffer[100];
        while (!file.eof()) {
            if (file.read(buffer, sizeof(buffer))) {
                // Process buffer contents
            }
        }
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}