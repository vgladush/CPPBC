#include "vintage_port.h"

int main()
{
	Port t("Gallo", "tawny", 20);

	t.Show();

	t -= 5;
	std::cout << t << std::endl;
	t += 8;
	std::cout << t << std::endl << std::endl;

	Port * p2 = new VintagePort();
	p2->Show();

	Port * p3 = new VintagePort("Roods", 18, "RDS-VIN", 2015);
	p2 = p3;
	p2->Show();
	std::cout << std::endl << *(dynamic_cast<VintagePort *>(p3)) << std::endl;

	return 0;
}
