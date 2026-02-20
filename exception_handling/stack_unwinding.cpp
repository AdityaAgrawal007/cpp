#include <iostream>
using namespace std;

// in the stack when function1 throws Exception then it's checked if it has a
// corresponding catch block to handle it and if not found then it's removed
// from the stack, the the next thing in stack is checked i.e. function2 it's
// also removed for the same reason and finally when function3 is checked and
// the catch block is found it's executed

class dummy {
public:
  int function_value;
  dummy(int func_val) : function_value(func_val) {}
  ~dummy() {
    cout << "Destructor called by function: " << function_value
         << endl; // if there are any local objects in the functions in the
                  // stack so while removing them the Destructor of those
                  // objects would be called
  }
};

void function1() {
  dummy d1(1);
  cout << "function1 called" << endl;
  throw 100;
  cout << "function1 ended" << endl;
}

void function2() {
  dummy d2(2);
  cout << "function2 called" << endl;
  function1();
  cout << "function2 ended" << endl;
}

void function3() {
  try {
    cout << "function3 called" << endl;
    function2();
  } catch (int i) {
    cout << "Exception Caught: " << i << endl;
  }
  cout << "function3 ended" << endl;
}

int main() {
  function3();
  return 0;
}
