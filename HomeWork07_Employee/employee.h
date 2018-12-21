#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class AbstractEmployee {
private:
	std::string first_name_;
	std::string last_name_;
	std::string job_;

public:
	AbstractEmployee();
	AbstractEmployee(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void showAll() const; // prints all data with names
	virtual void setAll(); // gets data for class fields from user
	friend std::ostream& operator<<(std::ostream& os, const AbstractEmployee& e); // prints first name & last name
	virtual ~AbstractEmployee() = 0;
};

class Employee : public AbstractEmployee {
public:
	Employee();
	Employee(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void showAll() const;
	virtual void setAll();
};

inline AbstractEmployee::~AbstractEmployee() = default;

class Manager : virtual public AbstractEmployee {
private:
	int in_charge_of_; // number of employees manager is in charge of

protected:
	int inChargeOf() const { return in_charge_of_; } // output
	void setInChargeOf(int employees) { in_charge_of_ = employees; } // input

public:
	Manager();
	Manager(const std::string& fn, const std::string& ln,const std::string& j, int ico = 0);
	Manager(const AbstractEmployee& e, int ico);
	Manager(const Manager& m);
	virtual void showAll() const;
	virtual void setAll();
};

class Fink: virtual public AbstractEmployee { // strikebreaker
private:
	std::string reports_to_; // person, who he reports to

protected:
	const std::string reportsTo() const { return reports_to_; }
	void setReportsTo(const std::string head) { reports_to_ = head; }

public:
	Fink();
	Fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	Fink(const AbstractEmployee& e, const std::string& rpo);
	Fink(const Fink & e);
	virtual void showAll() const;
	virtual void setAll();
};

class HighFink: public Manager, public Fink { // fink supervisor
public:
	HighFink();
	HighFink(const std::string& fn, const std::string& ln,const std::string& j, const std::string& rpo, int ico);
	HighFink(const AbstractEmployee& e, const std::string& rpo, int ico);
	HighFink(const Fink& f, int ico);
	HighFink(const Manager& m, const std::string& rpo);
	HighFink(const HighFink& h);
	virtual void showAll() const;
	virtual void setAll();
};

#endif // EMPLOYEE_H
