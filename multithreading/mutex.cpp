// two threads try to access same res cause race condition
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int x = 0;
mutex mtx;

void increment() {

  // while aquiring the lock even if both try it simoultaneously still mutex
  // uses "atomic CPU instructiton" which means that only one core can succede
  // even if multiple attempt at the exact same moment
  mtx.lock();

  for (int i = 0; i < 1000000; ++i) {
    x = x + 1;
  }

  mtx.unlock();
}

int main() {
  thread t1(increment);
  thread t2(increment);

  t1.join();
  t2.join();

  cout << "x: " << x << endl;
  return 0;
}
