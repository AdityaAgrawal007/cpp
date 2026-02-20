#include <iostream>
#include <memory>
using namespace std;

// say we use a pointer then in a function or somewhere it get's deallocated and we still try to use that so that will syntactically be correct but not symantically hence unique_ptrs also there is another problem, say that two pointers are pointing to the same memory locationand one goes out of scope and frees that memory so we are left with one "dangling pointer"

class square {
public:
	int side;
	square(int s){
		side = s;
	}
	int area(){
		return (side * side);
	}	
};

// void do_something_with_the_square(unique_ptr<square> sqr){
	// cout << sqr->side << endl;
// };

unique_ptr<square> do_something_with_the_square(unique_ptr<square> sqr){
	cout << sqr->side << endl;
	return sqr;
}

int main(){
	// unique_ptr is pointer to an object that is unique i.e. no one else can point to it
	// unique_ptr stores one pointer only at a time. We cannot copy unique_ptr, only transfer ownership of the object to another unique_ptr using the move() method
	// if i only do unique_ptr<entity> name; then it just declares a pointer that will point to respective entity but is null 
	// below make_unique<entity>() allocates memory and returns a unique ptr owning it 
	unique_ptr<square> P1 = make_unique<square>(4);
	cout << P1->area() << endl;
	// if we pass the pass the object directly then we would be passing a copy of it which isn't unique and which isn't allowed so instead we must also pass the "ownership" or the object (taking ownership means it would be responsible to delete it after use) 
	P1 = do_something_with_the_square(move(P1));
	
	// P1->area(); using P1 again would cause a segmentation fault because when the do_something... function ended then the pointer went out of scope after which it got deleted and then we are again trying to access it 
	
	return 0;	
}

// unique_ptr<class_name> ptr_name(new class_name(constructor_params)); // outdated way 
// unique_ptr<class_name> ptr_name = make_unique<class_name>(constructor_params);// mordern way (because of exception safety) 
