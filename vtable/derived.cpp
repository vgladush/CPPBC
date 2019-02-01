#include "derived.h"

#include <iostream>

using basecamp::Derived;

static void *vtable[] = {reinterpret_cast<void *>(&Derived::eval), reinterpret_cast<void *>(&Derived::printMsg)};

Derived::Derived() {
	vptr = vtable;
}

int Derived::eval(int a, int b) {
	return a * b;
}

void Derived::printMsg(const std::string& msg) {
	std::cout << "[Derived]: " << msg << std::endl;    
}
