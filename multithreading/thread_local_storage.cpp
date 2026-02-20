#include <iostream>
#include <thread>

using namespace std;

// object in thread local storage exists for the lifetime of the thread they belong to, created when the thread starts and destroyed when the thread exists  
thread_local int counter = 0;

void fun1(){
	counter++;
	cout << counter << endl;
}

void fun2(){
	counter+=2;
	cout << counter << endl;
}

int main(){
	// general syntax - thread thread_name (callable);
	// thread t1(fun1()) -> this is "calling the function" i.e. the stuff returned by the function will be passed to the thread 
	// below is "passing the function" i.e. the function itself is passed to the thread 
	thread t1(fun1);
	thread t2(fun2);

	// the main thread waits for the two so we must join them 
	t1.join();
	t2.join();

	cout << counter << endl;	
}
