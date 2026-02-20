#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int x = 0;
mutex mtx;

void increment() {

  // try to lock the mutex once if it's already locked by someone else then you
  // fail
  // unique_lock<mutex> lock(mtx, try_to_lock);

  // defer_lock - value as a possible argument to the unique_lock's constructor
  // when it's used a unique_lock object is just created it does not own the
  // mutex object yet, it's a compile time constant (created at compile time)
  // it's carries no state i.e. no members it's used to disambiguate between
  // constructors of unique_lock class unique_lock(mutex& m); and
  // unique_lock(mutex& m, defer_lock_t); two of the many constructors of
  // unique_lock class
  unique_lock<mutex> lock(mtx, defer_lock);

  lock.lock();

  // takes ownership of the object assuming that it is already locked, compile
  // time constant carrying no state unique_lock<mutex> lock(mtx, adopt_lock);
 
  for (int i = 0; i < 1000000; ++i) {
    x = x + 1;
  }

  lock.unlock();
}

int main() {
  thread t1(increment);
  thread t2(increment);

  t1.join();
  t2.join();

  cout << "x: " << x << endl;
  return 0;
}
