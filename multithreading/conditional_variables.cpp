#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx;
condition_variable cv;

// spurious wakeup happens when a thread is woken up(taking it from
// waiting/sleeping state to runnable state after which cpu eventually pick it
// up to run it) from sleeping state while it was waiting for a conditional
// variable but when it wakes up it finds that the cv isn't changed and it was
// woken up for no apparent reason. This might happen if multiple threads are
// woekn up they race for the cv and only one is finds the condition satisfied,
// it also happens sometime if library implementations is such that it causes it
bool data_ready = false;

void producer() {
  // simulaiton
  this_thread::sleep_for(chrono::seconds(2));

  lock_guard<mutex> lock(mtx);

  data_ready = true;

  cout << "Produced" << endl;

  // the notify_one function notifys one thread that waiting at random
  cv.notify_one();
}

void consumer() {
  unique_lock<mutex> lock(mtx);

  // the 2nd ardument is a predicate first it checks if the predicate is false
  // then unlock the mutex then sleep wake up if there is a notificatoin or
  // spurious wake up then relock the mutex check the predicate again return
  // from wait util predicate is true
  cv.wait(lock, []() { return data_ready; });

  cout << "Consumed" << endl;
}

int main() {

  thread t1(consumer);
  thread t2(producer);

  t2.join();
  t1.join();

  return 0;
}
