// when I want Specilized behaviour for a particular data type or a condition
// class template Specilization

#include <iostream>
using namespace std;

template <typename T> class printer {
public:
  void print_stuff(T stuff) { cout << "Generic Printing: " << stuff << endl; }
};

template <> class printer<char> {
public:
  void print_stuff(char stuff) {
    cout << "Specilized Printing: " << stuff << endl;
  }
};

int main() {
  printer<int> p1;
  p1.print_stuff(3);

  printer<string> p2;
  p2.print_stuff("hello, world!");

  printer<char> p3;
  p3.print_stuff('A');

  return 0;
}

// there is also function template Specilization etc ...
