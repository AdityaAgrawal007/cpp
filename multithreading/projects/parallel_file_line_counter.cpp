#include <atomic>
#include <condition_variable>
#include <endian.h>
#include <fstream>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using namespace std;

atomic<int> done = 0;
vector<string> v;
vector<int> output;
mutex out_mtx;

class ThreadPool {

public:
  ThreadPool(size_t n = thread::hardware_concurrency()) {
    for (int i = 0; i < n; ++i) {
      pool.emplace_back([this]() {
        function<void()> task;

        while (true) {
          unique_lock<mutex> lock(mtx);

          cv_.wait(lock, [this]() { return !tasks_.empty() || stop_; });

          if (tasks_.empty() && stop_) {
            return;
          }
          task = std::move(tasks_.front());
          tasks_.pop();
          task();
        }
      });
    }
  }

  ~ThreadPool() {
    stop_ = true;
    cv_.notify_all();
    for (int i = 0; i < pool.size(); ++i) {
      pool[i].join();
    }
  }

  void enqueue(function<void()> task) {
    unique_lock<mutex> lock(mtx);
    tasks_.emplace(std::move(task));
    cv_.notify_one();
  }

  // private:
  vector<thread> pool;
  queue<function<void()>> tasks_;
  mutex mtx;
  condition_variable cv_;
  int stop_ = false;
};

int main() {
  size_t n;
  cout << "Enter the number of files: " << endl;
  cin >> n;
  ThreadPool T(n);

  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    v.push_back(str);
    T.enqueue([i]() {
      int linecount = 0;
      string line;
      fstream file(v[i], ios::in);
      while (getline(file, line)) {
        linecount++;
      }
      file.close();

      {
        lock_guard<mutex> lk(out_mtx);
        output.push_back(linecount);
      }

      done++;
    });
  }

  while (done < n) {
  }
  for (int i = 0; i < output.size(); ++i) {
    cout << output[i] << endl;
  }
  return 0;
}
