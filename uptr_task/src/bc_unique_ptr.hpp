#ifndef BC_UNIQUE_PTR_HPP
#define BC_UNIQUE_PTR_HPP

#include <typeinfo>

namespace gl {
namespace cpp_basecamp {

template<class T>
struct del {
	void operator()(T *ptr) const { delete ptr; }
};

template<class T, class D = del<T>>
class unique_ptr {

	T *ptr = nullptr;
	D delet;

public:
	unique_ptr() = default;
	unique_ptr(T *tmp) : ptr(tmp) {}
	unique_ptr(unique_ptr && tmp) {
		ptr = tmp.get();
		tmp.ptr = nullptr;
	}
	unique_ptr &operator=(unique_ptr && tmp) {
		ptr = tmp.get();
		tmp.ptr = nullptr;
		return *this;
	}

	~unique_ptr() {
		delet(ptr);
		ptr = nullptr;
	}

	T *release() {
		T *tmp = ptr;
		ptr = nullptr;
		return tmp;
	}

	T &operator*() const {
		return *ptr;
	}

	T *operator->() const { return get(); }

	T *get() const { return ptr; }

	bool operator==(unique_ptr<T, D> const &rhs) const { return get() == rhs.get(); }

	template<class S, class V>
	bool operator==(unique_ptr<S, V> const &rhs) const { return false; }

};

} // namespace cxx_basecamp
} // namdespace gl

#endif // BC_UNIQUE_PTR_HPP
