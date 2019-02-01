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
	<< "otiginal string are: os1, os2, os3; my string are: ms1, ms2, ms3" << std::endl
	<< "os1 \'" << os1 << "\' == ms1 \'" << ms1 << "\' and size "
	<< os1.length() << " == " << ms1.length() << std::endl << "os2 \'"
	<< os2 << "\' != ms2 \'" << ms2 << "\', but size " << ms2.length()
	<< " == " << ms2.length() << std::endl << std::endl;

	// copy constructor, =
	std::string os3(os2);
	My_string ms3(ms2);
	os1 = os2;
	ms1 = ms2;
	std::cout << "test copy constructor, = :" << std::endl
	<< "and now os1 == os3 \'" << os1 << "\' == \'" << os3 << "\' size "
	<< os1.length() << " == " << os3.length() << std::endl << "ms1 == ms3 \'"
	<< ms1 << "\' == \'" << ms3 << "\' size " << ms1.length() << " == "
	<< ms3.length() << std::endl << std::endl;

	//clear, >> , append, +=, +
	std::cout << "test clear, >>, append, +=, + :" << std::endl << "please enter two words for \
testing istream: first to original, second to my_string" << std::endl;

	std::cin >> os1 >> ms1;

	std::cout << "result:" << std::endl << "os1 = " << os1 << ", size " << os1.length()
	<< std::endl << "ms1 = " << ms1 << ", size = " << ms1.length() << std::endl;
	os1.clear();
	ms1.clear();
	std::cout << "os1 \'" << os1 << "\' and ms1 \'" << ms1 << "\' are empty size "
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
	<< std::endl << "os2 == \'" << os2 << "\', ms2 == \'" << ms2 << "\' after append and change [9]. \
in [3]: os2 == \'" << os2[3] << "\', ms2 == \'" << ms2[3] << "\'" <<  std::endl << std::endl;

	//swap, compare, ==, !=
	std::cout << "test swap, compare, ==, != :" << std::endl << "before swap:" << std::endl
	<< os1 << (os1 == os2 ? " | == | " : " | != | ") << os2 << std::endl << ms1
	<< (ms1 == ms2 ? " | == | " : " | != | ") << ms2 << std::endl;

	os3 = os2;
	ms3 = ms2;
	os1.swap(os3);
	ms1.swap(ms3);

	std::cout << "after swap:" << std::endl << os1 << (os1 == os2 ? " | == | " : " | != | ")
	<< os2 << std::endl << ms1 << (ms1 == ms2 ? " | == | " : " | != | ") << ms2 << std::endl;

	//resize, substr, insert
	std::cout << std::endl << "last test: resize, substr and insert" << std::endl;
	os1.resize(20);
	os1.resize(15, 42);
	os1.resize(21, '!');
	ms1.resize(20);
	ms1.resize(15, 42);
	ms1.resize(21, '!');

	int k = os1.find("!!!");
	int l = ms1.substr("!!!");
	int h = os1.find("mine");
	int p = ms1.substr("orig");

	std::cout << "os1 " << os1 << " and ms1 " << ms1 << " after resize." << std::endl
	<< "subst (find original) found " << k << " == " << l << " not found " << h << " == "
	<< p << std::endl;

	os1 = "end test";
	ms1 = "end test";

	os1.insert(4, "of ");
	ms1.insert(4, "of ");
	os1.insert(11, 1, 's');
	ms1.insert(11, 's');

	std::cout << "insert str and char: " << std::endl << os1 << std::endl << ms1 << std::endl << std::endl;

	return 0;
}
