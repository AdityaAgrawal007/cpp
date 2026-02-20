#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int x = 0;
mutex mtx;

void increment() {

  // when the constructor of the lock gaurd object is called it locks the
  // mutex when the destructor of the lock_gaurd object is called it unlocks the
  // mutex automatically, another feature of this being that even if the
  // function throws some exception destructor is still called
  lock_guard<mutex> lock(mtx);

  for (int i = 0; i < 1000000; ++i) {
    x = x + 1;
  }

  // mtx.unlock(); no need to write
}

int main() {
  thread t1(increment);
  thread t2(increment);

  t1.join();
  t2.join();

  cout << "x: " << x << endl;
  return 0;
}
