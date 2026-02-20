#pragma once // replacement for #ifndef ANIMAL_H #define ANIMAL_H #endif
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void MakeSound() = 0; 
    virtual ~Animal() {}          
};
