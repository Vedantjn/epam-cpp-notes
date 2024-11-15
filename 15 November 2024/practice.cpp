#include<iostream>
using namespace std;

template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... restOfTheArgs>
T sum(T n, restOfTheArgs... args) {
    return n + sum(args...);
}

int main(){
    int ans = sum(1, 3, 5, 3, 2);
    cout << ans << endl;
    return 0;
}