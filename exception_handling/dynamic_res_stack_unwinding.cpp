// when we dynamically allocate memory on the heap in our program and the
// program is pronoe to exceptions then that memory must be freed if there an
// exception ouccures or else memory leaks can be caused this can be done
// mannually or using unique_ptr

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

void function() {
  unique_ptr<int> data(new int(10)); // destructor of unique_ptr automatically
                                     // frees the allocated memoroy
  // int *data = new int(10);
  cout << "Resource allocated: " << *data << endl;
  throw runtime_error("An error ouccured");
}

int main() {
  try {
    function();
  } catch (const exception &e) {
    cout << e.what() << endl;
  }
  return 0;
}
