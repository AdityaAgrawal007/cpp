// it's a compile time cast

#include <iostream>
#include <string>

using namespace std;

class Base {};
class Derived : public Base {
}; // won't work for private or protected inheritance

class integer {
public:
  int x;

  integer(int y = 0) : x(y) { cout << "Default Constructor called" << endl; }

  operator string() {
    cout << "Conversion Operator called" << endl;
    return to_string(x);
  }
};

int main() {

  char b = 'z';
  int a = 10, c = b;

  // static cast
  int d = static_cast<int>(b);
  cout << c << d << endl;

  // static cast for primitive data type pointers
  int *ptr = (int *)&b;
  cout << *ptr << endl;
  // int *ptr0 = static_cast<int *>(&b); illegal conversions are not allowed by
  // static cast

  integer obj(5);
  string str = obj;
  obj = 20; // here the comiler implicitly does obj = integer(20); so for that
            // it must temporaraly create an integer object for 20 which causes
            // an call to the Default constructor

  string str2 = static_cast<string>(obj);
  obj = static_cast<int>(15);

  // static cast in inheritance
  Derived d1;
  Base *b1 = static_cast<Base *>(&d1);

  // static cast to and from void ptr it allows both ways for any type of ptr
}
