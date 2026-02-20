#include <iostream>
#include <ratio>
#include <vector>
using namespace std;

int main() {
  vector<int> test(5);
  test[0] = 1;
  if (test[0]) {
    cout << "check";
  }
}
