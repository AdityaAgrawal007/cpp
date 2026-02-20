#include <cmath>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std;

void WriteToLog(int32_t log_fd, string &event) {
  write(log_fd, event.c_str(), event.size());
  write(log_fd, "\n", 1);
}

int main(int argc, char **argv) {
  // fixed width integer types - intN_t - on diffrent compiler/os/hardware there
  // can be diffrent sizes of datatypes ex: somewhere it might be 32bits, 64bits
  // somewhere else but if we want it to be preciesly say 32bits then we use the
  // following -
  int32_t log_fd =
      // open() is a low level POSTFIX system call that returns a int file
      // descriptor(its an integer that the os assigns to a open file to
      // identify it)
      open("log.txt", O_RDWR); // the second argument means open a file in both
                               // reading and write mode
  if (log_fd < 0) {
    cerr << "Failed to open file" << endl;
    return -1;
  }

  string s = "Log1";
  string s0 = "Log2";

  WriteToLog(log_fd, s);
  WriteToLog(log_fd, s0);

  // close(log_fd); if this line is not there the open file descriptors can
  // cause problems
  return 0;
}
