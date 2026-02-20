#include <iostream>

using namespace std;

template <typename T> class templ {
public:
  T x;
  T y;

  templ(T ix, T iy) : x(ix), y(iy) {}

  void getVals() { cout << "x: " << x << " " << "y: " << y << endl; }
};

int main() {
  templ<int> int_templ(3, 4);
  templ<char> char_templ('a', 'b');
  templ<float> float_templ(3.0, 8.0);

  int_templ.getVals();
  float_templ.getVals();
  char_templ.getVals();

  return 0;
}
