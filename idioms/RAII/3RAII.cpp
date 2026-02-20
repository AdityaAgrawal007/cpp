// Resource Aquisition is initilization (RAII)/Scope bound resource managment
// (SBRM) is a c++ programming technique which binds the life cycle of a
// resource to the lifetime of an object. this gaurentees that if resource
// Aquisition fails then then constructor exits with an exception

#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std;

class Logger {
public:
  // explicit keyword prevents the compiler from doing implicit conversions
  // using a constructor
  // here if some error ouccers then the constructor doesn't show
  explicit Logger(const string &log_file_path) {
    log_fd = open(log_file_path.c_str(), O_RDWR);
  }

  void Log(string &event) {
    // the write(int file_descriptor, const void* ptr_to_where_we_want_to_write,
    // size_t count_of_homManyBytesToWrite) sys call returns the no. of bytes
    // written or returns -1 if error ouccured
    if (write(log_fd, event.c_str(), event.length()) != event.length()) {
      cout << "Failed operation" << endl;
    }
  }

  ~Logger() { close(log_fd); }

private:
  int32_t log_fd;
};

int main() {
  Logger logger = Logger("log.txt");
  string s = "hello, world !\n";
  logger.Log(s);
  // logger.Log("hello, world!"); this won't work because "hello, world!" is a
  // const char[] literal which becomes temporary string when passed to a
  // function only if the function parameter allows binding to the temporary but
  // in this case a non const reference cannot bind to a temporary
  return 0;
}
