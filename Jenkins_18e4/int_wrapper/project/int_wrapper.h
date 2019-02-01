#pragma once

class TInt {
private:
	int v_;
public:
	TInt();
	TInt(const char* value);
	TInt(int);

	TInt& operator-();
	int getV() const;

	friend TInt operator/ (const TInt& lhs, const TInt&);
	friend TInt operator% (const TInt& lhs, const TInt&);
	friend TInt operator+ (const TInt& lhs, const TInt& );
	friend TInt operator- (const TInt& lhs, const TInt& );
	friend TInt operator* (const TInt& lhs, const TInt&);

	friend bool operator<(const TInt& lhs, const TInt& rhs);
	friend bool operator>(const TInt& lhs, const TInt& rhs);
	friend bool operator!=(const TInt& lhs, const TInt& rhs);
	friend bool operator==(const TInt& lhs, const TInt& rhs);
};
