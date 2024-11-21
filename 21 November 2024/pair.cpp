#include <iostream>
#include <utility> // For std::pair
using namespace std;

int main() {
    // Declaring a pair
    pair<int, string> myPair;

    // Initializing using constructor
    myPair = pair<int, string>(2, "Vedant");

    // Initializing using make_pair
    pair<int, string> anotherPair = make_pair(3, "Vanshika");

    // Initializing using initializer list
    pair<int, string> thirdPair{4, "Diana"};

    // Accessing elements
    cout << "First: " << myPair.first << "\n";  // Output: 2
    cout << "Second: " << myPair.second << "\n"; // Output: Bob
    cout << "First of anotherPair: " << anotherPair.first << "\n"; // Output: 3
    cout << "Second of anotherPair: " << anotherPair.second << "\n"; // Output: Charlie
    cout << "First of thirdPair: " << thirdPair.first << "\n"; // Output: 4
    cout << "Second of thirdPair: " << thirdPair.second << "\n"; // Output: Diana

    return 0;
}

// First: 2
// Second: Vedant
// First of anotherPair: 3
// Second of anotherPair: Vanshika
// First of thirdPair: 4
// Second of thirdPair: Diana