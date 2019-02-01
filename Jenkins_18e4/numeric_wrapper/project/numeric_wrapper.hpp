
#include "numeric_wrapper.h"
#include <iomanip>
#include <limits>
#include <typeinfo>
#include <cmath>
#include <iostream>
#include <cstring>

class SafeNumericBaseExc
{
};

class SafeNumeric_Overflow : public SafeNumericBaseExc
{
};
class SafeNumeric_DivisionByZero : public SafeNumericBaseExc
{
};
class SafeNumeric_InvalidInput : public SafeNumericBaseExc
{
};
class SafeNumeric_InvalidOperation : public SafeNumericBaseExc
{
};

template <typename T>
SafeNumeric<T>::SafeNumeric() noexcept : v_(0) {}

template <typename T>
SafeNumeric<T>::SafeNumeric(const char *value) {
	if (!value || !value[0])
		v_ = 0;
	else {
		size_t ad = 0;
		long double test = std::stold(value, &ad);
		if (value[ad])
			throw SafeNumeric_InvalidInput();
		if (std::numeric_limits<T>::max() < test || test < std::numeric_limits<T>::min())
			throw SafeNumeric_Overflow();
		v_ = test;
	}
}

template <typename T>
SafeNumeric<T>::SafeNumeric(const T &val) noexcept {
	v_ = val;
}

template <typename T>
SafeNumeric<T> &SafeNumeric<T>::operator-() {
	if (v_ > 0 && (-v_) > 0)
		throw SafeNumeric_InvalidOperation();
	v_ = -v_;
	return *this;
}

template <class T>
SafeNumeric<T> operator/(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	if (!rhs.get())
		throw SafeNumeric_DivisionByZero();
	SafeNumeric<T> res(lhs.get() / rhs.get());
	return res;
}

template <class T>
SafeNumeric<T> operator%(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	if (typeid(T) == typeid(double) || typeid(T) == typeid(float))
		throw SafeNumeric_InvalidOperation();
	if (rhs.get() < 0)
		throw SafeNumeric_InvalidOperation();
	SafeNumeric<T> res(static_cast<long long>(lhs.get()) % static_cast<long long>(rhs.get()));
	return res;
}

template <class T>
SafeNumeric<T> operator+(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	//ver 1
	// long double t = static_cast<long double>(lhs.get() + rhs.get());
	// if (t > std::numeric_limits<T>::max() || t < std::numeric_limits<T>::min())
	// 	throw SafeNumeric_Overflow();

	//ver 2
	// T test = lhs.get() + rhs.get();
	// if ((lhs.get() > 0 && rhs.get() > 0 && test < lhs.get()) || (lhs.get() < 0 && rhs.get() < 0 && test > lhs.get()))
	// 	throw SafeNumeric_Overflow();

	//ver 3 special for double
	if (std::numeric_limits<T>::max() == lhs.get())
		throw SafeNumeric_Overflow();

	SafeNumeric<T> res(lhs.get() + rhs.get());
	return res;
}

template <class T>
SafeNumeric<T> operator-(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	long double t = static_cast<long double>(lhs.get()) - rhs.get();
	if (t > std::numeric_limits<T>::max() || t < std::numeric_limits<T>::min())
		throw SafeNumeric_Overflow();

	SafeNumeric<T> res(lhs.get() - rhs.get());
	return res;
}

template <class T>
SafeNumeric<T> operator*(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	long double t = static_cast<long double>(lhs.get()) * rhs.get();
	if (t > std::numeric_limits<T>::max() || t < std::numeric_limits<T>::min())
		throw SafeNumeric_Overflow();

	SafeNumeric<T> res(lhs.get() * rhs.get());
	return res;
}


template <class T>
bool operator<(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	return (lhs.get() < rhs.get() ? true : false);
}

template <class T>
bool operator>(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	return (lhs.get() > rhs.get() ? true : false);
}

template <class T>
bool operator!=(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	return (lhs.get() != rhs.get() ? true : false);
}

template <class T>
bool operator==(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs) {
	return (lhs.get() == rhs.get() ? true : false);
}


// TODO: implement missed SafeNumeric<> members and free template functions here
