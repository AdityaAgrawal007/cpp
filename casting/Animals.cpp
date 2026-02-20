#include "Animal.h"

class Dog : public Animal {
public:
    void MakeSound() override {
        cout << "Bark!" << endl;
    }

    void FeedDisNigga() {
        cout << "Eat this bitch!" << endl;
    }
};

class Cat : public Animal {
public:
    void MakeSound() override {
        cout << "Meow!" << endl;
    }
};

// Factory function (factory = object-creator) - creates objs returns them through common parent type, thus hiding
// which class is exactly being used (encapsulation), decouples creation from usage (abstraction)
Animal* CreateAnimal(const string& type) {
    if (type == "dog")
        return new Dog(); // Dog* is automatically converted to Animal 
    if (type == "cat")
        return new Cat();
    return nullptr;
}