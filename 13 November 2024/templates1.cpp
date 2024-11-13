
#include <iostream>
using namespace std;

// Function template for finding maximum of two values
template <typename T>
T findMax(T x, T y) {
    return (x > y) ? x : y;
}

// Class template with multiple parameters
template <class T, class U>
class Pair {
    private:
        T first;
        U second;
    public:
        Pair(T a, U b) : first(a), second(b) {}
        void display() {
            cout << "First: " << first << ", Second: " << second << endl;
        }
};

// Template with default parameter
template <class T = int>
class Container {
    private:
        T value;
    public:
        Container(T val) : value(val) {}
        T getValue() { return value; }
};

int main() {
    // Using function template
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Max of 3.5 and 7.5: " << findMax(3.5, 7.5) << endl;
    
    // Using class template
    Pair<int, string> p1(1, "Hello");
    p1.display();
    
    // Using template with default parameter
    Container<> c1(5);  // Uses default int type
    Container<double> c2(3.14);
    
    cout << "Container 1 value: " << c1.getValue() << endl;
    cout << "Container 2 value: " << c2.getValue() << endl;
    
    return 0;
}

// Max of 10 and 20: 20
// Max of 3.5 and 7.5: 7.5
// First: 1, Second: Hello
// Container 1 value: 5
// Container 2 value: 3.14