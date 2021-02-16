#include <iostream>




template <class T> Stack<T>::Stack(){
    ptr = new T[20];
    size = 20;
}

template <class T> Stack<T>::Stack(int n){
    ptr = new T[n];
    size = n;
}

template <class T> T* Stack<T>::get_ptr(){
    return ptr;
}

template <class T> int Stack<T>::get_size(){
    return size;
}
template <class T> int Stack<T>::getNonEmpty() {
    int noempt = 0;
    for (int i = 0; i < size; i++) {
        if (ptr[i] != NULL) {
            noempt++;
        }
    }
    return noempt;
}

template <class T> void Stack<T>::push(T t){
    int noempt=getNonEmpty();
        if(noempt!=size){
            ptr[size-1-noempt]=t;
        }else{
            std::cout << "Full Stack! "<< std::endl;
        }
    }

template <class T> void Stack<T>::pop(){
    int noempt=getNonEmpty();
    if(noempt==0){
        std::cout << "It's an empty Stack! "<< std::endl;
    }
    else{
        ptr[size-noempt]=NULL;
    }
}
template <class T> T Stack<T>::top(){
    if(isEmpty()==false){
        return ptr[size-getNonEmpty()];
    }else{
        std::cout << "It's an empty Stack! "<< std::endl;
        return NULL;
    }
}
template <class T> bool Stack<T>::isEmpty(){
    bool isempty=false;
    if(getNonEmpty()==0){
        isempty=true;
    }
    return isempty;
}
template <class T> void Stack<T>::print(){
    if(isEmpty()){
        std::cout<<"";
    }else{
        for(int i=size-getNonEmpty() ;i <size;i++){
            std::cout<<ptr[i]<<";";
        }
    }
}
