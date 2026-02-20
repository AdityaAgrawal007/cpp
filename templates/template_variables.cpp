#include <iostream>
using namespace std;

template <typename T>
constexpr T var =
    3.4; // it generatets a value using the given value, constexpr is used for
         // compile time evaluation for invalid conversions

int main() {
  cout << var<int> << endl;
  cout << var<double> << endl;
  cout << var<char> << endl;

  return 0;
}
