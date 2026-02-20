// this is used when we know for sure 100% that the object being used ain't null
#include <iostream>
using namespace std;

void setToTen(int &x) { // here the compiler binds x to a which means that it
                        // does not create a copy of a, "neither does it store
                        // the address of a in x like a pointer IT MAKES X AN
                        // ALIAS OF A" this means that inside the function
                        // whenever we use x it would be like using "real" a
  x = 10;
  // x = new int(5); not possible here
}

int main() {
  int a;
  setToTen(a);
  // setToTen(NULL); or int *p = nullptr; f(*p); or int &r = *(int*)nullptr;
  // none of this is allowed because the compiler assumes that x is a valid
  // object with a memory location to it and it's safe to write to it and as c++
  // gives 0 runtime checks so doing this and then trying to write there would
  // crash the program
  cout << a << endl; // the object itself is passed no address are passed
}
