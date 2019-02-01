#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template<class T>
class Stack
{

	T *top = nullptr;
	size_t size = 0;
	size_t used = 0;

	void	copy_data(T* in, T *from, size_t cn) {
		for (size_t i = 0; i < cn; ++i) {
			in[i] = from[i];
		}
	}

public:

	Stack(size_t sz = 1) {
		top = new T[sz];
		size = sz;
	}

	Stack(const Stack<T> & cpy) {
		top = new T[cpy.size];
		size = cpy.size;
		try {
			copy_data(top, cpy.top, cpy.used);
			used = cpy.used;
		} catch (...) {
			throw std::logic_error("cant copy the stack");
		}
	}

	Stack<T> &operator=(const Stack<T> & cpy) {
		T * tmp = new T[cpy.size];
		try {
			copy_data(tmp, cpy.top, cpy.used);
			used = cpy.used;
			delete [] top;
			top = tmp;
			size = cpy.size;
		} catch (...) {
			delete [] tmp;
			throw std::logic_error("cant assign the stack");
		}
	}

	~Stack() {
		delete [] top;
		top = nullptr;
		size = 0;
		used = 0;
	}

	size_t	count() const { return used; }

	void	push(const T & data) {
		if (used == size) {
			size_t t = (size ? size * 2 : 1);
			T * tmp = new T[t];
			try {
				copy_data(tmp, top, used);
				delete [] top;
				top = tmp;
				size = t;
			} catch (...) {
				delete [] tmp;
				throw std::logic_error("cant expand the stack");
			}
		}
		try {
			top[used] = data;
			++used;
		} catch (...) {
			throw std::logic_error("cant expand the stack");
		}
	}

	T		pop() {
		if (!used)
			throw std::logic_error("stack is empty");
		return top[--used];
	}

};

#endif
