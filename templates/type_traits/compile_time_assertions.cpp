#include <iostream>
#include <type_traits>

using namespace std;

template <typename T> void print_stuff(T value) {
  // static_assert is a compile time language keyword, if the condition fails
  // then it shows the error message
  static_assert(is_arithmetic<T>::value, "T must be an arithmatic type");
  cout << "Value: " << value << endl;
}

int main() {
  print_stuff(2);
  // print_stuff("hello, world!");
}
