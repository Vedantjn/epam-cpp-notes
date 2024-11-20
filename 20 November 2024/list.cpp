#include <iostream>
#include <list>
using namespace std;

int main() {
    // Create a list
    list<int> numbers;
    
    // push_back() - Add elements at the end
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    
    // push_front() - Add elements at the beginning
    numbers.push_front(5);
    numbers.push_front(2);
    
    // insert() - Insert element at specific position
    auto it = numbers.begin();
    advance(it, 2);
    numbers.insert(it, 15);
    
    // size() - Get list size
    cout << "List size: " << numbers.size() << endl;
    
    // front() and back() - Access first and last elements
    cout << "First element: " << numbers.front() << endl;
    cout << "Last element: " << numbers.back() << endl;
    
    // pop_front() and pop_back() - Remove first and last elements
    numbers.pop_front();
    numbers.pop_back();
    
    // remove() - Remove all elements with specific value
    numbers.remove(15);
    
    // sort() - Sort the list
    numbers.sort();
    
    // reverse() - Reverse the list
    numbers.reverse();
    
    // unique() - Remove consecutive duplicate elements
    numbers.unique();
    
    // clear() - Remove all elements
    numbers.clear();
    
    // empty() - Check if list is empty
    if(numbers.empty()) {
        cout << "List is empty" << endl;
    }
    
    // splice() - Transfer elements from another list
    list<int> list2 = {100, 200, 300};
    numbers.splice(numbers.begin(), list2);
    
    // merge() - Merge two sorted lists
    list<int> list3 = {1, 3, 5};
    list<int> list4 = {2, 4, 6};
    list3.merge(list4);
    
    // assign() - Assign new elements
    numbers.assign(5, 10); // Assigns 5 elements with value 10
    
    // resize() - Change size of list
    numbers.resize(3);
    
    // Print the list
    cout << "Final list contents: ";
    for(int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

// List size: 6
// First element: 2
// Last element: 30
// List is empty
// Final list contents: 10 10 10