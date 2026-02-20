#include <iostream>
using namespace std;

template <int N> struct Factorial {
  static const int value =
      N * Factorial<N - 1>::value; // const is used to make a compile time
                                   // decision and static is used because it has
                                   // no object hence we must make it accicible
                                   // from the class directly
};

template <> struct Factorial<0> {
  static const int value = 1;
};

int main() {
  const int x = 3; // here x is not a compile time constant becuase to do so we
                   // need to use constexpr, const in namespace scope cannot
                   // make things compile time constant whereas in templates and
                   // structs they behave diffrently
  cout << "Factorial of 5 is: " << Factorial<5>::value << endl;
  return 0;
}
