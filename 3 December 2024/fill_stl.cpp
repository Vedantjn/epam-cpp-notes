// Assigns a specific value to a range of elements.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec(10);

    // Fill the vector with zeros
    fill(vec.begin(), vec.end(), 0);

    for (int x : vec) {
        cout << x << " ";
    }
    return 0;
}

// 0 0 0 0 0 0 0 0 0 0 