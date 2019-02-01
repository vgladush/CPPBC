#include <iostream>

#include "base.h"
#include "derived.h"

using basecamp::Base;
using basecamp::Derived;

int main() {

	constexpr int a = 3;
	constexpr int b = 4;
	const std::string msg { "Ready to eval..." };
	
	Base* base = new Base;
	Base* deriv = new Derived;
	base->printMsg(msg);
	std::cout << base->eval(a, b) << std::endl;
	deriv->printMsg(msg);
	std::cout << deriv->eval(a, b) << std::endl;
	delete base;
	delete deriv;

	return 0;
}
