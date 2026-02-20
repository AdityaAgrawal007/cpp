// 1. multithreading is a technique in which program is divided into smaller units
// of execution called threads, each thread runs independantly but shares
// resources like memory, allowing multiple "INDEPENDANT" tasks to be performed
// simultaneously, even if the tasks are dependant they are synchronized so that
// while one thread is waiting for other output it will do something else and
// then switch back to over here or they can also overlap, the program creates
// threads but after that the control is passed to the os where the scheduler
// manages them 
// 2. threads inside a process share the same memory  

// 1. when we run a program file the os creates a process for that automatically
// and that inturn creates a thread by default but after that weather to create
// more threads is not decided by the os but they are created if the program
// like below makes them or libs we use make them
// 2. if the "process" ends it will kill all threads inside it no matter their
// state

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono; // the functions we want are inside nested
                             // namespace
using namespace std::chrono_literals;

long long nowMs() {
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch())
      .count();
}

void multiply(long int a, long int b) {
  cout << "Worker thread initiated: " << nowMs() << " ms" << endl;
  int result = a * b;
  cout << result << endl;
  std::this_thread::sleep_for(200ms);
  cout << "Worker thread terminated: " << nowMs() << " ms" << endl;
}

int main() {
  cout << "Main thread initiated: " << nowMs() << " ms" << endl;
  // thread t1(); - "Most Vexing Parse" it's an ambiguity in c++ - If something
  // can be parsed as a function declaration, C++ will parse it as a function
  // declaration so in this case no thread is being created instead a t1
  // function got created

  thread t1(
      multiply, 9,
      9); // 1. here t1 is the "thread handle" i.e. an object "responsible"
          // for ensuring the thread finsishes cleanely it owns the
          // thread_id/ owns that resource, 2. when we start a new thread
          // from that moment onwards it's an independant in execution but
  // 3. the function to be called in the thread must always return void
  cout << t1.joinable() << endl;

  // t1.detach();  using this here the thread t1 will surely get created but if
  // the main program ends befoure t1 can even print the first statement it
  // would kill it
  t1.join(); // this simply is an instruction to the program to wait until the
             // worker thread has finished execution if main program finishes
             // befoure the thread completes it causes a random crash

  cout << "Main thread terminated: " << nowMs() << " ms" << endl;

  return 0;
}
