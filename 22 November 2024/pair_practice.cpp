// If the first elements are equal, the second elements (char) are compared.

#include <iostream>
#include <utility> // For std::pair

using namespace std;

int main() {
    // Declare and initialize pairs
    pair<int, char> myPair1(1, 'a');
    pair<int, char> myPair2(2, 'b');
    pair<int, char> myPair3(1, 'a');

    // Comparing pairs
    cout << "Comparing pairs:" << endl;

    // Equality check
    if (myPair1 == myPair3) {
        cout << "myPair1 is equal to myPair3." << endl;
    } else if (myPair1 < myPair2) {
        cout << "myPair1 is less than myPair2." << endl;
    } else if (myPair2 > myPair3) {
        cout << "myPair2 is greater than myPair3." << endl;
    } else {
        cout << "No specific comparison holds true." << endl;
    }

    // Detailed breakdown
    cout << "\nDetailed comparisons:" << endl;

    cout << "myPair1 == myPair2: " << (myPair1 == myPair2 ? "true" : "false") << endl;
    cout << "myPair1 != myPair2: " << (myPair1 != myPair2 ? "true" : "false") << endl;
    cout << "myPair1 < myPair2: " << (myPair1 < myPair2 ? "true" : "false") << endl;
    cout << "myPair1 <= myPair2: " << (myPair1 <= myPair2 ? "true" : "false") << endl;
    cout << "myPair1 > myPair2: " << (myPair1 > myPair2 ? "true" : "false") << endl;
    cout << "myPair1 >= myPair2: " << (myPair1 >= myPair2 ? "true" : "false") << endl;

    // Modify pairs to demonstrate changes
    myPair2 = make_pair(1, 'c'); // Change myPair2 to match key but different value
    cout << "\nAfter modifying myPair2 to (1, 'c'):" << endl;

    cout << "myPair1 == myPair2: " << (myPair1 == myPair2 ? "true" : "false") << endl;
    cout << "myPair1 < myPair2: " << (myPair1 < myPair2 ? "true" : "false") << endl;

    return 0;
}
