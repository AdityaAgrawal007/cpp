#include <iostream>
using namespace std;

template <typename T>
T max(
    T x,
    T y) // 1. template keyword is used to declare anything as a template, 2.
         // typename is a instruction to compiler that here a typeparameter is
         // beind defined in these angle brackets, 3. T is just a placeholder 4.
         // when we pass arguments the T will be replaced by that data type
{
  return (x > y) ? x : y;
}

int main() {
  cout << ::max<int>(3, 5) << endl; // :: is reference to global namespace
  cout << ::max<double>(3.0, 4.0) << endl;
  cout << ::max<char>('g', 'a') << endl;

  return 0;
}
