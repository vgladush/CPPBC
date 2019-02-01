#ifndef _DERIVED_H_
#define _DERIVED_H_

#include "base.h"

namespace basecamp {

class Derived : public Base {
public:
	Derived();
	int eval(int a, int b);
	void printMsg(const std::string& msg);

protected:
};

}

#endif
