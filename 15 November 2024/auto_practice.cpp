#include<iostream>
#include<vector>
using namespace std;

template<typename T>
int sum(T val) {
    return val;
}

template<typename T, typename... Args>
int sum(T x, Args... args) {
    return x + sum(args...);
}


int difference(auto val1, int val2) { // only after c++ 20
    cout << val2 - val1 << endl;
}

int main(){
    difference(3, 5);

    vector<int>vec = {1, 4, 2, 55, 2};

    int ans = sum(1, 2, 3, 4, 5);
    cout << ans << endl;
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