#include <iostream>
#include <vector>

#define SIZE 20

template <typename T> 
class StackI {
  public: 
    virtual void push(T t) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
    virtual void print() = 0;
};

template <typename T>
class Stack : public StackI <T> {

    T *arr;
    unsigned int capacity;
    int top;

  public:
    Stack<T>();
    Stack<T>(unsigned int n);

    void push(T t);
    T pop();
    T peek();
    void print();

    bool isEmpty();
    int FullStackException();
    int Counter();

    ~Stack() {
      delete [] arr;
    }
};

// constructor - initialization
template <class T>
Stack<T>::Stack(unsigned int size) : capacity(size), top(-1) 
{
  arr = new T[size];
}

template <class T>
int Stack<T>::Counter() {
  int notempty = 0;

  for(int i = 0; i < capacity; i++) {

    if(arr[i] != 0){
        notempty++;
    }
  }
  return notempty;
}

// to add an element to the stack
template <class T>
void Stack<T>::push(T t)
{
  int notempty = Counter();
  if(notempty != capacity){
      std::cout << "Inserting " << t << std::endl;
      arr[++top] = t;
      std::cout << top << std::endl;
  } else {
    std::cout << "Stack is full, Program will be terminated\n" << std::endl;
    exit(EXIT_FAILURE);
  }

}

//pop the top element of the stack
template <class T>
T Stack<T>::pop()
{
  int notempty = Counter();
  if(notempty == 0){
    std::cout << "Stack is empty, Program will be terminated\n" << std::endl;
    exit(EXIT_FAILURE);
  } else {
  std::cout << "Popping out " << peek() << std::endl;
  return arr[top--];
  }
}

template <class T> bool Stack<T>::isEmpty(){
    bool isempty=false;
    if(Counter()==0){
        isempty=true;
    }
    return isempty;
}

//return the top element
template <class T>
T Stack<T>::peek() {

  if(isEmpty() == false){
    return arr[capacity - Counter()];

  } else {
    std::cout << "Stack is empty, we can't display the top element" << std::endl;
    exit(EXIT_FAILURE);
  }

} 

template <class T>
void Stack<T>::print() {

  if(isEmpty()) {
    std::cout << "Stack is empty, we can't show it" << std::endl;

  } else {

    for(int i = 0; i < capacity; i++){
      std::cout << arr[i] << ",";
    }
  }
}

//

int main(){

Stack<int> test(2);

test.push(5);
test.push(4);
test.peek();

}