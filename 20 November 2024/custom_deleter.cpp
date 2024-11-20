// void c_del(int* ptr) {
//     delete[] ptr;
// }

// class BB {
//     BB() {
//         cout << "BB's Contructor called" << endl;
//     }

//     ~BB() {
//         cout << "BB's Destructor called" << endl;
//     }
// };

// int main() {
//     unique_ptr<int[]> ptr(new int[10], c_del);
//     *ptr = 3;

//     unique_ptr<int[]> ptr(new BB[10]);

// }


#include <iostream>
#include <memory>
#include <cstdio>
using namespace std;

// Custom deleter to close a file
void close_file(FILE* file) {
    cout << "Closing file...\n";
    fclose(file);
}
 
int main() {
    // Open a file and manage it with a unique_ptr and custom deleter
    unique_ptr<FILE, decltype(&close_file)> file(fopen("example.txt", "w"), close_file);
 
    // Use the file (writing, etc.)
    if (file) {
        fprintf(file.get(), "Hello, World!");
    }
 
    // The file will be automatically closed when file goes out of scope
    return 0;
}