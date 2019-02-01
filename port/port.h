#ifndef PORT_H
#define PORT_H

#include <iostream>

class Port {
private:
	char* brand;
	char style[20]; // e.g. tawny, ruby, vintage
	int bottles;

public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port() { delete [] brand; }

	Port& operator= (const Port & p);
	Port& operator+= (int b); // adds b to bottles
	Port& operator-= (int b); // subtracts b from bottles, if possible

	int BottleCount() const { return bottles; }
	virtual void Show() const {
		std::cout << "Brand: " << brand << std::endl << "Kind: " << style << std::endl << "Bottles: " << bottles << std::endl;
	}
	friend std::ostream& operator<< (std::ostream& os, const Port& p);
};

std::ostream& operator<< (std::ostream& os, const Port& p);

/*
2)
Возможно потому что мы хотим их задать как inline (писать не обязательно)?! В таком случае их нужно определить там же где и объявили
(возможно я не правильно понял вопрос о "переопределении")

3)
operator=() и operator<<() могут быть вирутальными но это бы не имело смысла т.к. в дочернем классе будут
другие входящие параметры, что значит это не перегрузка той же функции а совсем другая.. Перегрузка функции
это когда название и входящие параметры одинаковые. Т. ч. в дочернем классе будет совсем другая функция (оператор)
и делать его виртуальным в этом классе нет смысла, из-за того что мы его не собираемся перегружать в дочернем.
*/

#endif
