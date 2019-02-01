#include "wine_priv.h"

using std::cin;
using std::cout;

Wine::Wine() {}

Wine::Wine(const char* l, int y) : std::string(l), count(y) {}

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : std::string(l),
	PairArrayT(ArrayIntT(yr, y), ArrayIntT(bot, y)), count(y) {}

Wine::~Wine() {}

void	Wine::getBottles()
{
	if (PairArrayT::first.size() < (unsigned)count)
	{
		PairArrayT::first.resize(count);
		PairArrayT::second.resize(count);
		for (int i = 0; i < count; ++i)
		{
			cout << std::string::c_str() << " " << i + 1 << " of " << count << std::endl;
			cout << "Enter year of bottling: ";
			cin >> PairArrayT::first[i];
			cout << "Enter number of bottles: ";
			cin >> PairArrayT::second[i];
		}
	}
}

void	Wine::show() const
{
	for (int i = 0; i < count; ++i)
	{
		cout << std::string::c_str() << " " << i + 1 << " of " << count << std::endl
		<< "year: " << PairArrayT::first[i] << " bottles: " << PairArrayT::second[i] << std::endl;
	}
}

const char	*Wine::label() const
{
	return std::string::c_str();
}

int	Wine::sum()
{
	return PairArrayT::second.sum();
}
