#include <iostream>
#include <set>
using namespace std;

class MyClass {
public:
    bool operator()(int x, int y) const {
        return x > y; 
    }
};

int main() {
    set<int, MyClass> st;

    st.insert(5);
    st.insert(1);
    st.insert(3);

    for (const auto& obj : st) {
        cout << obj << " ";
    }

    return 0;
}

// 1 3 5 