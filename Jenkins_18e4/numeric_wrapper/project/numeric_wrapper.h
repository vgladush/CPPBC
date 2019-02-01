#pragma once

template <class T>
class SafeNumeric
{
  private:
	T v_;

  public:
	SafeNumeric() noexcept;
	explicit SafeNumeric(const char *value);
	SafeNumeric(const T &) noexcept;

	SafeNumeric<T> &operator-();

	T &get() { return v_; }
	T get() const { return v_; }
};

template <class T>
SafeNumeric<T> operator/(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs);

template <class T>
SafeNumeric<T> operator%(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs);
template <class T>
SafeNumeric<T> operator+(const SafeNumeric<T> &lhs, const SafeNumeric<T> &);
template <class T>
SafeNumeric<T> operator-(const SafeNumeric<T> &lhs, const SafeNumeric<T> &);
template <class T>
SafeNumeric<T> operator*(const SafeNumeric<T> &lhs, const SafeNumeric<T> &);

template <class T>
bool operator<(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs);
template <class T>
bool operator>(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs);
template <class T>
bool operator!=(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs);
template <class T>
bool operator==(const SafeNumeric<T> &lhs, const SafeNumeric<T> &rhs);
