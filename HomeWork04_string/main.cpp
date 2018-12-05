#include <iostream>
#include "my_string.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// TESTS

	// default constructor, length, <<
	std::string os1, os2("original");
	My_string ms1, ms2("mine str");

	std::cout << std::endl << "test default constructor, length(), << :" << std::endl
	<< "orig (os1) \'" << os1 << "\' == my (ms1) \'" << ms1 << "\' and size "
	<< os1.length() << " == " << ms1.length() << std::endl << "orig (os2) \'"
	<< os2 << "\' != my (ms2) \'" << ms2 << "\', but size " << ms2.length()
	<< " == " << ms2.length() << std::endl << std::endl;

	// copy constructor, =
	std::string os3(os2);
	My_string ms3(ms2);
	os1 = os2;
	ms1 = ms2;
	std::cout << "test copy constructor, = :" << std::endl
	<< "and now orig (os1 == os3) \'" << os1 << "\' == \'" << os3 << "\' size "
	<< os1.length() << " == " << os3.length() << std::endl << "my (ms1 == ms3) \'"
	<< ms1 << "\' == \'" << ms3 << "\' size " << ms1.length() << " == "
	<< ms3.length() << std::endl << std::endl;

	//clear, >> , append, +=, +
	std::cout << "test clear, >>, append, +=, + :" << std::endl << "please enter two words for \
testing istream: first to original, second to my_string" << std::endl;

	std::cin >> os1 >> ms1;

	std::cout << "result:" << std::endl << "orig = " << os1 << ", size " << os1.length()
	<< std::endl << "my = " << ms1 << ", size = " << ms1.length() << std::endl;
	os1.clear();
	ms1.clear();
	std::cout << "orig \'" << os1 << "\' and my \'" << ms1 << "\' are empty size "
	<< os1.length() << " == " << ms1.length() << std::endl;

	
	os1 = "test ";
	ms1 = "test ";
	os1 += os2 + " " + os1 + "!";
	ms1 += ms2 + " " + ms1 + "!";
	os2.append("don't  don't", 5, 2);
	ms2.append("don't  don't", 5, 2);
	os2[9] = '!';
	ms2[9] = '!';
	std::cout << "os1 == \'" << os1 << "\', ms1 == \'" << ms1 << "\' after +="
	<< std::endl << "os2 == \'" << os2 << "\', ms2 == \'" << ms2 << "\' after append and change [9].\
in [3]: os2 == \'" << os2[3] << "\', ms2 == \'" << ms2[3] << std::endl << std::endl;

	//swap, compare, ==, !=
	std::cout << "test swap, compare, ==, != :" << std::endl << os1 << (os1 == os2 ? " | == | " : " | != | ")
	<< os2 << std::endl << ms1 << (ms1 == ms2 ? " | == | " : " | != | ") << ms2 << " before swap" << std::endl;

	os3 = os2;
	ms3 = ms2;
	os1.swap(os3);
	ms1.swap(ms3);

	std::cout << os1 << (os1 == os2 ? " | == | " : " | != | ") << os2 << std::endl << ms1
	<< (ms1 == ms2 ? " | == | " : " | != | ") << ms2 << " after swap" << std::endl;

	return 0;
}
