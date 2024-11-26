#include <iostream>
#include <list>
#include <memory> 

using namespace std;

void customDeleter(list<int>* ptr) {
    cout << "Custom deleter called, deleting bucket array." << endl;
    delete[] ptr;
}

class myHash {
    int noOFBuckets;
    unique_ptr<list<int>[], decltype(&customDeleter)> listOfBuckets;

public:
    myHash(int count) 
        : noOFBuckets(count), 
          listOfBuckets(new list<int>[noOFBuckets], customDeleter) {
        // Using unique_ptr with custom deleter for automatic memory management
    }

    int hashingkeyLogic(int element) {
        return element % noOFBuckets; 
    }

    void addElement(int ele) {
        int key = hashingkeyLogic(ele); 
        listOfBuckets[key].push_back(ele);  
    }

    void deleteElement(int ele) {
        int key = hashingkeyLogic(ele);  
        listOfBuckets[key].remove(ele);  
    }

    void printTheElements() {
        for (int i = 0; i < noOFBuckets; ++i) {
            cout << "Bucket " << i << ": ";
            for (int x : listOfBuckets[i]) {
                cout << x << " ";  
            }
            cout << endl;
        }
    }
};

int main() {
    // Hash table with 10 buckets
    myHash hashTable(10);

    hashTable.addElement(15);
    hashTable.addElement(25);
    hashTable.addElement(35);
    hashTable.addElement(5);
    hashTable.addElement(10);

    hashTable.printTheElements();

    hashTable.deleteElement(25);  // Example of deleting an element
    cout << "After deleting 25:" << endl;
    hashTable.printTheElements();

    return 0;
}
