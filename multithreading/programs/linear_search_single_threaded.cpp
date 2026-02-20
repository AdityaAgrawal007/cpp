#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

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

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Error: no arguments provided!" << endl;
    return -1;
  }
  // if (!isdigit(argc)) {
  //   cout << "Error: Invalid argument argc, must be int" << endl;
  //   return -1;
  // }
  for (int i = 1; i < argc; ++i) {
    if (!isValidInteger(argv[i])) {
      cout << "Error: '" << argv[i] << "' is not a valid integer. Skipping." << endl;
      return -1;
    }
  }

  const int no_elements = 100000000;
  // int search_array[no_elements]; for a large input it will cross the stack limit hence we must allocate on heap
  // int *search_array = new int[no_elements];
  vector<int> search_array(no_elements);
  unordered_map<int, bool> map;
  struct timespec start, end;

  for (int i = 0; i < no_elements; ++i) {
    search_array[i] = i;
  }

  // for (int x : search_array) {
  //   cout << x << " ";
  // }
  cout << endl;
  cout << endl;

  cout << "map check: " << endl;
  for (int i = 1; i < argc; ++i) {
    cout << atoi(argv[i]) << " ";
    // cout << int(*argv[i]) - '0' << " ";
    // map[int(*argv[i])] = 1;
    map[atoi(argv[i])] = 1;
  }
  cout << endl;
  cout << endl;

  for (auto iterator : map) {
    cout << iterator.first << ": " << iterator.second << " ";
  }
  cout << endl;
  cout << endl;

  cout << "Initiating loop on thread: " << this_thread::get_id() << endl;
  clock_gettime(CLOCK_MONOTONIC, &start);
  cout << "Timestamp: sec: " << start.tv_sec << " nsec: " << start.tv_nsec << endl;
  for (int i = 0; i < no_elements; ++i) {
    if (map[search_array[i]])
      cout << "Element: " << search_array[i] << " found at index" << i << endl;
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  cout << "Task Completed by thread: " << this_thread::get_id() << endl;
  cout << "Timestamp: sec: " << end.tv_sec << " nsec: " << end.tv_nsec << endl;
  long long total_sec = (end.tv_sec - start.tv_sec);
  long long total_nsec = (end.tv_nsec - start.tv_nsec);
  cout << "Total time needed for operation: sec: " << total_sec << " nsec: " << total_nsec << endl;
}
