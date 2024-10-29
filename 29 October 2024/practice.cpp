#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "World!";
    s1.resize(15, '*');
    cout << "After resizing to 15 with '*': " << s1 << " (Size: " << s1.size() << ")" << endl;
    return 0;
}