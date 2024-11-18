#include <iostream>
using namespace std;

class mycls {
public:
	mycls() { 
        cout << "Default constructor" << endl; 
    }
	mycls(const mycls& other) { 
        cout << "Copy constructor" << endl; 
    }
	mycls(mycls&& other) { 
        cout << "Move constructor" << endl; 
    }
	mycls& operator=(const mycls& other) { 
        cout << "Copy assignment" << endl; 
        return *this; 
    }
	mycls& operator=(mycls&& other) { 
        cout << "Move assignment" << endl; 
        return *this; 
    }
};

class A
{
	int *m;
	mycls oo;
public:
	A()
	{
		cout << "A: Default constructor\n";
		m = new int;
		*m = 4;
	}

	A(const A &rhs)
		: oo(rhs.oo)
	{
		cout << "A: Copy constructor\n";
		this->m = new int;
		*this->m = *rhs.m;
	}

	A(A && rhs)
		: oo(std::move(rhs.oo))
	{
		cout << "A: Move constructor\n";
		this->m = rhs.m;
		rhs.m = nullptr;
	}

	~A()
	{
		cout << "A: Destructor\n";
		if (m)
			delete m;
	}
 
	A& operator = (const A &rhs) // l value ref
	{
		cout << "A: Copy assignment operator\n";
		if (this != &rhs) {
			delete m;
			m = new int;
			*m = *rhs.m;
			oo = rhs.oo;
		}
		return *this;
	}
 
	A& operator=(A &&rhs) // r value ref
	{
		cout << "A: Move assignment operator\n";
		if (this != &rhs) {
			delete m;
			m = rhs.m;
			oo = std::move(rhs.oo);
			rhs.m = nullptr;
		}
		return *this;
	}

	void dataprocess()
	{
		if(m)
			cout << "Value of m: " << *m << endl;
		else
			cout << "m is nullptr\n";
	}
};
 
A fun(A& x) 
{
	cout << "Inside fun()\n";
	A y;
	return y; 
}

int main()
{
	A o1;
	// A o2 = move(o1); 
	// A o4(o2);
	// o1.dataprocess();
	
	A o3;
	
    o3 = o1;
	o3 = fun(o1);
 
	int a = 5; // r value ref
	int b = a; // l value ref
	cout << "a = " << a << ", b = " << b << endl;
	
	return 0;
}
