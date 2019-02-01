#include "employee.h"

Manager::Manager() : AbstractEmployee(), in_charge_of_(0) {}

Manager::Manager(const std::string& fn, const std::string& ln,const std::string& j, int ico)
	: AbstractEmployee(fn, ln, j), in_charge_of_(ico) {}

Manager::Manager(const AbstractEmployee& e, int ico) : AbstractEmployee(e), in_charge_of_(ico) {}

Manager::Manager(const Manager& m) : AbstractEmployee(m), in_charge_of_(m.in_charge_of_) {}

void Manager::showAll() const
{
	std::cout << "Manager data:" << std::endl;
	AbstractEmployee::showAll();
	std::cout << "In charge of: " << in_charge_of_ << std::endl;
}

void Manager::setAll()
{
	std::cout << "Enter manager data:" << std::endl;
	AbstractEmployee::setAll();
	std::cout << "In charge of: ";
	std::cin >> in_charge_of_;
}
