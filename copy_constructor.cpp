#include <cstring>
#include <iostream>

using namespace std;

class a {
public:
  int x = 10;
};

class b {
public:
  int x, y = 5;
  b() {}
  b(const b &y) { // const here is optinoal but we write it just to ensure that
                  // we don't accidentally modify the original object, this is
                  // used when say we don't want to copy all members the user
                  // defined constructor makes "deep copies" of stuff, it's used
                  // when the class has got dynamically allocated memory,
                  // network connections etc
    x = y.x;
    cout << "copy constructor called!" << endl;
  }
};

class dynamic {
public:
  char *s;
  int size;
  // as there are two constructors below now it depends upon the argument which
  // one will be called
  dynamic(const char *str) {
    size = strlen(str);
    s = new char[size + 1]; // here we allocate one extra "byte" because C
                            // styled strings end with '/0' null terminator to
                            // mark the end for string functions
    strcpy(s, str);
  }

  ~dynamic() {
    delete[] s; // we have allocated an array of chars using new char[] and we
                // haven't allocated a single char using new char hence we use
                // "delete [] s" and not "delete s"
  }

  // if a copy constructor wouldn't have been present here then the default
  // constructor would have made a shallow copy wich would point to the same
  // memory location in the memory then if we say delete one pointer and the
  // memory is deallocated then we are left with dangling pointer of the
  // remaining, also the changes made in one would get reflected in the other
  // one as they both are modifying the same memory location
  dynamic(const dynamic &other) {
    size = other.size;
    s = new char[size + 1];
    strcpy(s, other.s);
  }
  void change(const std::string &newstr) {
    delete[] s;
    size = newstr.size();
    s = new char[size + 1];
    strcpy(s, newstr.c_str());
  }
};

int main() {
  a A;
  // the compiler uses a copy constructor which makes shallow copies as
  // demonstrated below, this works well for basic stuff but not for dynamically
  // allocated memroy
  a B = A; // this is also done by copy connstructor
  A.x = 20;
  // below the default copy constructor is used
  a C(A);
  a D(A);
  D = C; // this is done by "copy assignment operator" - it's job is to copy
         // stuff from one to another where both of them are already
         // "initilized" the default copy constructor does a shallow copy but
         // user defined one can do deep copy
  cout << A.x << endl;
  cout << B.x << endl;
  cout << C.x << endl;

  // here the user defined copy constructor is used
  b b1;
  b1.x = 10;
  cout << b1.x << endl;

  b b2(b1);
  cout << b2.x << endl;

  b1.y = 15;
  cout << "b1.y: " << b1.y << endl;

  cout << "b2.y: " << b2.y << endl;

  cout << "---------------------------" << endl;

  dynamic d1("something in my way");
  cout << d1.s << endl;
  dynamic d2(d1);
  cout << d2.s << endl;
  d2.change("AC$DC");
  cout << d2.s << endl;
}
