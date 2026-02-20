// 1. erase remove idiom is a technique to remove elements/elements satisfying
// certain conditions from a container specially sequential containers where
// elemination of a element requires rest elements to adjust which in worst case
// may lead to O(n^2) time complexity but using this technique we can do it in a
// single parse O(n)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printAll(vector<int> &v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  cout << "Vector initially: ";
  printAll(v);

  // 2. remove_if() reorders container such that elements we want to remove are
  // moved at the end and it returns an "iterator" pointing to the new logical
  // end 2.5 here we use auto because an "iterator" is returned not a poniter
  // and it could defer as per the compiler
  // 2.6 if lambda returns true then the element should be removed and if it
  // returns false then it should be kept
  // 2.7 the remove_if loops through a range
  auto new_logical_end =
      remove_if(v.begin(), v.end(), [](int a) { return a % 2; });
  cout << "Vector after remove_if(): ";
  printAll(v);

  // 3. delets elements and shifts remaining to the left
  v.erase(new_logical_end, v.end());
  cout << "vector after erase(): ";
  printAll(v);
}
