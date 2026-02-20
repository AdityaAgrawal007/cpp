// RTTI - det type of obj at runtime 
#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void MakeSound() {
        cout << "Animal noises" << endl;
    }
};

class Dog : public Animal{
    public: 
    void MakeSound() override {
        cout << "Bark!" << endl;
    }
};

class Cat: public Animal{
    public:
    void MakeSound() override{
        cout << "Meow!" << endl;
    }
};

int main(){
    // implicit casting 
    // explicit casting     

    Dog doggy;
    doggy.MakeSound();
    doggy.Animal::MakeSound();

    Cat kitty;
    kitty.MakeSound();

    Animal* animal = &doggy;
    animal->MakeSound();

    // normal casting 
    int a = 5;
    double b = (double) a;
    cout << "Implicit cast: " << b << endl;
    // the above tells the compiler to perform the casting "however it can" so it can now perform 
    // multiple type conversions like const_cast, static_cast, ... until one works -> less safe 

    // static cast -> only allows conversions that are allowed for static cast, syntax -> static_cast <dest_type> (source);
    double c = static_cast<double>(a);
    cout << "Static cast: " << c << endl; 

    