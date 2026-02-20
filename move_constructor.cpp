#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// because copying memory from heap is expensive hence we just chnage the
// pointer that was previously pointing to that memory in heap memory, it takes
// the other pointer points it to where the original pointer was pointing and
// then makes the original one point to nullptr syntax - ClassName(className&&
// other); here className&& is "rvalue reference"

class Resources {
  int *data;
  size_t size; // int in cpp is a signed datatype, size_t is unsigned data
               // integer datatype used to store size of arrays, strings, memory
               // allocations etc

public:
  Resources(size_t s) : size(s) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
      data[i] = i * 10;
    }
    cout << "Constructor called allocated memory at: " << data << endl;
  }

  Resources(Resources &&other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
    cout << "Move Constructor called, stole Resources from: " << &other << endl;
  }

  ~Resources() {
    if (data != nullptr) {
      cout << "Destructor called, deleting memory at: " << data << endl;
      delete[] data;
    } else {
      cout << "Destructor called on null Resource" << endl;
    }
  }

  void printData() const {
    if (data) {
      cout << "Data: ";
      for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
      }
      std::cout << std::endl;
    } else {
      std::cout << "No data (resource moved)." << std::endl;
    }
  }
};

int main() {
  Resources original(5);
  original.printData();

  std::cout << "\nMoving resource...\n";
  Resources moved_resource = std::move(original);

  std::cout << "\nAfter move:\n";
  original.printData();
  moved_resource.printData();

  return 0;
}
