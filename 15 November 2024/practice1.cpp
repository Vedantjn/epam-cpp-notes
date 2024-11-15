#include<iostream>
using namespace std;

class MyClass {
private:
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
public:
    int* begin() { 
        return &arr[0]; 
    }
    int* end() { 
        return &arr[size]; 
    }
};

int main(){
    MyClass obj;
    for(auto v : obj) {
        cout << v << endl;
    }
    return 0;
}

// 1
// 2
// 3
// 4
// 5