#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std;

class Logger {
public:
  // here when the constructor is called then it just creates the object without
  // initilizing it i.e. now I have int32_t log_fd but that file descriptor
  // doesn't have any value and the user is free to call obj.Log("random_shit")
  // so this can lead to undefined behaviour

  Logger();

  bool Initialize(const std::string &log_file_path) {
    log_fd_ = open(log_file_path.c_str(), O_RDWR);
    return (log_fd_ < 0 ? false : true);
  }

  void Log(const std::string &event);

  ~Logger() { close(log_fd_); }

private:
  int32_t log_fd_;
};

int main(int argc, char **argv) {
  Logger logger = Logger();
  if (!logger.Initialize("log")) {
    std::cerr << "Failed to initialize logger";
    return -1;
  }
  logger.Log("some random event");
  return 0;
}
