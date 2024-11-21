
#include <iostream>
#include <set>
using namespace std;

int main() {
    // set<int>
    set<int> mySet;
    mySet.insert(5);
    mySet.insert(1);
    mySet.insert(3);

    cout << "Elements in set<int>:" << endl;
    for (const int& element : mySet) {
        cout << element << " ";
    }
    cout << endl;

    // set<int, greater<>>
    set<int, greater<int>> myGreaterSet;
    myGreaterSet.insert(5);
    myGreaterSet.insert(1);
    myGreaterSet.insert(3);

    cout << "Elements in set<int, greater<>>:" << endl;
    for (const int& element : myGreaterSet) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
