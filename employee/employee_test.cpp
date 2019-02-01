#include "employee.h"
#include <iostream>

int main() {
	Employee employee("Rick", "Deckard", "Blade runner");
	std::cout << employee << std::endl;
	employee.showAll();

	Manager manager("Harry", "Bryant", "Captain", 5);
	std::cout << manager << std::endl;
	manager.showAll();

	Fink fink("Leon", "Kowalski", "Cargo loader", "Roy Batty");
	std::cout << fink << std::endl;
	fink.showAll();

	HighFink highFink(manager, "Eduardo Gaff");
	highFink.showAll();
	std::cout << "Press a key for next phase:" << std::endl;
	std::cin.get();

	HighFink highFink2;
	highFink2.setAll();

	std::cout << "Using an AbstractEmployee * pointer:" << std::endl;
	AbstractEmployee* tri[4] = { &employee, &fink, &highFink, &highFink2};
	for (auto i = 0; i < 4; i++) {
		tri[i]->showAll();
	}
	return 0;
}
