// 1. allow container traversal without exposing internal structure
// 2. support container independant functions
// 3. types - input, output, forward, bi-directional, random access
// 4. container_type::iterator

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {10, 20, 30};

  for (vector<int>::iterator i = v.begin(); i != v.end();
       i++) { // .end() returns an iterator to the therotical element just after
              // the last element
    cout << *i << " ";
  }
  cout << endl;

  // cbegin(), cend() return a const_iterator i.e. it can only read but not
  // modify
  for (auto i = v.cbegin(); i != v.cend();
       i++) {          // i++ increment & decrement operation on iterators
    cout << *i << " "; // dereferencing operation
  }
  cout << endl;

  for (auto i = v.rbegin(); i != v.rend();
       i++) { // rbegin() points to the last elements and rend() points to the
              // therotical element present befoure the first element
    cout << *i << " ";
  }
  cout << endl;

  // some operations can only be performed for random access iterators like those in vectors etc not in ones that are in list, map...
  vector<int>::iterator i = v.begin();
  i = i + 1;
  cout << *i << endl;
  i = i + 1;
  cout << *i << endl;
  *i = *i + 1;
  cout << *i << endl;

  // iterator adapters - built over traditional iterators - reverse iterators, move iterators, stream iterators, inserter iterator
  return 0;
}
