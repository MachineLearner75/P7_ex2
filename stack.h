#include <iostream>

#ifndef STACK_H
#define STACK_H

/*
Exceptions
*/
class EmptyStackException : public std::exception {
    virtual const char* what() const throw() {
        return "Empty stack!";
    }
} EmptyStackException;


class FullStackException : public std::exception {
    virtual const char* what() const throw() {
        return "Full stack!";
    }
} FullStackException;

template <class T>
class StackNode {
  protected:
    StackNode *next;
    T value;
  public:
    StackNode(T value) : value(value) {}
    void setNext(StackNode* node) {
        next = node;
    }
    StackNode* getNext() { return next; }
};

/* Stack  ADT */
template <typename T> 
class StackI {
  public: 
    virtual void push(T t) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual void print() = 0;
};

template <typename T>
class Stack : public StackI <T> {
  protected:
    int maxSize;
    int size;
    StackNode<T> *head;

    void print();
    int getNonEmpty();

  public:
    Stack<T>();
    Stack<T>(int n);
    ~Stack();

    void push(T t);
    void pop();
    T top();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack() : maxSize(20), size(0), head(nullptr) {}

template <typename T> 
Stack<T>::Stack(int n) : maxSize(n), size(0), head(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    StackNode<T> *walk = head;
    StackNode<T> *temp = nullptr;

    while (walk != nullptr) {
        temp = walk;
        walk = walk->getNext();
        delete temp;
    }
}

/*template <class T> 
int Stack<T>::getNonEmpty() {
    int noempt = 0;
    for (int i = 0; i < size; i++) {
        if (ptr[i] != NULL) {
            noempt++;
        }
    }
    return noempt;
}*/

template <typename T> 
void Stack<T>::push(T t) {
    if (size >= maxSize) {
        throw FullStackException;
    }

    StackNode<T> *sn = new StackNode<T>(t);
    sn->setNext(head);
    size++;

    /*int noempt=getNonEmpty();
        if(noempt!=size){
            ptr[size-1-noempt]=t;
        }else{
            std::cout << "Full Stack! "<< std::endl;
        }
    */
}

template <class T> 
void Stack<T>::pop() {

    /*int noempt=getNonEmpty();
    if(noempt==0){
        std::cout << "It's an empty Stack! "<< std::endl;
    }
    else{
        ptr[size-noempt] = NULL;
    }*/
}
template <class T> 
T Stack<T>::top(){
    return 0;
    /*if(isEmpty()==false){
        return ptr[size-getNonEmpty()];
    }else{
        std::cout << "It's an empty Stack! "<< std::endl;
        return NULL;
    }*/
}
template <class T> 
bool Stack<T>::isEmpty(){
    return false;
    /*bool isempty=false;
    if(getNonEmpty()==0){
        isempty=true;
    }
    return isempty;*/
}
template <class T>
void Stack<T>::print(){
    /*if(isEmpty()){
        std::cout<<"";
    }else{
        for(int i=size-getNonEmpty() ;i <size;i++){
            std::cout<<ptr[i]<<";";
        }
    }*/
}

#endif