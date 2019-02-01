#include "move.h"

Move::Move(double a, double b) : x(a), y(b) { }

void Move::showmove() const {
	std::cout << "x = " << x << ", y = " << y << std::endl;
}

Move Move::add(const Move & m) const {
	Move mv(x + m.x, y + m.y);
	return mv;
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}
// 	x = a;
// 	y = b;
// }
