#include <climits> // for INT_MAX
#include <iostream>
#include <random>
#include <thread>
#include <time.h> // struct timespec, CLOCK_MONOTONIC etc are here
using namespace std;

int main() {
  struct timespec start, end;
  // timespec has two members tv_sec for seconds and tv_nsec for nanoseconds
  // clock_gettime() quries the clock which is a kernel maintained time counter, CLOCK_MONOTONIC is used to select which clock i.e. in this case a clock that moves forward only and is not affected by system time
  int max_number = 0;
  // int array_of_random_numbers[100000000]; this is allocated on stack which is close to 400MB and the max capacity allowed for a program is around 8-9MB:) so either we can allocate on static storage (global/data segment) static storage is memory allocated at compile time with a fixed size lasting for programs entire execution or we can make a vector which will automatically allocate it on heap
  static int array_of_random_numbers[100000];
  mt19937 random_number_generator(random_device{}()); // we use mt19937 on top of random_device because we need to generate a large sequence of numbers and the performance of random_device is not good
  uniform_int_distribution<int> distribution(0, INT_MAX);

  for (int i = 0; i < sizeof(array_of_random_numbers) / sizeof(array_of_random_numbers[0]); ++i) {
    array_of_random_numbers[i] = distribution(random_number_generator);
  }

  cout << "Initiating loop on thread: " << this_thread::get_id() << endl;
  clock_gettime(CLOCK_MONOTONIC, &start);
  cout << "Timestamp: sec: " << start.tv_sec << " nsec: " << start.tv_nsec << endl;
  for (int i = 0; i < sizeof(array_of_random_numbers) / sizeof(array_of_random_numbers[0]); ++i) {
    if (max_number < array_of_random_numbers[i]) {
      max_number = array_of_random_numbers[i];
    }
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  cout << "Task Completed by thread: " << this_thread::get_id() << endl;
  cout << "Timestamp: sec: " << end.tv_sec << " nsec: " << end.tv_nsec << endl;
  long long total_sec = (end.tv_sec - start.tv_sec);
  long long total_nsec = (end.tv_nsec - start.tv_nsec);
  cout << "Total time needed for operation: sec: " << total_sec << " nsec: " << total_nsec << endl; // nanosecong logic must be handled because they can be negative ... ?

  cout << "Max Number: " << max_number << endl;
}
