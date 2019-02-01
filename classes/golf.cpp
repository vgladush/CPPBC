#include "golf.h"

int main()
{
	golf gl;
	setGolf(gl, "For test", 97);
	showGolf(gl);
	if (!setGolf(gl))
		std::cout << "\"fullname is empty\"";
	showGolf(gl);
	return 0;
}
