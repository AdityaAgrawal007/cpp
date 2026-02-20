#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <thread>
#include <time.h>
using namespace std;

int main() {
  struct timespec start, end;
  int max_number = 0;
  int min_number = INT_MAX;
  static int array_of_random_numbers[100000000];

  // generate an array of random integers
  mt19937 random_seed_generator(random_device{}());
  int size_of_array = sizeof(array_of_random_numbers) / sizeof(array_of_random_numbers[0]);
  for (int i = 0; i < size_of_array; ++i) {
    array_of_random_numbers[i] = i;
  }
  shuffle(array_of_random_numbers, array_of_random_numbers + size_of_array, random_seed_generator);

  cout << "Initiating loop on thread: " << this_thread::get_id() << endl;
  clock_gettime(CLOCK_MONOTONIC, &start);
  cout << "Timestamp: sec: " << start.tv_sec << " nsec: " << start.tv_nsec << endl;
  for (int i = 0; i < size_of_array; ++i) {
    if (max_number < array_of_random_numbers[i]) {
      max_number = array_of_random_numbers[i];
    }
    if (min_number > array_of_random_numbers[i]) {
      min_number = array_of_random_numbers[i];
    }
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  cout << "Task Completed by thread: " << this_thread::get_id() << endl;
  cout << "Timestamp: sec: " << end.tv_sec << " nsec: " << end.tv_nsec << endl;
  long long total_sec = (end.tv_sec - start.tv_sec);
  long long total_nsec = (end.tv_nsec - start.tv_nsec);
  cout << "Total time needed for operation: sec: " << total_sec << " nsec: " << total_nsec << endl; // nanosecong logic must be handled because they can be negative ... ?

  cout << "Max Number: " << max_number << endl;
  cout << "Min Number: " << min_number << endl;
}
