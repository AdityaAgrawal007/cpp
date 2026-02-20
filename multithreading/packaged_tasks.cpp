// packaged task class wraps a callabe so that they can be invoked asynchronosly, we need to invoke packaged task

#include <condition_variable>
#include <deque>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>

using namespace std;

// packaged_task<int()> is an object that wraps a callable with no arguments and returns an int and whoose result is obtained by a
// future
deque<packaged_task<int()>> task_q;
mutex mtx;
condition_variable cv;

int factorial(int N) {
  int res = 1;
  for (int i = N; i > 1; i--) {
    res *= i;
  }

  cout << "Result is = " << res << "\n";
  return res;
}

void thread1() {
  packaged_task<int()> t;
  {
    unique_lock<mutex> locker(mtx);
    cv.wait(locker, []() { return !task_q.empty(); });
    t = move(task_q.front());
    task_q.pop_front();
  }
  // this executes the callabe, stores the result internally, marks the associated future as ready
  t();
}

int main() {
  thread t1(thread1);

  // bind creates a callable that resolves to factorial(6) when invoked
  packaged_task<int()> t(bind(factorial, 6));

  future<int> fu = t.get_future();
  {
    lock_guard<mutex> locker(mtx);
    task_q.push_back(move(t));
  }
  cv.notify_one();

  cout << fu.get() << endl;

  t1.join();
}
