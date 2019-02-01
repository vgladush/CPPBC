#include "stack.hpp"

class test
{
public:
	test operator=(test const &spec) {
		throw std::logic_error("special throw");
	}
};

int main() {
	Stack<int> k;
	Stack<std::string> y(6);
	Stack<test> u(3);

	try {
	k.pop();
	} catch (std::exception const & ex) {
		std::cerr << "error: " << ex.what() << std::endl;
	}
	try {
		k.push(23);
		k.push(23);
		std::cout << "stack<int> count == " << k.count() << std::endl;
		k.pop();
		std::cout << "stack<int> after pop == " << k.count() << std::endl;
		y.push("test");
		y.push("test");
		y.push("test");
		y.push("test");
		y.push("test");
		y.push("test");
		std::cout << "stack<string> count == " << y.count() << std::endl;
		y.pop();
		y.pop();
		std::cout << "stack<string> after double pop == " << y.count() << std::endl;
	} catch (...) {
		std::cerr << "we don't see the msg" << std::endl;
	}
	try {
		test tt;
		u.push(tt);
	} catch (std::exception const & ex) {
		std::cerr << "error: " << ex.what() << std::endl;
	}

	return 0;
}
