#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void MakeSound() { cout << "Animal\n"; }
};

class Dog : public Animal
{
public:
    void MakeSound() override { cout << "Bark\n"; }
    void bark() { cout << "Woof woof\n"; } // derived-only
};

int main()
{
    Animal* a = new Dog();
    Dog *d = dynamic_cast<Dog *>(a); // downcasting 
    d->bark();
}