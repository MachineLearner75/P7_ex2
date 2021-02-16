#include <iostream>
#include <vector>

#define SIZE 20

template <typename T> 
class StackI {
  public: 
    virtual void push(T t) = 0;
    virtual void pop() = 0;
    virtual T peek() = 0;
    virtual void print() = 0;
};

template <typename T>
class Stack : public StackI <T> {

  protected :
    T *arr;
    unsigned int capacity;

  public:
    Stack<T>();
    Stack<T>(unsigned int n);

    void push(T t);
    void pop();
    T peek();
    void print();

    bool EmptyStackException();
    bool FullStackException();

    ~Stack() {
      delete [] arr;
    }
};

// constructor - initialization
template <typename T>
Stack<T>::Stack(unsigned int size) : capacity(size), top(-1) 
{
  arr = new T[size];
}

// to add an element to the stack
template <typename T>
void Stack<T>::push(T t)
{
  if(FullStackException(top)){
    std::cout << "Stack is full, Program will be terminated\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "Inserting " << t << std::endl;
  arr[++top] = t;
}

//pop the top element of the stack
template <typename T>
T Stack<T>::pop()
{
  if(EmptyStackException(top)){
    std::cout << "Stack is empty, Program will be terminated\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "Popping out " << peek() << std::endl;
  return arr[top--];
}

//return the top element
template <typename T>
T StackI<T>::peek() {

  if(!EmptyStackException(top)) {

    return arr[top];
  } else {
    exit(EXIT_FAILURE);
  }
} 

template <typename T>
void StackI<T>::print() {
  std::cout << "" << std::endl;
}

//

int main(){

Stack<int> test(5);

test.push(5);

}