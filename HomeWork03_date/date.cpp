#include <regex>
#include "date.h"

My_date::My_date(const std::string & dt)
{
	set_date(dt);
}

void	My_date::set_date(const std::string & dt)
{
	std::cmatch res;
	std::regex check("(\\d{2,4})([\\.-]{1})(\\d{2})([\\.-]{1})(\\d{2,4})");

	if (!std::regex_match(dt.c_str(), res, check) || res[2] != res[4] ||
		(res[1].length() != 2 && res[5].length() != 2) || res[1].length() == res[5].length())
	{
		throw std::exception();
	}

	m = stoi(res[3]);
	if (m > 12 || m < 1)
		throw std::exception();
	y = stoi((res[1].length() == 2 ? res[5] : res[1]));
	d = stoi((res[1].length() == 2 ? res[1] : res[5]));

	if (d > 31 || d < 1)
		throw std::exception();
	else if (m == 2)
	{
		if (!(y % 4) && ((y % 100) || !(y % 400)))
		{
			if (d > 29)
				throw std::exception();
		}
		else if (d > 28)
			throw std::exception();
	}
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		throw std::exception();
	dd = (y - 1) * 365 + ((y - 1) / 4) - ((y - 1) / 100) + ((y - 1) / 400);
	dd += d;
	dd += (m - 1) * 31;
	if (m > 2)
		dd -= ((!(y % 4) && ((y % 100) || !(y % 400))) ? 2 : 3);
	if (m > 11)
		dd -= 4;
	else if (m > 9)
		dd -= 3;
	else if (m > 6)
		dd -= 2;
	else if (m > 4)
		dd -= 1;
}

int		My_date::get_in_days() const
{
	return dd;
}


My_date::~My_date() {}

int		My_date::operator-(My_date const & dt) const
{
	return dd - dt.get_in_days();
}

void	operator>>(std::istream &is, My_date & dt)
{
	std::string s;
	is >> s;
	dt.set_date(s);
}

std::ostream	&operator<<(std::ostream &o, const My_date & d)
{
	o << d.get_day() << "-" << d.get_month() << "-" << d.get_year() << std::endl;
	return o;
}

int		My_date::get_day() const
{
	return d;
}

int		My_date::get_month() const
{
	return m;
}

int		My_date::get_year() const
{
	return y;
}
