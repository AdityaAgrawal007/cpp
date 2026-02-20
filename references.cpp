// refs are 
#include <iostream>
using namespace std;

int main(){
	// pointers
	int x = 10;
	int* ptr = &x;
	// cout << x << endl;
	// cout << ptr << endl;
	// cout << *ptr << endl;
	
	//types of const pointers 
	// const int* c1ptr = x; //data it points to cannot be changed;
	// int* const c2ptr = x; //c2ptr cannot point to something diffrent 
	// const int* const c3ptr = x; //both the above combined 

	//refs - cannot change what it points to, doesn't have it's own address like pointer. also cannot be init to NULL like a pointer 
	
	int& ref = x;
	cout << &x << endl;
	cout << &ref << endl;
	cout << ref << endl;
}
