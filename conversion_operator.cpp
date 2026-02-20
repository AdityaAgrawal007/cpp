#include <cmath>
#include <iostream>

using namespace std;

// conversion operator is a member function that tells the compiler how to
// convert an object of current class to into another type implicitly

class Complex {
private:
  double real, imagnary;

public:
  Complex(double r = 0.00, double i = 0.00) : real(r), imagnary(i) {}

  double mag() { return getMag(); }

  operator double() {
    return getMag();
  } // if someone tries to use a Complex object where a double is expected so do
    // implicit conversion this way

private:
  double getMag() { return sqrt(real * real + imagnary * imagnary); }
};

int main() {
  Complex com(3.0, 4.0);
  cout << com.mag() << endl;
  cout << com << endl; // here cout does not know how to print a complex objext
                       // but it know how to print a double so compiler sees
                       // there exists a conversion operator so it automatically
                       // does cout << double(com) << endl;
}
