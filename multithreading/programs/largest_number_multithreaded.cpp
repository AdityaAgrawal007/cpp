#include <climits>
#include <iostream>
#include <random>
#include <thread>
#include <time.h>

using namespace std;

static int array_of_random_numbers[99999990];
static int local_maximum_per_thread[30];

void worker_function(int thread_index, int start_index, int end_index) {
  int local_maximum = 0;
  cout << "Executing Thread: " << this_thread::get_id() << endl;
  for (int i = start_index; i < end_index; ++i) {
    if (array_of_random_numbers[i] > local_maximum) {
      local_maximum = array_of_random_numbers[i];
    }
  }

  local_maximum_per_thread[thread_index] = local_maximum;
}

int main() {
  int number_of_threads = 30;
  int total_elements = sizeof(array_of_random_numbers) / sizeof(array_of_random_numbers[0]);
  int elements_per_thread = total_elements / number_of_threads;

  struct timespec start_timestamp, end_timestamp;

  mt19937 random_number_generator(random_device{}());
  uniform_int_distribution<int> distribution(0, INT_MAX);

  for (int i = 0; i < total_elements; ++i) {
    array_of_random_numbers[i] = distribution(random_number_generator);
  }

  thread thread_pool[30];

  cout << "Initiating task on Parent thread: " << this_thread::get_id() << endl;

  clock_gettime(CLOCK_MONOTONIC, &start_timestamp);
  cout << "Timestamp: sec: " << start_timestamp.tv_sec << " nsec: " << start_timestamp.tv_nsec << endl;

  for (int i = 0; i < number_of_threads; ++i) {
    int start_index = i * elements_per_thread;
    int end_index = (i == number_of_threads - 1) ? total_elements : start_index + elements_per_thread;

    thread_pool[i] = thread(worker_function, i, start_index, end_index);
  }

  for (int i = 0; i < number_of_threads; ++i) {
    thread_pool[i].join();
  }

  int global_maximum = local_maximum_per_thread[0];
  for (int i = 1; i < number_of_threads; ++i) {
    if (local_maximum_per_thread[i] > global_maximum) {
      global_maximum = local_maximum_per_thread[i];
    }
  }

  clock_gettime(CLOCK_MONOTONIC, &end_timestamp);
  cout << "Task Completed by thread: " << this_thread::get_id() << endl;

  cout << "Timestamp: sec: " << end_timestamp.tv_sec << " nsec: " << end_timestamp.tv_nsec << endl;

  long long total_seconds = end_timestamp.tv_sec - start_timestamp.tv_sec;
  long long total_nanoseconds = end_timestamp.tv_nsec - start_timestamp.tv_nsec;

  cout << "Total time needed for operation: sec: " << total_seconds << " nsec: " << total_nanoseconds << endl;

  cout << "Max Number: " << global_maximum << endl;
}
