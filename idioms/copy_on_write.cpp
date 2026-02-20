// 1. COW/Lazy copy - delay doing an expensive copy until the moment someone
// actually tries to modify the shared data, ex: two pointers point to the same
// memory location so on init we don't make a seperate copy for the other one
// until we try to modify it

#ifndef COWPTR_HPP
#define COWPTR_HPP

#include <memory>

// 2. <class T> is same as <typename T>
template <class T> class bar {};

#include <iostream>
using namespace std;

int main() {}
#endif
