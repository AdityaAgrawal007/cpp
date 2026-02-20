// 1. SFINAE It is a feature that lets the compiler silently ignore a template
// function or class if substituting a type makes it invalid
// 2. This allows us to enable or disable functions based on type traits,
// without causing compilation errors
#include <iostream>
#include <type_traits>

using namespace std;

// 1. enable_if checks the condition if it's true then typedef type exists and =
// 0 if it's false then type does not exits
// 2. if the second typename i.e. is enable_if is true then the program
// continues but if it's false then second parameter becomes false and SIFNAE
// removes the template itself
template <typename T, typename enable_if<is_integral<T>::value, int>::type = 0>
void process(T value) {
  cout << "Processing Integral Value " << value << endl;
}

template <typename T,
          typename enable_if<is_floating_point<T>::value, int>::type = 0>
void process(T value) {
  cout << "Processing Floating Value " << value << endl;
}

int main() {
  process(3);
  process(2.0);
}
