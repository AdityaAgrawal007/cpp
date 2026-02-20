#include <iostream>
using namespace std;
// objects -> occupies storage in memory 
// memory model 

int main(){
	// stack memory -> function calls, variables etc
	// heap memory -> dynamically allocated memory
	// int* ptr = new int(5); delete ptr; - as this is stores in heap which is slow hence is not used for performance, can cause fragmentation, memory leaks (memory leaks ouccur when you dynamically allocate memory on the heap but don not free it and when the pointer goes out of scope it can no longer be accessed but it has taken up space as well, langs like go deal with this using garbage collectors that look for segments of memory no longer accessible during runtime and frees them but it comes with a cost of runtime, langs like rust does this at compile time 
	// data segment -> stores const, static, global variables that are initilized
	// code segment -> stores static, global varibales that are uninit 
	// code segment/text segment -> stores executable code generally read only
	return 0;
}
