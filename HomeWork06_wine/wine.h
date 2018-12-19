#ifndef WINE_H
#define WINE_H

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
	size_t	sum();
	const char	*label() const;

private:
	class composit
	{
	public:
		composit();
		composit(const char* l, int y);
		composit(const char* l, int y, const int yr[], const int bot[]);
		~composit();

		void	getBottles();
		void	show() const;
		size_t	sum();
		const char	*label() const;

	private:
		std::string name;
		size_t		count = 0;
		PairArrayT	info;
	};

	composit cm;
};

#endif
