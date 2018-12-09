#include "date.h"

int main()
{

	My_date ds1("2000-01-01");
	My_date ds2("1222.12.11");
	My_date ds3("10.12.2018");

	std::cout << ds2;
	std::cout << ds3 - ds1 << std::endl;

/*	for exception
	My_date excp1("12.12-2005");
	//or
	My_date excp2("05.13.2005");
	//or
	My_date excp3("31-04-2011");
*/
	return 0;
}
