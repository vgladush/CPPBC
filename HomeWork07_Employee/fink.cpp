#include "employee.h"

Fink::Fink() : AbstractEmployee(), reports_to_("none") {}

Fink::Fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	: AbstractEmployee(fn, ln, j), reports_to_(rpo) {}

Fink::Fink(const AbstractEmployee& e, const std::string& rpo) : AbstractEmployee(e), reports_to_(rpo) {}

Fink::Fink(const Fink & e) : AbstractEmployee(e), reports_to_(e.reports_to_) {}

void Fink::showAll() const
{
	std::cout << "Fink data:" << std::endl;
	AbstractEmployee::showAll();
	std::cout << "Reports to: " << reports_to_ << std::endl;
}

void Fink::setAll()
{
	std::cout << "Enter fink data:" << std::endl;
	AbstractEmployee::setAll();
	std::cout << "Reports to: ";
	std::cin >> reports_to_;
}
