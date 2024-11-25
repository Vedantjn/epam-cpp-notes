// // // When using a range-based for loop with non-primitive or custom types, 
// // // it's a good practice to use a reference (preferably const reference) 
// // // to avoid unnecessary copying. Copy constructors can be costly, especially 
// // // for complex types or containers holding large amounts of data.

#include <iostream>
#include <vector>

using namespace std;

class MyClass {
public:
    MyClass(int val) : data(val) {}
    MyClass(const MyClass& other) {
        data = other.data;
        cout << "Copy constructor called for " << data << endl;
    }
    int getData() const { return data; }

private:
    int data;
};

int main() {
    vector<MyClass> myVector = {MyClass(1), MyClass(2), MyClass(3)};

    // Range-based for loop without reference (invokes copy constructor)
    for (auto item : myVector) {
        cout << "Data: " << item.getData() << endl;
    }

    return 0;
}

// // Copy constructor called for 1
// // Copy constructor called for 2
// // Copy constructor called for 3
// // Copy constructor called for 1
// // Data: 1
// // Copy constructor called for 2
// // Data: 2
// // Copy constructor called for 3
// // Data: 3

// // --------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

class MyClass {
public:
    MyClass(int val) : data(val) {}
    MyClass(const MyClass& other) {
        data = other.data;
        cout << "Copy constructor called for " << data << endl;
    }
    int getData() const { return data; }

private:
    int data;
};

int main() {
    vector<MyClass> myVector = {MyClass(1), MyClass(2), MyClass(3)};

    // Range-based for loop without reference (invokes copy constructor)
    for (auto& item : myVector) {
        cout << "Data: " << item.getData() << endl;
    }

    return 0;
}

// // Copy constructor called for 1
// // Copy constructor called for 2
// // Copy constructor called for 3
// // Data: 1
// // Data: 2
// // Data: 3

// --------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

class MyClass {
public:
    MyClass(int val) : data(val) {}
    MyClass(const MyClass& other) {
        data = other.data;
        cout << "Copy constructor called for " << data << endl;
    }
    int getData() const { return data; }

private:
    int data;
};

int main() {
    // vector<MyClass> myVector = {MyClass(1), MyClass(2), MyClass(3)};
    vector<MyClass>myVector;

    myVector.emplace_back(MyClass(1));
    myVector.emplace_back(MyClass(2));
    myVector.emplace_back(MyClass(3));

    // Range-based for loop without reference (invokes copy constructor)
    for (const auto& item : myVector) {
        cout << "Data: " << item.getData() << endl;
    }

    return 0;
}

// Copy constructor called for 1
// Copy constructor called for 2
// Copy constructor called for 3
// Data: 1
// Data: 2
// Data: 3

// -------------------------------------

#include <iostream>
#include <vector>

using namespace std;

class MyClass {
public:
    MyClass(int val) : data(val) {}
    MyClass(const MyClass& other) {
        data = other.data;
        cout << "Copy constructor called for " << data << endl;
    }
    int getData() const { return data; }

private:
    int data;
};

int main() {
    vector<MyClass> myVector = {MyClass(1), MyClass(2), MyClass(3)};

    // Range-based for loop without reference (invokes copy constructor)
    for (const auto& item : myVector) {
        cout << "Data: " << item.getData() << endl;
    }

    return 0;
}

// Copy constructor called for 1
// Copy constructor called for 2
// Copy constructor called for 1
// Copy constructor called for 3
// Copy constructor called for 1
// Copy constructor called for 2
// Data: 1
// Data: 2
// Data: 3