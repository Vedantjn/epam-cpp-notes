// Exception handling: Try catch
#include <iostream>
using namespace std;

class Test {
public:
    Test() {
        
    }
    
    void memFunc() {
        int* ptr = new int[100000000000]; // terminate called after throwing an instance of 'std::bad_alloc'
    }
    
    int memFunc2(int x, int y) { // y as 0 exception handling
        int c = x / y;
        return c;
    }
};

int main() {
    Test obj;
    obj.memFunc();
}