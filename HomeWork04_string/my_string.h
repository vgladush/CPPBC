#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream> //size_t, exception, ostream etc.

class My_string
{
public:
	My_string(const char *s = "");
	My_string(const My_string & s);
	My_string &append(const My_string & s, size_t start, size_t count);
	My_string &append(const char * s, size_t start, size_t count);
	My_string &append(const My_string & s);
	My_string &append(const char * s);
	~My_string();
	void	clear();
	void	swap(My_string & s);
	char	*c_str() const;
	size_t	length() const;
	int		compare(const My_string & s) const;

	char	operator[](int i) const;
	char	& operator[](int i);
	My_string & operator = (const My_string & s);
	My_string & operator = (const char *s);
	My_string & operator += (const My_string & s);
	My_string & operator += (const char *s);
	My_string operator + (const My_string & s);
	My_string operator + (const char *s);
	bool operator == (const My_string & s) const;
	bool operator != (const My_string & s) const;
	
private:
	char	*str;
	size_t	size;
};

std::istream &operator>>(std::istream &is, My_string & s);
std::ostream &operator<<(std::ostream &o, const My_string & s);

#endif
