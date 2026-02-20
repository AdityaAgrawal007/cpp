#include <iostream>
using namespace std;

void foo(void){
	// int counter = 0;
	static int counter = 0;
	// 1. using static keyword the variable is stored in static memory not in stack hence it remains persistant across function calls	
	counter++;
	cout << counter << endl;
}

	// 2. static name = x; now this can only be accessed in this file

class nigga {
public:
	static int y; // 3. a non-constexpr static data member cannot be init inside the class, because class is just a blueprint not a place where memory lives 
};

int nigga::y = 0;

int main(){
	foo();
	foo();	
	foo();

	nigga n;
	n.y = 1;
	cout << n.y << endl;

	return 0;
}
