#include <string>
#include <vector>

using namespace std;

class bar {
public:
  void doSomething();

  // private:
  //   vector<int> data; // problem 1 - if we change anything in this file then
  //   all files that included this also need to be recompiled string name. so
  //   instead we just do the following
private:
  class impl; // forward declaration - means an assurity to the compiler that
              // something like this exists
  impl *p;
};
