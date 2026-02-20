// in this we can edit only specific parameters instead or redefining every one
// of them from scratch like in explicit/full template spelicalization

#include <iostream>
using namespace std;

template <typename A, typename B> void foo(A var, B str) {
  cout << "Primary Template" << endl;
}

template <typename A, typename B> void foo(A *var, B str) {
  cout << "Partial Specialization Template" << endl;
}

int main() {
  int var = 10;
  int *ptr = &var;

  foo(var, "Geek");
  foo(ptr, 24);

  return 0;
}
