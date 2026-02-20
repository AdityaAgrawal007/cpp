#include <iostream>
using namespace std;

// virtual table or the vTable is a table of function pointers that is created by the compiler to support dynamic polymorphism, a vTable is created by the compiler for a class that contains a virtual function and each object of this class is provided with a pointer to that table called the 'vPtr'

class Base {
public:
    virtual void function1()
    {
        cout << "Base function1()" << endl;
    }
    virtual void function2()
    {
        cout << "Base function2()" << endl;
    }
    virtual void function3()
    {
        cout << "Base function3()" << endl;
    }
};
// the base class has three virtual functions to the vTable will have three entries pointing here

class Derived1 : public Base {
public:
    void function1()
    {
        cout << "Derived1 function1()" << endl;
    }
};
// the vTable for Derived1 class will contain the overiden function 1 but remaning will stay as it is 


class Derived2 : public Derived1 {
public:
    void function2()
    {
        cout << "Derived2 function2()" << endl;
    }
};

// driver code
int main()
{
    // defining base class pointers
    Base* ptr1 = new Base();
    Base* ptr2 = new Derived1();
    Base* ptr3 = new Derived2();

    // calling all functions
    ptr1->function1();
    ptr1->function2();
    ptr1->function3();

    ptr2->function1();
    ptr2->function2();
    ptr2->function3();

    ptr3->function1();
    ptr3->function2();
    ptr3->function3();

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}
