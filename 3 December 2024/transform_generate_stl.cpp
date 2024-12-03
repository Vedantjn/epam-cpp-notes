#include <vector>
#include <iostream>
#include <algorithm> // For std::transform, std::generate

using namespace std;

int main() {
    vector<int> s(5);

    // Fill with incrementing values
    int start = 10;
    generate(s.begin(), s.end(), [&start]() { return start++; });

    cout << "Generated Vector: ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    // Transform to multiply by 2
    transform(s.begin(), s.end(), s.begin(), [](int x) { return x * 2; });

    cout << "After Transform (Multiply by 2): ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}

// Generated Vector: 10 11 12 13 14
// After Transform (Multiply by 2): 20 22 24 26 28