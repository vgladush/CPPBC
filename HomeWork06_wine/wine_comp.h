#ifndef WINE_COMP_H
#define WINE_COMP_H

#include <iostream>
#include <valarray>

using ArrayIntT = std::valarray<int>;
using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;

class Wine
{
public:
	Wine();
	Wine(const char* l, int y);
	Wine(const char* l, int y, const int yr[], const int bot[]);
	~Wine();

	void	getBottles();
	void	show() const;
	int		sum();
	const char	*label() const;

private:
	std::string name;
	int			count = 0;
	PairArrayT	info;

};

#endif
