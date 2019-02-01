#ifndef DATE_H
#define DATE_H

#include <iostream>

class My_date
{
public:
	My_date(const std::string & dt = "01.01.1987");
	~My_date();
	int		get_in_days() const;
	void	set_date(const std::string & dt);
	int		operator-(My_date const & dt) const;
	int		get_day() const;
	int		get_month() const;
	int		get_year() const;

private:
	int d;
	int m;
	int y;
	int dd;

};

void	operator>>(std::istream &is, My_date & s);
std::ostream &operator<<(std::ostream &o, const My_date & s);

#endif
