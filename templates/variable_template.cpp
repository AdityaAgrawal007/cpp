#include <iostream>

using namespace std;

template <typename T1, typename T2> class templ {
public:
  T1 x;
  T2 y;

  templ(T1 ix, T2 iy) : x(ix), y(iy) {}

  void getVals() { cout << "x: " << x << " " << "y: " << y << endl; }
};

int main() {
  templ<int, double> int_templ(3, 4.0);
  templ<char, int> char_templ('a', 3);
  templ<float, char> float_templ(3.0, 'e');

  int_templ.getVals();
  float_templ.getVals();
  char_templ.getVals();

  return 0;
}
