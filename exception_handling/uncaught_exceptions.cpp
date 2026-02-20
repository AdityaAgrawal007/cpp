// Customizing Termination Behaviour for Uncaught Exceptions
#include <exception>
#include <iostream>

using namespace std;

// when an exception is raised but isn't catched maybe because the exception
// catching subsystem fails to find a matching catch block for a particular
// exception, it calles the unexpected() (defines behaviour when when an
// uncaught exception arises) and this fxn by default calls terminate() (defines
// actions to be performed during process termination) which in turn by default
// calls abort() and the process is aborted

// set_terminate(terminate_handler newhandler) to override the above behaviour

void customTerminator() {
  cout << "I'll be back" << endl;
  // abort(); the terminate will call abort() even if not mentioned
}

int main() {

  set_terminate(customTerminator);

  try {
    cout << "try block initiated" << endl;
    throw 100;
  } catch (char a) {
    cout << "Catch block initiated" << endl;
  }

  return 0;
}
