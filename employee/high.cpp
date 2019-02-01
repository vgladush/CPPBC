#include "employee.h"

HighFink::HighFink() : AbstractEmployee(), Manager(), Fink() {}

HighFink::HighFink(const std::string& fn, const std::string& ln,const std::string& j, const std::string& rpo, int ico)
	: AbstractEmployee(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {}

HighFink::HighFink(const AbstractEmployee& e, const std::string& rpo, int ico)
	: AbstractEmployee(e), Manager(e, ico), Fink(e, rpo) {}

HighFink::HighFink(const Fink& f, int ico) : AbstractEmployee(f), Manager(f, ico), Fink(f) {}

HighFink::HighFink(const Manager& m, const std::string& rpo) : AbstractEmployee(m), Manager(m), Fink(m, rpo) {}

HighFink::HighFink(const HighFink& h) : AbstractEmployee(h), Manager(h), Fink(h) {}

void HighFink::showAll() const
{
	std::cout << "High Fink data:" << std::endl;
	AbstractEmployee::showAll();
	std::cout << "Reports to: " << reportsTo() << std::endl << "In charge of: " << inChargeOf() << std::endl;
}

void HighFink::setAll()
{
	std::string s;
	int i = 0;
	std::cout << "Enter high fink data:" <<std::endl;
	AbstractEmployee::setAll();
	std::cout << "Reports to: ";
	std::cin >> s;
	setReportsTo(s);
	std::cout << "In charge of: ";
	std::cin >> i;
	setInChargeOf(i);
}
