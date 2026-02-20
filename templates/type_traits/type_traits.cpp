// <type_traits> is a C++ header file that provides templates to check and
// manipulate types during compile time or It helps us ask questions about types
// (like "Is this an integer?") and make decisions before the program even runs

#include <iostream>
#include <type_traits>

using namespace std;

template <typename T> void checkType() {
  if constexpr (is_integral<T>::value) { // 1. constexpr to make a compile time
                                         // decision.
    // 2. the above is a unary type trait meaning it only has one input type
    // 3. following is the internal working of "predefined" type_traits, other
    // 4. demonstration fo compile time type checking below
    // types include binary, transformation
    // template<typename T> struct is_int {
    //     static const bool value = false;
    // };
    //
    // template<>
    // struct is_int<int> {
    //     static const bool value = true;
    // };
    // 4. Integral type - any data type that represents whole numbers (no
    // decimals)
    // ex: char - internally stores integer code, int, long, short etc ... 5.
    // 5. is_integral is a unary type trait,
    cout << "T is an integral type" << endl;
  } else {
    cout << "T is not an integral type" << endl;
  }
}

int main() {
  checkType<int>();
  checkType<float>();
  checkType<char>();

  return 0;
}
