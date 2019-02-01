#include "base.h"

#include <iostream>

using basecamp::Base;

static void *vtable[] = {reinterpret_cast<void *>(&Base::this_eval), reinterpret_cast<void *>(&Base::this_printMsg)};

using func1 = int (*)(int, int);
using func2 = void (*)(const std::string&);


Base::Base() : vptr(vtable) {}

int Base::eval(int a, int b) {
	func1 f = (func1)vptr[0];
	return f(a, b);
}

int Base::this_eval(int a, int b) {
	return (a + b);
}

void Base::printMsg(const std::string& msg) {
	func2 f = (func2)vptr[1];
	f(msg);
}

void Base::this_printMsg(const std::string& msg) {
	std::cout << "[Base]: " << msg << std::endl;
}
