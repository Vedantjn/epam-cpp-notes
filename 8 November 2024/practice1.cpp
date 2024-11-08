// Bad Alloc Error
#include <iostream>
using namespace std;

class Test {
public:
    Test() {
        
    }
    
    void memFunc() {
        // terminate called after throwing an instance of 'std::bad_alloc'
        // what():  std::bad_alloc
        int* ptr = new int[100000000000];
        int* ptr2 = (int*)malloc(sizeof(int) * 100000000000); 
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