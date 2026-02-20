#include <iostream>
using namespace std;

// static storage duration - objs memory is allocated once for the entire lifetime of the program, not created and destroyed when scope begins/ends, constructed beforue main() starts, destroyed after main() ends, comes from global variables, namespace scope variables, static inside functions, static class members, constexpr variables at namespace scope, address stays same, 0 init by defalut
// thread safety - if one thread is wrting on object a then other threads should be prevented from reading or writing on it simoultaneously that's thread safety

// Automatic Storage Duration: Objects with automatic storage duration are created at the point of definition and destroyed when the scope in which they are declared is exited. These objects are also known as "local" or "stack" objects. Function parameters and local non-static variables fall into this category

// Dynamic Storage Duration: Objects with dynamic storage duration are created at runtime, using memory allocation functions such as new or malloc. The lifetime of these objects must be managed manually

int main(){

}
