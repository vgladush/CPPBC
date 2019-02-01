#include "vintage_port.h"
#include <string.h>

VintagePort::VintagePort() : Port("none", "vintage")
{
	nickname = new char[5];
	strcpy(nickname, "none");
	nickname[4] = 0;
	year = 2000;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	nickname[strlen(nn)] = 0;
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
	year = vp.year;
	delete [] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	Port::operator=(vp);
	year = vp.year;
	delete [] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	return *this;
}

void	VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << static_cast<Port>(vp);
	/* or
	const Port *p = &vp;
	os << *p;
	*/
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}
