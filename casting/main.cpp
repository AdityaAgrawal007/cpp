#include "Animal.h"

// Forward declaration (telling compiler this function exists)
Animal *CreateAnimal(const string &type);

int main()
{
    string userChoice;
    cout << "Enter animal (dog/cat): ";
    cin >> userChoice;

    //     Because userChoice is unknown at compile time, the exact object type (Dog or Cat) is chosen at runtime.
    // Then the correct overridden function (Bark or Meow) is called at runtime.

    // upcasting(safer) - treating a derived class object as if it were a base class object, compiler does it automatically      
    Animal *a = CreateAnimal(userChoice);

    if (a)
    {
        // downcasting is riskerier as it may cause runtime errors 
        a->MakeSound();
        // a->FeedDisNigga() isn't accessible cause MakeSound() is a member of the parent class
        // whereas FeedDisNigga() is a member of the derived class, USING UPCASTING BASE CLASS CANNOT 
        // ACCESS DERIVED CLASS MEMBERS!!!
    }
    else
    {
        cout << "Unknown animal type\n";
    }

    delete a;
}
