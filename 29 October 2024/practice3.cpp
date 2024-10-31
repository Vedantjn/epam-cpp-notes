#include <iostream> 
using namespace std;

class Base {
    int id;
    int ref;
    const string name;

    public:
        Base(int i, int r, string n) : id(i), ref(r), name(n) {
            cout << "Base constructor called" << endl;
        }
};

class Derived : public Base {
    const double value;

    public: 
        Derived(int i, int r, string n, double v) : Base(i, r, n), value(v) {
            cout << "Derived constructor called" << endl;
        }
};

int main() {
    Derived derivedObj(12, 43, "name", 23.232);
}