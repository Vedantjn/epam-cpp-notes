#include<iostream>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    list<int> ls{1, 3, 6, 78, 33};
    ls.push_back(3);
    ls.push_back(2);
    ls.push_back(34);

    for(auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    ls.sort();

    for(auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    ls.reverse();

    for(auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    auto maxElement = *max_element(ls.begin(), ls.end());
    cout << maxElement << endl;
    auto minElement = *min_element(ls.begin(), ls.end());
    cout << minElement << endl;

    int sum = accumulate(ls.begin(), ls.end(), 0);
    cout << sum << endl;

    // Count occurrences of a specific value (e.g., 3)
    int countThree = count(ls.begin(), ls.end(), 3);
    cout << countThree << endl;

    // Find if a value exists using binary search
    bool found = binary_search(ls.begin(), ls.end(), 6);
    cout << found << endl;

    // Find a specific value using find
    auto it = find(ls.begin(), ls.end(), 6);
    cout << *it << endl;
    if (it != ls.end()) {
        cout << "Found: " << *it << endl;
    } else {
        cout << "Not Found" << endl;
    }

    auto lower = lower_bound(ls.begin(), ls.end(), 3);
    cout << *lower << endl;
    auto upper = upper_bound(ls.begin(), ls.end(), 3);
    cout << *upper << endl;

    for(auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// 1 3 6 78 33 3 2 34 
// 1 2 3 3 6 33 34 78      
// 78 34 33 6 3 3 2 1      
// 78
// 1
// 160
// 2
// 0
// 6
// Found: 6
// 78
// 8
// 78 34 33 6 3 3 2 1 