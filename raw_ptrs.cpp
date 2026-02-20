#include <iostream>

using namespace std;
// raw pointer is the one whoose lifetime isn't controlled by an encapsulating object like a smart poniter 
int main(){
	int x = 10; // memoroy is allocated on heap
	int* ptr = &x;
	// pointer arithmatic - incrementing pointer by a offset to iterate but not possible with "const" On 64-bit operating systems, a pointer has a size of 64 bits. A system's pointer size determines how much addressable memory it can have, pointers can be made to point to different datatypes using +=, -=, ++, -- 
	cout << ptr << endl;
	cout << ++ptr << endl; // here ptr moves by 4bytes - type scaled incrementation
	cout << --ptr << endl;
	// ptr += 5;
	// cout << ptr << endl;
	// the below does not work due to operator precedence - =   +=   -=   *=   /=   <<=   >>=   &=   ^=   |= 
	// cout << ptr += 5 << endl;
	
	int arr[5] = {1, 2, 3, 4, 5};
	int* ptr1 = &arr[0];
	int* ptr2 = &arr[4];

	cout << ptr2 - ptr1 << endl; // pointer substraction returns the number of elements between the two indexes "of the same array object"

	// pointer comparision 
	int* a = &x;	
	int** c = &a;
	int* b = *c;
	if(a == b) cout << "same location" << endl;
	else cout << "diff location" << endl;

}
