#include <algorithm>
#include <iostream>
#include <type_traits>
using namespace std;

template <typename t1, typename t2>
typename enable_if<is_arithmetic<t1>::value && is_arithmetic<t2>::value,
                   common_type_t<t1, t2>>::type
// common_type_t is - what's the datatype that both t1 and t2 can be safely
// converted to ?

smart_min(t1 x, t2 y) {
  return x > y ? y : x;
}

template <typename t1, typename t2>
typename enable_if<is_same<t1, string>::value && is_same<t2, string>::value,
                   string>::type
smart_min(t1 x, t2 y) {
  return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end())
             ? x
             : y; // compare strings in lexiographical order i.e.
                  // dictionary order comparision
}

template <typename T1, typename T2>
enable_if_t<is_arithmetic_v<T1> && is_arithmetic_v<T2> && !is_same_v<T1, T2>,
            common_type_t<T1, T2>>
smart_min(T1 x, T2 y) {
  using CT = common_type_t<T1, T2>;
  return static_cast<CT>(x > y ? y : x);
}

template <typename T1, typename T2>
enable_if_t<!is_arithmetic_v<T1> && !is_arithmetic_v<T2> &&
                !(is_same_v<T1, string> && is_same_v<T2, string>),
            void>
smart_min(T1, T2) {
  static_assert(false, "smart_min: incompatible types — must be both "
                       "arithmetic or both std::string");
}

// template <typename t1, typename t2> auto smart_min(t1 x, t2 y) {
//   static_assert(is_arithmetic<t1>::value && is_arithmetic<t2>::value,
//                 "given types should be arithmetic");
//   // is_same_v is a helper variable template used to check if two types are
//   // identical or not k
//   static_assert(!is_same_v<t1, t2>, "given types must be diffrent");
//   // common_type_t is a type trait used to determine a common type to which
//   both
//   // can be converted safely without loss of information
//   using ct = common_type_t<t1, t2>;
//   // here using keyword is used to create a type alias, i.e. it is used to
//   give
//   // a diffrent name to the type returned by common_type_t
//   return static_cast<ct>(x > y ? y : x);
// }

// template <typename t1, typename t2> void smart_min(t1, t2) {
//   constexpr bool ok =
//       (is_arithmetic<t1>::value && is_arithmetic<t2>::value) ||
//       (is_same<t1, string>::value && is_same<t2, string>::value);
//
//   static_assert(ok, "smart_min: incompatible types — must be both arithmetic
//   "
//                     "or both std::string");
// }

int main() {
  cout << smart_min(2, 3) << endl;
  cout << smart_min('a', 'b') << endl;
  // cout << smart_min("cat", "dog"); these give error cause they are string
  // literals and decau tp const char*
  cout << smart_min(string("cat"), string("dog")) << endl;
  cout << smart_min(2, 3) << endl;
  cout << smart_min(2, 3.5) << endl;
  cout << smart_min(string("cat"), string("dog")) << endl;
  // smart_min(string("hi"), 5); // should fail at compile time
}
