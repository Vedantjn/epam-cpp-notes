// constructors and destructors in has a relationship
  #include <iostream>
  using namespace std;

  class Engine {
  private:
      string type;
  public:
      Engine() {
          type = "Unknown";
          cout << "Engine constructor called" << endl;
      }
      Engine(string t) {
          type = t;
          cout << "Engine parameterized constructor called" << endl;
      }
      ~Engine() {
          cout << "Engine destructor called" << endl;
      }
      void start() {
          cout << type << " Engine started" << endl;
      }
  };

  class Vehicle {
  private:
      string brand;
  public:
      Vehicle() {
          brand = "Unknown";
          cout << "Vehicle constructor called" << endl;
      }
      Vehicle(string b) {
          brand = b;
          cout << "Vehicle parameterized constructor called" << endl;
      }
      ~Vehicle() {
          cout << "Vehicle destructor called" << endl;
      }
      void displayBrand() {
          cout << "Brand: " << brand << endl;
      }
  };

  // In HAS-A relationship (composition), when an object is created:
  // 1. First, the member object's constructor is called (Engine)
  // 2. Then, the containing class's constructor is called (Car)
  // When object is destroyed:
  // 1. First, the containing class's destructor is called (Car)
  // 2. Then, the member object's destructor is called (Engine)

  class Car : public Vehicle {  // IS-A relationship
  private:
      Engine engine;  // HAS-A relationship - Engine is a member of Car
  public:
      Car() : Vehicle() {
          cout << "Car constructor called" << endl;
      }
      Car(string b, string e) : Vehicle(b), engine(e) {
          cout << "Car parameterized constructor called" << endl;
      }
      ~Car() {
          cout << "Car destructor called" << endl;
      }
      void startCar() {
          engine.start();
      }
  };

  int main() {
      Car car("Toyota", "V8");
      car.displayBrand();
      car.startCar();
    
      return 0;
  }

// Vehicle parameterized constructor called
// Engine parameterized constructor called
// Car parameterized constructor called
// Brand: Toyota
// V8 Engine started
// Car destructor called
// Engine destructor called
// Vehicle destructor called