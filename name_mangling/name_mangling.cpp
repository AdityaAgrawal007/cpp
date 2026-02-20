// compiler generates diffrent names for the funcitons based on their arguments
// to aid the linker
#include <iostream>
using namespace std;

int foo(int x) { return 1; }
int foo(void) { return 0; }

int main() {
  foo(5);
  foo();
}
