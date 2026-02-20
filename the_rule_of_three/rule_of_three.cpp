// the rule of three states that if a class deines one (or more of the
// following, it should explicitly define all three - 1. copy constructor 2.
// copy assignment operator 3. destructor
#include <iostream>
using namespace std;

class Array {
private:
  int size;
  int *vals;

public:
  ~Array();
  Array(int s, int *v);
};

Array::~Array() {
  delete vals;
  vals = NULL;
}

// in this program we do not have a user defined copy constructor that will
// allocate a diffrent memory for the copy hence when the a1 will go out of
// scope the destructor will be called it will delete a1 the pointer itself and
// then the memeory it is pointing to now as we have a copy so a2 was also
// pointing to that memory so when a2 will go out of scope then desctructor will
// be called again first it will delete a2 the pointer itself but then it will
// go on to delete the memory it was pointing to which already got deleted and
// this will cauase a double free detected error in tchache and core dumped
Array::Array(int s, int *v) {
  size = s;
  vals = new int[size];
  std::copy(v, v + size, vals);
}

int main() {
  int vals[4] = {11, 22, 33, 44};
  Array a1(4, vals);

  // This line causes problems.
  Array a2(a1);

  return 0;
}
