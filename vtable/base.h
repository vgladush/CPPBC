#ifndef _BASE_H_
#define _BASE_H_

#include <string>

namespace basecamp {
	
class Base {
protected:
	void **vptr;

public:
	Base();
//	virtual 
	int this_eval(int a, int b);
	int eval(int a, int b);
	
//	virtual 
	void printMsg(const std::string& msg);
	void this_printMsg(const std::string& msg);
};

}

#endif
