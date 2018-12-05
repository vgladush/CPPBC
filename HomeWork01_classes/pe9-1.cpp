#include "golf.h"

void setGolf(golf& g, const char* name, int hc) {
	bzero(g.fullname, Len);
	memcpy(g.fullname, name, (strlen(name) < Len ? strlen(name) : Len - 1));
	g.handicap = hc;
}

int setGolf(golf& g) {
	std::string nm;
	std::cout << "enter fullname: ";
	std::getline(std::cin, nm);
	bzero(g.fullname, Len);
	memcpy(g.fullname, nm.c_str(), (nm.size() < Len ? nm.size() : Len - 1));
	std::cout << "enter handicap: ";
	std::getline(std::cin, nm);
	try {
		g.handicap = std::stod(nm);
	} catch (...) {
		g.handicap = 0;
	}
	if (!strlen(g.fullname))
		return 0;
	return 1;
}

void showGolf(const golf& g) {
	std::cout << g.fullname << " " << g.handicap << std::endl;
}
