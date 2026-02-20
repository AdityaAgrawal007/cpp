// 1. idioms in c++ are common well extablished patterns (conventions and
// techniques) for writing code

#include <iostream>
using namespace std;

class foo {
public:
  foo() {};
  ~foo() {};

  // 2. Non-copyable/Non-Movable idioms are c++ degsin patterns that prevent
  // "objects" from being copied or assigned. this is done by deleting copy
  // constructor and copy assignment operator
  // 2.5 we need this so that we can use it on classess that manage resources
  // like file handles, network sockets etc where copying can cause isshues like
  // resource leaks, double deletions etc ...

  foo(const foo &) = delete;
  foo &operator=(const foo &) = delete;
};

class foo_child : private foo {
  // 3. now this class also becomes Non-copyable we don't need to write those
  // two lines here
};

int main() {
  foo obj1;
  // foo obj2(obj1);
  foo_child obj2;
  // foo_child obj3(obj2);
}
