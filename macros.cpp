// #define MACRO_NAME macro_definition
// the preprocessor will replace the definition whereever macro is used

#define SQUARE(x) (x * x) // function-like macros
// #define P 3 // object-like macros
// #ifdef #endif conditional macros

#include <iostream>
using namespace std;

int main() {
  int n = 5;
  int result = SQUARE(n);
  cout << result << endl;

  // they don't have type checking

  // predefined macros - just can it
  cout << "This is line: " << __LINE__ << " in file: " << __FILE__
       << " written on date: " << __DATE__ << " at time: " << __TIME__ << endl;
}
