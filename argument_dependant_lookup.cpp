// ADL(protocol) when we call a function without qualifying it's namespace the
// compiler normally only looks up for the function in the currect scopebut ADL
// does an extra thing i.e. it also into the namespace of the agruments passed
// to the function if the arguemnt belongs to some other namespace then the the
// function is checked over there as well
#include <iostream>

int main() {
  // operator<<(std::cout, "Hello, world!\n");
  // operator<< does not exist in the global namespace
  std::cout
      << "Hello, world!"; // but this still works because the left arguemnt
                          // std::cout lives in the std::ostream which is in the
                          // std namespace so ADL checks std namespcae
  // std::cout << "nigaa" << endl; causes an error because "endl" is not a
  // function so it's treated as an object and it does not belong to this
  // namespace so i.e. ADL ONLY RUNS FOR FUNCTION CALLS
  endl(std::cout << "Hello, world!");
  // (endl)(std::cout); ADL Only works with unquantifiable function names (once
  // in front of which we do not write namespace) here because of paranthesis
  // it's an expression
}
