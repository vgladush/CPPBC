#include "port.h"
#include <string.h>

Port::Port(const char* br, const char* st, int b) : bottles(b)
{
	if (!br || !st)
		throw std::exception();
	if (strlen(st) > 19)
		throw std::exception();
	brand = new char[strlen(br) + 1];
	brand[strlen(br)] = 0;
	strcpy(brand, br);
	bzero(style, 20);
	strcpy(style, st);
}

Port::Port(const Port& p)
{
	brand = 0;
	*this = p;
}

Port& Port::operator= (const Port & p)
{
	delete [] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	brand[strlen(p.brand)] = 0;
	bzero(style, 20);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+= (int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-= (int b)
{
	if (bottles < b)
		std::cout << "Can't subtracts " << b << " bottles, because port have only " << bottles << "bottles" << std::endl;
	else
		bottles -= b;
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

