#include <ctime>
#include <iostream>
#include <mutex>
#include <string.h>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

class env {
public:
  env(unordered_map<int, bool> &map, vector<int> search_space) : class_map(map), class_search_space(search_space) {
  }

  void worker_function(int i, int start_index, int end_index) {
    cout << "Executing Thread: " << this_thread::get_id() << endl;
    for (int i = start_index; i <= end_index; ++i) {
      // if (class_map[class_search_space[i]]) {
      //   class_map.erase(class_search_space[i]);
      //   cout << "Element: " << class_search_space[i] << " found at index: " << i << endl;
      // }
      int value = class_search_space[i];
      {
        lock_guard<mutex> lock(mtx);
        if (class_map.find(value) != class_map.end()) {
          class_map.erase(value);
          cout << "Element: " << class_search_space[i] << " found at index: " << i << " by thread: " << this_thread::get_id() << endl;
        }
      }
    }
  }

private:
  unordered_map<int, bool> &class_map;
  vector<int> class_search_space;
  mutex mtx;
};

bool isValidInteger(const char *ch) {
  if (ch == nullptr || *ch == '\0') {
    cout << "Error: argv cannot be empty" << endl;
    return false;
  }
  if (ch[0] == '-') {
    cout << "Error: negative numbers not allowed!" << endl;
    return false;
  }
  for (int i = 0; ch[i] != '\0'; ++i) {
    if (!isdigit((unsigned char)ch[i])) {
      cout << "Error: '" << ch << "' is not a valid integer!" << endl;
      return false;
    }
  }
  return true;
}

int main(int argc, char *agrv[]) {
  if (argc < 2) {
    cout << "Error: no arguments provided!" << endl;
    return -1;
  }
  for (int i = 1; i < argc; ++i) {
    if (!isValidInteger(agrv[i])) {
      cout << "Error: '" << agrv[i] << "' is not a valid integer. Skipping." << endl;
      return -1;
    }
  }
  int no_of_elements = 10000000;
  int no_of_threads = 30;
  vector<int> search_space(no_of_elements);
  thread thread_pool[no_of_threads];
  int no_elements_per_thread = no_of_elements / no_of_threads;
  struct timespec start_timestamp, end_timestamp;
  unordered_map<int, bool> map;

  for (int i = 0; i < no_of_elements; ++i) {
    search_space[i] = i;
  }

  for (int i = 2; i < argc; ++i) {
    map[atoi(agrv[i])] = 1;
  }

  env object(map, search_space);
  cout << "Initiating task on Parent thread: " << this_thread::get_id() << endl;

  clock_gettime(CLOCK_MONOTONIC, &start_timestamp);
  cout << "Timestamp: sec: " << start_timestamp.tv_sec << " nsec: " << start_timestamp.tv_nsec << endl;

  for (int i = 0; i < no_of_threads; ++i) {
    int start_index = i * no_elements_per_thread;
    int end_index = (i == no_of_threads - 1) ? no_of_elements - 1 : start_index + no_elements_per_thread - 1;
    // did not understand the arugments below why pass &object and define namespace explicitly ?
    thread_pool[i] = thread(&env::worker_function, &object, i, start_index, end_index);
  }
  for (int i = 0; i < no_of_threads; ++i) {
    thread_pool[i].join();
  }
  clock_gettime(CLOCK_MONOTONIC, &end_timestamp);
  cout << "Task Completed by thread: " << this_thread::get_id() << endl;

  cout << "Timestamp: sec: " << end_timestamp.tv_sec << " nsec: " << end_timestamp.tv_nsec << endl;

  long long total_seconds = end_timestamp.tv_sec - start_timestamp.tv_sec;
  long long total_nanoseconds = end_timestamp.tv_nsec - start_timestamp.tv_nsec;

  cout << "Total time needed for operation: sec: " << total_seconds << " nsec: " << total_nanoseconds << endl;
}
