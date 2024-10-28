#include<iostream>

struct Person {
    char a;     // 1 byte
    char b;     // 1 byte
    // Padding explanation:
    // - CPU prefers 'int' to be aligned on 4-byte boundary for efficient memory access
    // - After 2 chars (2 bytes), compiler adds 2 bytes of padding
    // - This ensures 'int c' starts at byte offset 4 instead of byte offset 2
    // Memory layout: [a][b][pad][pad][c][c][c][c]
    int c;      // 4 bytes
};              // Total size: 8 bytes (2 chars + 2 padding + 4 int)

int main() {
    Person p;
    std::cout << "Size of Person struct: " << sizeof(Person) << " bytes" << std::endl;
    // Size of Person struct: 8 bytes
    return 0;
}