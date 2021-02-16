#include <iostream>
#include <vector>

#define SIZE 20

template <class T> 
class StackI {
  T *arr;
  int top;
  int capacity;

  public:
    StackI(int size = SIZE);

    void push(T);
    T pop();
    T peek();
    void print();

    int size();
    bool EmptyStackException();
    bool FullStackException();

    ~StackI() {
      delete [] arr;
    }
};

// constructor - initialization
template <class T>
StackI<T>::StackI(int size) 
{
  arr = new T[size];
  capacity = size;
  top = -1;
}

// to add an element to the stack
template <class T>
void StackI<T>::push(T t)
{
  if(FullStackException(top)){
    std::cout << "Stack is full, Program will be terminated\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "Inserting " << t << std::endl;
  arr[++top] = t;
}

//pop the top element of the stack
template <class T>
T StackI<T>::pop()
{
  if(EmptyStackException(top)){
    std::cout << "Stack is empty, Program will be terminated\n" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "Popping out " << peek() << std::endl;
  return arr[top--];
}

//return the top element
template <class T>
T StackI<T>::peek() {

  if(!EmptyStackException(top)) {

    return arr[top];
  } else {
    exit(EXIT_FAILURE);
  }
} 

template <class T>
void StackI<T>::print() {
  std::cout << "" << std::endl;
}

//

int main(){

StackI<int> test(5);

test.push(5);

}