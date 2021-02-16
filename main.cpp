#include <iostream>
#include <exception>

#include "stack.h"

using std::cout;
using std::endl;
using std::exception;

int main() {
    Stack <int> a (12);

    try {
        a.push(10);

    } catch (exception &e) {
        cout << e.what() << endl;
    }
    /*for(int i=1;i<a.get_size()+1;i++){
      a.push(i);
    }
    a.print();
    std::cout<<"\n";
    a.pop();
    a.pop();
    std::cout<<a.top()<<"\n";
    for(int i=0;i<11;i++){
        a.pop();
        a.print();
        std::cout<<"\n";
    }*/
}
