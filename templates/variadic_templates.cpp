// variadic templates are the ones which can take in a variable number of
// arguments ex: variadic function template
#include <iostream>
using namespace std;

void printStuff() {
  cout << "I am the last function" << endl;
}

// T is the type of first argument, Types is a pack of types of the remaining arguments, similarly var1 is the first argument and var2 is a pack
// of the other arguments. var2... means to expand this pack
template <typename T, typename... Types> void printStuff(T var1, Types... var2) {
  cout << var1 << endl;
  printStuff(var2...);
}

int main() {
  printStuff(1, 2.0, 3.00, 'A', "hello, world!", false);
  return 0;
}
