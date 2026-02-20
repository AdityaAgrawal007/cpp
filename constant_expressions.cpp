#include <array>
#include <iostream>

using namespace std;

int main() {
  // 1 - this size is known at compile time but the value of x is only known at
  // runtime (x is not a "compile time constant") so we need to allocate the
  // memory though at compile time so we need 1
  int x = 1;
  // array<int, x> a1;

  // defines expressions that can be evaluated at compile time we know the value
  // of y at compile time but value of x is only known at runtime
  const int y = 1;
  // constexpr int y = 1;
  array<int, y> a2;

  // const int* a = new int;
  // *a = 10; error
  // a = (int*)&x;

  // int* const a = new int;
  // *a = 10;
  // a = (int*) &x; error
}
