// 1. technique to overload assignment operator effeciently by overcomming the
// problems disscussed in assignment_operator.cpp

#include <iostream>
#include <utility>
using namespace std;

class foo {
public:
  int size;
  int *ptr;
  foo(int s = 0) {
    size = s;
    ptr = (size > 0) ? new int(size) : nullptr;
  }

  foo(foo &obj) {
    size = obj.size;
    ptr = new int(obj.size);
    copy(obj.ptr, obj.ptr + size, this->ptr);
  }

  friend void swap(foo &obj1, foo &obj2) {
    // 2. swap() essentially swaps the values of two variables
    swap(obj1.size, obj2.size);
    swap(obj1.ptr, obj2.ptr);
  }

  // 2. working of copy and swap
  foo &operator=(foo obj) { // 2.5 make a copy of the right hand side, this
                            // solves the first problem of self assignment check
    // 2.5.1 here the obj object is created by the copy constructor by the
    // compiler to we don't have to manually do the memory allocation and all
    // and the code duplicacy thing is sovled here
    swap(*this, obj); // 2.6 swap it with the obj in which we want to copy it
    return *this;     // 2.7 the temporary obj get's deleted afterwards
  }

  ~foo() { delete[] ptr; }
};

int main() {}
