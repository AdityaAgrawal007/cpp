#include <cstring>
#include <iostream>

using namespace std;

class foo {
  int size;
  int *ptr;

public:
  foo(int s = 0) {
    size = s;
    ptr = (s > 0) ? new int[size] : nullptr;
  }

  foo(const foo &obj) {
    size = obj.size;
    this->ptr = (size < 0) ? nullptr : new int[size];
    // 1. the below function copy(a, b, dest) starts copying from a till b(b
    // exculsive) and copies it to destination
    copy(obj.ptr, obj.ptr + size, this->ptr);
  }

  foo &operator=(const foo &obj) {
    // 2. here we check if we aren't copying the object to itself cause in that
    // case what we are about to do can cause memory leaks
    if (this != &obj) { // 2.5 self allocaiton is rarely done and this check
                        // slows down the code
      // 3. because copy assignment operator is used to copy to objects that
      // already have a value hence we first need to delete it
      delete[] this->ptr;
      // 3.5 here if the memory is dealocated and something goes wrong after
      // that then we are left with a dangling pointer there is nothing here
      // that ensures atomicity
      this->ptr = new int[obj.size];
      this->size = obj.size;
      // 4. void* memmove( void* dest, const void* src, std::size_t count );
      memmove(this->ptr, obj.ptr, this->size * sizeof(int));
      // 5. the whole logic of copying is repeated in copy constructor and
      // operator
    }
    return *this;
  }
  ~foo() { delete[] ptr; }
};

int main() {
  foo obj1;
  // foo obj1(obj1);
}
