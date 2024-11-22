#include <bits/stdc++.h>
using namespace std;

// Functor to count comparisons while sorting
class Sort {
public:
    mutable int comparisons = 0; // Make comparisons mutable to modify in const context
    bool operator()(int a, int b) const {
        comparisons++;
        return a < b;
    }
};

// Function to compare two integers for ascending order
bool compareAscending(int a, int b) {
    return a < b;
}

// Function to sort and display elements using different approaches
void sortAndDisplay() {
    vector<int> numbers{239, 54, 21445, 32923};

    // Sorting with a free function
    cout << "Sorting numbers in ascending order using compareAscending:" << endl;
    sort(numbers.begin(), numbers.end(), compareAscending);
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    // Sorting with a functor
    Sort sorter;
    cout << "Sorting numbers in ascending order using Sort functor:" << endl;
    sort(numbers.begin(), numbers.end(), sorter);
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << "\nTotal comparisons made by Sort functor: " << sorter.comparisons << endl;

    // Sorting with a lambda function
    cout << "Sorting numbers in descending order using lambda function:" << endl;
    sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;
}

// Function to display a single number
void displayNumber(int a) {
    cout << "Displaying number: " << a << endl;
}

// Function to display the square of a number
void displaySquare(int x) {
    cout << "Displaying square: " << x * x << endl;
}

// Function to sort an array using a callback comparator
void sortArray(int arr[], int size, bool (*compareFunc)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compareFunc(arr[i], arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    // Example 1: Sort and display vector
    sortAndDisplay();

    // Example 2: Sorting an array using custom comparator
    int array[]{4, 5, 3, 56, 5, 23, 5};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Sorting array in descending order using lambda function:" << endl;
    sortArray(array, size, [](int a, int b) { return a > b; });
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Sorting array in ascending order using compareAscending:" << endl;
    sortArray(array, size, compareAscending);
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

// Sorting numbers in ascending order using compareAscending:
// 54 239 21445 32923
// Sorting numbers in ascending order using Sort functor:     
// 54 239 21445 32923
// Total comparisons made by Sort functor: 0
// Sorting numbers in descending order using lambda function: 
// 32923 21445 239 54
// Sorting array in descending order using lambda function:   
// 3 4 5 5 5 23 56
// Sorting array in ascending order using compareAscending:   
// 56 23 5 5 5 4 3