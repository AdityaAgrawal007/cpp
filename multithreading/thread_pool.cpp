// what we create using thread() is just a c++ object which has the reference to
// the actuall os thread, at kernel level though a thread conist of program
// counter, cpu registers, a call stack, thread local storage, kernel schedule
// info, thread_id, pointer to code it's executing

// thread pool - group of worker threads - create a set of threads that can be
// reused, this saves the overhead that ouccers in creating and destroying them

#include <algorithm>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

class thread_pool // size_t returns an unsigned int type which is basically
                  // whole numbers and is thus used when negative values do not
                  // make sence i.e. in the case of denoting the size of arrays
                  // etc ...
{
public:
  thread_pool(
      size_t num_threads =
          thread::hardware_concurrency()) // the hardware_concurrency() returns
                                          // the maximum number of threads that
                                          // can run on that processor, this
                                          // default value is only used when no
                                          // argument is passed to the
                                          // constructor
  {
    for (size_t i = 0; i < num_threads;
         ++i) { // this for loop runs in the main thread and the while loop
                // inside runs in the respective worker threads hence the
                // internal while loop does not block this one they are
                // independant
      threads_.emplace_back(
          [this]() { // the emplace_back() is used to creat a thread directly at
                     // the end of a vector, the lambda passed to it will be
                     // used as an argument for the constructor of the thread.
                     // This is same as writing -
                     // threads_.push_back(std::thread(lambda)), so now as a
                     // lambda "function" has been passed to the thread() it
                     // will start executing it immediatly
            while (true) {
              function<void()> task;
              {
                unique_lock<mutex> lock(queue_mutex_);
                cv_.wait(lock, [this] {
                  return !tasks_.empty() || stop_;
                }); // we just created the thread now this line parks it i.e.
                    // wait until either there is some task to do or the
                    // destructor is asking to exit
                if (stop_ && tasks_.empty()) {
                  return;
                }
                task = move(tasks_.front());
                tasks_.pop();
              }
              task();
            }
          });
    }
  } // emplace_back() creates a new element at the back of the vector

  ~thread_pool() {
    {
      unique_lock<mutex> lock(queue_mutex_);
      stop_ = true;
    }

    cv_.notify_all();

    for (auto &thread : threads_) {
      thread.join();
    }
  }

  void enqueue(function<void()> task) {
    {
      unique_lock<std::mutex> lock(queue_mutex_);
      tasks_.emplace(move(task)); // append to the queue
    }
    cv_.notify_one();
  }

private:
  vector<thread> threads_;
  queue<function<void()>>
      tasks_; // function<void()> it's like a datatype for storing // funciton
              // that has no arguments and returns nothingg
  mutex queue_mutex_;
  condition_variable cv_;
  bool stop_ = false;
};

int main() {
  thread_pool pool(4);

  for (int i = 0; i < 5; ++i) { // pass lambdas to the enqueu function
    pool.enqueue([i] {
      cout << "task " << i << " is running on thread " << this_thread::get_id()
           << endl;
      this_thread::sleep_for(chrono::milliseconds(100));
    });
  }

  return 0;
}
