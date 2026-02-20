#include <iostream>
#include <type_traits>

using namespace std;

// this version does not perform any compile time checks, correct version is
// below it template <typename T1, typename T2> int add(T1 x, T2 y){
//   if(is_integral<T1>::value && is_integral<T2>::value){
//     return x + y;
//   }
// }
//
// int main(){
//   cout << add(2, 3) << endl;
//   cout << add(2.0, 3.0) << endl;
// }

template <typename T1, typename T2>

// 1. typename specifies to the compiler that type is a type
// 2. enable_if template is a template struct/metafunction that checks both
// conditions and returns a type only if condition is true. the first parameter
// is the condition if it evaluates to true then use the type in the second
// argument
// 3. decltype is operator that evaluates a condition (first checks if condition
// is value if yes then what would be it's type)without actually running,
// decltype needs an expression to evaluate the result
// 4. hence T1() is a temporary object of that type initilized ex: if T1 = int
// then T1 = 0 it (how?)

typename enable_if<is_integral<T1>::value && is_integral<T2>::value,
                   decltype(T1() + T2())>::type add(T1 x, T2 y) {
  return x + y;
}

int main() {
  cout << add(2, 3) << endl;
  // cout <<  add(2.0, 3.0) << endl; won't work
}
