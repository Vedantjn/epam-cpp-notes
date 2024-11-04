// both base and derived have same function names, you can use :: 
// to call base class function from derived class

  #include <iostream>
  using namespace std;

  // Base class with a non-virtual display function
  class Base {
  public:
      void display() {
          cout << "Display from Base class" << endl;
      }
  };

  // Derived class inherits from Base and overrides display
  class Derived : public Base {
  public:
      void display() {
          Base::display();  // Call base class display function
          cout << "Display from Derived class" << endl;
      }
  };

  int main() {
      Base baseObj;         // Create Base object
      Derived derivedObj;   // Create Derived object
      Base* basePtr = &derivedObj;  // Base pointer pointing to Derived object

      // Direct call using Base object - calls Base::display
      baseObj.display();     

      // Direct call using Derived object - calls Derived::display
      derivedObj.display();  

      // Call through Base pointer - calls Base::display 
      // (no virtual function, so early binding occurs)
      basePtr->display();    

      return 0;
  }