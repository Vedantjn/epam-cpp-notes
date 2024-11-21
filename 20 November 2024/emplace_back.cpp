// Vector emplace() is used to insert elements at the given position in a vector by 
// constructing it in-place within the vector, rather than creating a temporary object 
// and then moving or copying it into the vector.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;

    // Using emplace_back to add elements to the vector
    numbers.emplace_back(10);
    numbers.emplace_back(20);
    numbers.emplace_back(30);

    // Displaying the elements in the vector
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}  
