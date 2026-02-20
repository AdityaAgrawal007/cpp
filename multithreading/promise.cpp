#include <exception>
#include <functional>
#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace std;

// promise is an object that holds a future value, it starts empty though
// the following function fills the promise with a value
void RetrieveValue(promise<int> &result) {
  try {
    int ans = 21095022;
    result.set_value(ans);
  } catch (...) {
    result.set_exception(current_exception());
  }
}

int main() {
  // create a promise object
  promise<int> pr;
  // associate a future object with the promise
  future<int> f = pr.get_future();
  // the result of the thread is set to the promise
  thread th(RetrieveValue, ref(pr));
  try {
    int result = f.get();
    cout << "Result: " << result << endl;
  } catch (const exception &e) {
    cerr << "Exception is: " << e.what() << endl;
  }
  th.join();
}
