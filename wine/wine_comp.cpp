#include "wine_comp.h"

using std::cin;
using std::cout;

Wine::Wine() {}

Wine::Wine(const char* l, int y) : name(l), count(y) {}

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : name(l), count(y)
{
	info.first.resize(y);
	info.second.resize(y);
	for (int i = 0; i < y; ++i)
	{
		info.first[i] = yr[i];
		info.second[i] = bot[i];
	}
}

Wine::~Wine() {}

void	Wine::getBottles()
{
	if (info.first.size() < (unsigned)count)
	{
		info.first.resize(count);
		info.second.resize(count);
		for (int i = 0; i < count; ++i)
		{
			cout << name << " " << i + 1 << " of " << count << std::endl;
			cout << "Enter year of bottling: ";
			cin >> info.first[i];
			cout << "Enter number of bottles: ";
			cin >> info.second[i];
		}
	}
}

void	Wine::show() const
{
	for (int i = 0; i < count; ++i)
	{
		cout << name << " " << i + 1 << " of " << count << std::endl
		<< "year: " << info.first[i] << " bottles: " << info.second[i] << std::endl;
	}
}

const char	*Wine::label() const
{
	return name.c_str();
}

int	Wine::sum()
{
	return info.second.sum();
}
