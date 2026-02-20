// we use this when "maybe it can be null", we interface with c libs, we fiddle
// with raw buffers/arrays, pointer arithmatic
// A reference shares the same memory address as the original variable; it
// is an alias. A pointer is a separate variable with its own memory address
// that stores the address of another variable.
#include <iostream>
using namespace std;

void maybeSetToTen(int *x) {
  if (x == nullptr)
    return;
  *x = 10;
  cout << x << endl;
  x = new int(20); // we use this when we want to later make the pointer point
                   // to a seperate memory address
  cout << x << endl;
  cout << *x << endl;
}

void changingptrs(int *&ptr) { ptr = new int(200); }

int main() {
  int a = 5;
  maybeSetToTen(&a);
  cout << a << endl;
  maybeSetToTen(nullptr);

  int *ptr = new int(100);
  changingptrs(ptr);
  cout << *ptr << endl;
}
