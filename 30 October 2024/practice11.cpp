#include <iostream>
using namespace std;

class Demo {
    int a;
public:
    Demo() {
        a = 10;
    }
    
    explicit Demo(const Demo& d) {
        a = d.a;
    }
    
    void show() {
        cout << a << endl;
    }
};

int main() {
    Demo d1;
    // Demo d2 = d1; // This will now give error due to explicit
    Demo d2(d1);     // This is the correct way with explicit
    d2.show(); // 10
    return 0;
}
