#include <cctype>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <sys/types.h>
#include <vector>

using namespace std;

// POLYMORPHIP EXCEPTION CLASS -
class NegativeValueException : public exception {
private:
  int value;

public:
  NegativeValueException(int val) : value(val) {}

  const char *what() const noexcept override {
    return "NegativeValueException ouccured!";
  }
};

int main() {
  vector<int> vec = {1, 2, 3};
  int x;
  cin >> x;

  // throwing built in exceptions
  try { // try block to try out code
    if (x % 2 != 0) {
      throw -1; // to throw the exception
    }
    // CATCH BY VALUE
    // it creates a copy of the throw object in the catch block
  } catch (int e) { // to catch exception and take control when it ouccers
    cout << "Caught exception: " << e << endl;
  }

  // throwing standard exceptions - logic_error, invalid_argument, domain_error,
  // length_error, out_of_range, future_error, runtime_error, range_error,
  // overflow_error, underflow_error, regex_error, system_error,
  // ios_base::failure, filesystem::filesystem_error, tx_exception,
  // nonexistent_local_time, ambiguous_local_time, format_error, bad_typeid,
  // bad_cast, bad_any_cast, bad_optional_access, bad_expected_access,
  // bad_weak_ptr, bad_function_call, bad_alloc, bad_array_new_length,
  // bad_exception, bad_variant_access
  try {
    vec.at(3); // here we don't use the throw keyword as the function itself
               // throws an exception so inorder make this work we must know the
               // function that throws exceptions and also the exception itself
               // must be known in order to write in the catch block
  } catch (out_of_range e) {
    cout << e.what() << endl; // what() gives info
  }

  // writing custom exceptions
  try {
    int n;
    cin >> n;
    if (n < 0) {
      throw NegativeValueException(n);
    }
  } catch (NegativeValueException n) {
    cout << n.what();
  }

  // CATCH BY REFERENCE
  // catch (const exception &e) {
  //   cout << e.what() << endl;
  // }

  // catching multiple exceptions
  try {
    int x;
    cout << "Enter something in the range 1-10" << endl;
    cin >> x;
    if (x > 10 || x < 1) {
      throw out_of_range("Out of Range argument passed");
    } else if (x == 5) {
      throw invalid_argument("invalid_argument");
    } else {
      throw "Unexpected error has ouccured";
    }
  } catch (invalid_argument a) {
    cout << a.what() << endl;
  } catch (out_of_range o) {
    cout << o.what() << endl;
  } catch (...) {
    cout << "Random shit just happened" << endl;
  }

  // we write return 0 for successfull program execution but even if we don't it
  // still defaults to it
}

// exception propogation
// nested try catch blocks
// exit(), exit codes
// access voilations
