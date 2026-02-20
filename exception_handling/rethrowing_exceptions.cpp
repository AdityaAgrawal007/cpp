// it is helpful as we can do 1. additional processing - add more info
#include <iostream>
#include <stdexcept>
using namespace std;

// EXCEPTION SPECIFICATION IN C++
// void fun() noexcept{} - this means that it is garunteed that the function
// will not throw an exception void fun() noexcept(false) noexcept(false) - this
// means that the function may throw exception

int division(int a, int b) {
  try {
    if (b == 0) {
      throw runtime_error("Division by zero not allowed");
    }
  } catch (runtime_error &r) {
    cout << "Division Catch Block caught " << r.what() << endl;
    throw;
  }
  return a / b;
}

int add(int a, int b) {
  try {
    if (a < 0 && b < 0) {
      throw invalid_argument("Negative values not allowed");
    }
  } catch (invalid_argument &i) {
    cout << "Addition Catch Block caught " << i.what() << endl;
    throw;
  }
  return a + b;
}

// becuase the function is never called befoure the arguments aren't completely
// evaluated hence in the stack there is only main then division function add
// never gets called

int main() {
  int a, b, c, d;

  cout << "Add: a b c " << endl;
  cin >> a >> b >> c;
  try {
    int result = add(c, division(a, b));
    cout << "Result: " << result << endl;
  } catch (exception &e) {
    cout << "Main Catch Block: " << e.what() << endl;
  }

  return 0;
}
