#include <iostream>
using namespace std;

template <class T, int max> int arrMin(T arr[], int n) {
  int m = max;
  for (int i = 0; i < n; i++)
    if (arr[i] < m)
      m = arr[i];
  return m;
}

int main() {

  int arr1[] = {10, 20, 15, 12};
  int n1 =
      sizeof(arr1) /
      sizeof(arr1[0]); // sizeof() is an operator and not a function as the
                       // compiler should evaluate it at compile time unlike
                       // functions which are evaluated at runtime. it's a unary
                       // compile time operator (takes only one operand)
  char arr2[] = {1, 2, 3};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  cout << arrMin<int, 10000>(arr1, n1) << endl;
  cout << arrMin<char, 256>(arr2, n2);

  return 0;
}
