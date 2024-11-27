#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>s{1, 5, 7, 6 ,3};
    cout << *s.lower_bound(10) << endl;

    if( *s.lower_bound(10) == *s.end()) {
        cout << "Out of bound" ;
    }

    return 0;
}