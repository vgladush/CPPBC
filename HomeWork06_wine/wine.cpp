#include "wine.h"

using std::cin;
using std::cout;

Wine::Wine() {}

Wine::Wine(const char* l, int y) : cm(l, y) {}


Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : cm(l, y, yr, bot) {}

Wine::~Wine() {}

void	Wine::getBottles()
{
	cm.getBottles();
}

void	Wine::show() const
{
	cm.show();
}

const char	*Wine::label() const
{
	return cm.label();
}

size_t	Wine::sum()
{
	return cm.sum();
}

Wine::composit::composit() {}

Wine::composit::composit(const char* l, int y) : name(l), count(y) {}

Wine::composit::composit(const char* l, int y, const int yr[], const int bot[]) : name(l), count(y)
{
	info.first.resize(y);
	info.second.resize(y);
	for (int i = 0; i < y; ++i)
	{
		info.first[i] = yr[i];
		info.second[i] = bot[i];
	}
}

Wine::composit::~composit() {}

void	Wine::composit::getBottles()
{
	if (info.first.size() < count)
	{
		info.first.resize(count);
		info.second.resize(count);
		for (unsigned i = 0; i < count; ++i)
		{
			cout << name << " " << i + 1 << " of " << count << std::endl;
			cout << "Enter year of bottling: ";
			cin >> info.first[i];
			cout << "Enter number of bottles: ";
			cin >> info.second[i];
		}
	}
}

void	Wine::composit::show() const
{
	for (unsigned i = 0; i < count; ++i)
	{
		cout << name << " " << i + 1 << " of " << count << std::endl
		<< "year: " << info.first[i] << " bottles: " << info.second[i] << std::endl;
	}
}

const char	*Wine::composit::label() const
{
	return name.c_str();
}

size_t	Wine::composit::sum()
{
	return info.second.sum();
}
