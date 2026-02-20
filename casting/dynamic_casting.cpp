#include <iostream>
using namespace std;

class Base
{
public:
    virtual void BaseCall(void)
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
    public:
    void SpecialDerivedFunction(){
        cout << "Sp Derived Function" << endl;
    }
};

int main()
{
    // --------SLOP---------------
    // Base b;
    // b.BaseCall();

    // Derived d;
    // d.BaseCall();
    // d.SpecialDerivedFunction();

    // Base b;
    // Base* bp = &b;
    // bp->BaseCall();

    // ------SLOP ENDS-----------------

    // for accessing a derived class object using a base class pointer - upcasting 
    // Derived d;
    // Base* bp = &d;
    // or 
    Base* bp = new Derived();
    // can still only access the base class functions
    // bp->BaseCall();

    // now say we want to access some special function in derived class so 
    // we must downcast the bp pointer form Base class to Derived class 
    // to use dynamic cast the "base class must be polymorphic i.e. it must have at least one virtual function"
    // dynamic casting is used FOR "safe downcasting" when we only have a Base pointer, we don't know the derived 
    // class type it refers to and thus we cannot create an object for that derived class 
    // dynamic_cast uses RTTI 
    Derived* d2 = dynamic_cast<Derived*>(bp);
    d2->SpecialDerivedFunction();
}

