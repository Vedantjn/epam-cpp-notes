/*
The Pimpl Idiom (Pointer to Implementation) in C++

1. What is Pimpl?
- Pimpl stands for "Pointer to Implementation" or "Private Implementation"
- It's a design pattern that reduces compilation dependencies and separates interface from implementation
- Also known as "Compilation Firewall" or "Cheshire Cat" pattern

2. Key Components:
- Public class (interface) that users interact with
- Private implementation class (usually named Impl or Implementation)
- A unique_ptr/shared_ptr to the implementation in the public class

3. Benefits:
- Reduced compilation dependencies
- Better binary compatibility
- Faster build times
- Ability to change implementation without recompiling client code
- Smaller header files
- Information hiding

4. Basic Structure:
class Widget {                   // In header file
private:
    class Impl;                  // Forward declaration
    std::unique_ptr<Impl> pImpl; // Pointer to implementation
public:
    Widget();                    // Constructor
    ~Widget();                   // Destructor needed for unique_ptr
    // ... public interface
};

class Widget::Impl {             // In source file
    // ... actual implementation
};

5. Common Use Cases:
- Large software systems
- Plugin architectures
- API design
- Platform-specific implementations
- Library development

6. Trade-offs:
- Extra level of indirection
- Dynamic allocation overhead
- More complex code structure
*/

// Example implementation
#include <memory>
#include <string>

using namespace std;

// Widget.h
class Widget {
private:
    class Impl;
    unique_ptr<Impl> pImpl;

public:
    Widget();
    ~Widget();
    
    void doSomething();
    string getName() const;
};

// Widget.cpp
class Widget::Impl {
private:
    string name;
    int data;

public:
    Impl() : name("Widget"), data(0) {}
    void doSomething() { data++; }
    string getName() const { return name; }
};

Widget::Widget() : pImpl(make_unique<Impl>()) {}
Widget::~Widget() = default;

void Widget::doSomething() {
    pImpl->doSomething();
}

string Widget::getName() const {
    return pImpl->getName();
}
