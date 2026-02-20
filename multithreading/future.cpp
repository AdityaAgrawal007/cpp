// future is a class template used to recieve result from an asynchronous tasks
// managed using async, packaged_task, promise which return a future object.
// syntax - future <type> name;

#include <future>
#include <iostream>
using namespace std;

int returnTwo() { return 2; }

int main() {
  // async() launches a new thread with the launch::async argument and the
  // function is assigned to that thread. async calls function returning without
  // waiting for the execution of function to complete. The value returned by
  // function can be accessed throught the future
  future<int> f = async(launch::async, returnTwo);
  cout << f.get() << endl;
  // cout << f.get() << endl; the state of future is reset after getting the
  // result hence we can access the result of the computation only once. The
  // solution to this is .valid() which checks if the state of the future is
  // valid or not
}
