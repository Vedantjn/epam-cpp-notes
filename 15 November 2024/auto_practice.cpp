#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec = {1, 4, 2, 55, 2};
    
    // Method 1: Traditional for loop with index
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    // Method 2: Iterator based for loop
    for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++) {
        cout << *it << endl;
    }

    // Method 3: Range-based for loop (C++11 and later)
    for(auto v : vec) {
        cout << v << endl;
    }

    return 0;
}