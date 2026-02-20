#include <iostream>
#include <memory>
using namespace std;

// shared_ptr<Entity> name(new(entity)); this is definitly bad with shared
// pointers casue shared pointer has to allocate another block of memory called
// the control block where it stores "reference count", so if we instead first
// create a new block and then pass it into the shared pointer constructor then
// it has got two

class tester {
public:
  tester() { cout << "Constructor called" << endl; }

  ~tester() { cout << "Destructor called" << endl; }
};

int main() {
  {
    shared_ptr<tester> ptr1;
    {
      shared_ptr<tester> ptr2 = make_unique<tester>();
      ptr2 = ptr1;
    }
  }
}
// weak_ptr is nothing but the same thing execept for the fact that after coping
// the other one does not take ownership
