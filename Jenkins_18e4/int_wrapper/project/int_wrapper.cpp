#include "int_wrapper.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

class TInt_Overflow
{
};

class TInt_DivisionByZero
{
};

TInt::TInt() : v_(0) {}

TInt::TInt(const char* value)
{
	if (!value)
		throw TInt_Overflow();

	for (size_t i = (value[0] == '-' ? 1 : 0); i < strlen(value); ++i)
	{
		if (!isdigit(value[i]))
			throw std::exception();
	}
	long long s = atol(value);
	if (s > 2147483647 || s < -2147483648)
		throw TInt_Overflow();
	v_ = s;
}

TInt::TInt(int v) : v_(v) {}

int		TInt::getV() const
{
	return v_;
}

TInt& TInt::operator-()
{
	long long u = v_;
	u = -u;
	if (u > 2147483647)
		throw TInt_Overflow();
	v_ = u;
	return *this;
}

TInt operator/ (const TInt& lhs, const TInt& rhs)
{
	if (!rhs.v_)
		throw TInt_DivisionByZero();
	TInt tn(lhs.v_ / rhs.v_);
	return tn;
}

TInt operator% (const TInt& lhs, const TInt& rhs)
{
	TInt tn(lhs.v_ % rhs.v_);
	return tn;
}

TInt operator+ (const TInt& lhs, const TInt& rhs)
{
	long long i = static_cast<long long>(lhs.v_) + rhs.v_;
	if (i > 2147483647 || i < -2147483648)
		throw TInt_Overflow();
	TInt tn(i);
	return tn;
}

TInt operator- (const TInt& lhs, const TInt& rhs)
{
	long long i = static_cast<long long>(lhs.v_) - rhs.v_;
	if (i > 2147483647 || i < -2147483648)
		throw TInt_Overflow();
	TInt tn(i);
	return tn;
}

TInt operator* (const TInt& lhs, const TInt& rhs)
{
	long long i = static_cast<long long>(lhs.v_) * rhs.v_;
	if (i > 2147483647 || i < -2147483648)
		throw TInt_Overflow();
	TInt tn(i);
	return tn;
}

bool operator<(const TInt& lhs, const TInt& rhs)
{
	return lhs.v_ < rhs.v_;
}

bool operator>(const TInt& lhs, const TInt& rhs)
{
	return lhs.v_ > rhs.v_;
}

bool operator!=(const TInt& lhs, const TInt& rhs)
{
	return lhs.v_ != rhs.v_;
}

bool operator==(const TInt& lhs, const TInt& rhs)
{
	return lhs.v_ == rhs.v_;
}
