#include <iostream>

using namespace std;

template <typename T, int max> int arrMin(T arr[], int n) {}

template <typename T1, typename T2 = double, typename T3 = string> class T {
public:
  T1 x;
  T2 y;
  T3 z;

  T(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3) {}

  void getVals() { cout << x << " " << y << " " << z << endl; }
};

int main() {
  T<int, double, string> obj(1, 2.0, "niga");
  obj.getVals();
}
