#include <iostream>
using namespace std;

// lvalues - objects that have identifiable locations in the memory i.e. an
// address, it must have the capacity to store data hence it cannot be a
// function/expression/constant
// r value is something that doesn't have any identifiable location in
// memory

void nigga(const int &x) { cout << x << endl; } // this is useful as here we don't need to make a copy of the variable 

int main() {
  int i = 10;
  // lvalue = rvalue
  const int &a = 10; // this is called "const value reference" it can bind to temporary internally the compiler does something like this - temp = 10;
  // int& a = temp;
  nigga(a);

}
