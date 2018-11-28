#include "move.h"

int main()
{
	Move m1(25.67, 38.5);
	Move m2; // default 0 0

	std::cout << "m1: ";
	m1.showmove();
	std::cout << "m2: ";
	m2.showmove();

	m2.reset(53.32, 42.09);
	std::cout << "m2 changed to ";
	m2.showmove();

	m1 = m1.add(m2);
	std::cout << "m1 changed to ";
	m1.showmove();

	m1.reset();
	std::cout << "m1 reset ";
	m1.showmove();

	return 0;
}
