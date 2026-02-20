#include <iostream>
#include <utility>
using namespace std;

// & i is used for processing lvalues
void utilityFun(int &i) { cout << "Processes lvalue: " << i << endl; }

// && i is used for processing rvalues
void utilityFun(int &&i) { cout << "Processes rvalue: " << i << endl; }

// named variable - any var that has a identifire ex: args and every named variable is a lvalue
// template <typename T> void Fun(T &&args) { utilityFun(args); } // args is lvalue here

// forward preservers weather the original argument was lvalue or rvalue this is called perfect forwarding
template <typename T> void Fun(T &&args) { utilityFun(std::forward<T>(args)); }

int main() {
  // lvalue = x, rvalue = 10
  int x = 10;
  Fun(10);
  // move tells compiler to treat x as rvalue no matter we input lvalue or rvalue
  Fun(10);
  Fun(std::move(x));
}
