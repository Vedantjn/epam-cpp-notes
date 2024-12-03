// Copies elements from one range to another.

#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> s = {1, 2, 3, 4, 5};

    vector<int> s2(5);


    cout << "Original Vector: ";
    for (int value : s) {
        cout << value << " ";
    }
    cout << endl;

    copy(s.begin(), s.end(), s2.begin());

    cout << "Copied Vector: ";
    for (int value : s2) {
        cout << value << " ";
    }
    cout << endl;

    vector<int>s3(2);
    copy(s.begin(), s.begin() + 2, s3.begin());

    cout << "Copied Vector: ";
    for (int value : s3) {
        cout << value << " ";
    }
    cout << endl;


    return 0;
}