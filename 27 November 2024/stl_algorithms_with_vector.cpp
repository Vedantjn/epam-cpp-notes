#include<iostream>
#include<vector>
#include<algorithm> 
#include<numeric> 
using namespace std;

int main(){
    vector<int> vec{1, 2, 4, 5, 6, 7};
    int sum = accumulate(vec.begin(), vec.end(), 0); 
    cout << sum << endl;

    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());

    cout << endl;

    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    reverse(vec.begin(), vec.end());

    cout << endl;

    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Max element: " << *max_element(vec.begin(), vec.end()) << endl;
    cout << "Min element: " << *min_element(vec.begin(), vec.end()) << endl;
    cout << "Count of 5: " << count(vec.begin(), vec.end(), 5) << endl;

    if (binary_search(vec.begin(), vec.end(), 4)) {
        cout << "4 is found in the vector." << endl;
    } else {
        cout << "4 is not found in the vector." << endl;
    }

    auto it = find(vec.begin(), vec.end(), 4);
    if (it != vec.end()) {
        cout << "4 is found at position: " << distance(vec.begin(), it) << endl;
    } else {
        cout << "4 is not found in the vector." << endl;
    }

    auto lower = lower_bound(vec.begin(), vec.end(), 4);
    auto upper = upper_bound(vec.begin(), vec.end(), 4);
    cout << "Lower bound of 4: " << distance(vec.begin(), lower) << endl;
    cout << "Upper bound of 4: " << distance(vec.begin(), upper) << endl;

    return 0;
}

// 25
// 1 2 4 5 6 7

// 1 2 4 5 6 7

// 7 6 5 4 2 1
// Max element: 7
// Min element: 1
// Count of 5: 1
// 4 is not found in the vector.
// 4 is found at position: 3
// Lower bound of 4: 0     
// Upper bound of 4: 6  