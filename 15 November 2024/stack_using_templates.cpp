#include <iostream>
using namespace std;

template<typename T>
class stackTemplate
{
  T* ptr;
  int maxSize;
  int top;
public:
  
  stackTemplate(int size)
  {
    ptr = new T[size];
    maxSize = size;
    top = -1;
  }

  ~stackTemplate()
  {
    delete[] ptr;
  }

  void push(T element)
  {
    if (sizeOfStack() == maxSize)
    {
      cout << "Overflow" << endl;
    }
    else
    {
      cout<<"Pushed element is: "<<element << endl;
      ptr[++top] = element;
      cout << "Next element will be inserted at: "<<top + 1 << endl;
    }
  }

  void pop()
  {
    if (!isEmpty())
    {
      cout << "Popped out element is: " << ptr[top] << endl;
      top--;
    }
    else
    {
      cout << "UnderFlow" << endl;
    }
  }

  void topElement()
  {
    if (!isEmpty())
    {
      cout << "Top element is: " << ptr[top] << endl;
    }
    else
    {
      cout << "Stack is empty" << endl;
    }
  }

  int sizeOfStack()
  {
    cout << "Size is: " << top + 1 << endl;
    return top + 1;
  }

  bool isEmpty()
  {
    return (top < 0);
  }

  bool isFull()
  {
    return (top == maxSize - 1);
  }
};

int main() {
    stackTemplate<int> st(5);
    
    st.push(10);
    st.push(20);
    st.push(30);
    
    st.topElement();
    st.sizeOfStack();
    
    st.pop();
    st.pop();
    
    st.sizeOfStack();
    st.topElement();
    
    return 0;
}

// Size is: 0
// Pushed element is: 10
// Next element will be inserted at: 1
// Size is: 1
// Pushed element is: 20
// Next element will be inserted at: 2
// Size is: 2
// Pushed element is: 30
// Next element will be inserted at: 3
// Top element is: 30
// Size is: 3
// Popped out element is: 30
// Popped out element is: 20
// Size is: 1
// Top element is: 10