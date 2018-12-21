#include "employee.h"

AbstractEmployee::AbstractEmployee() : first_name_("none"), last_name_("none"), job_("none") {}

AbstractEmployee::AbstractEmployee(const std::string& fn, const std::string& ln, const std::string& j)
	: first_name_(fn), last_name_(ln), job_(j) {}

void	AbstractEmployee::showAll() const
{
	std::cout << "first name: " << first_name_ << std::endl
	<< "last name: " << last_name_ << std::endl << "job: " << job_ << std::endl;
}

void	AbstractEmployee::AbstractEmployee::setAll()
{
	std::cout << "first name: ";
	std::cin >> first_name_;
	std::cout << "last name: ";
	std::cin >> last_name_;
	std::cout << "job: ";
	std::cin >> job_;
}

std::ostream& operator<<(std::ostream &os, const AbstractEmployee &e)
{
	os << e.first_name_ << " " << e.last_name_;
	return os;
}
