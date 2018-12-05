#include "my_string.h"

My_string::My_string(const char *s)
{
	str = 0;
	*this = s;
}

My_string::My_string(const My_string & s)
{
	str = 0;
	*this = s;
}

My_string::~My_string()
{
	delete [] str;
	size = 0;
}

My_string & My_string::append(const My_string & s, size_t start, size_t count)
{
	if (start > s.length())
		throw std::out_of_range("out_of_range");
	char *new_s = new char[size + count + 1];
	new_s[size + count] = 0;
	int i = 0, j = 0;
	for (; i < size; ++i)
	{
		new_s[i] = str[i];
	}
	for (; j < count && s[j + start]; ++j)
	{
		new_s[i + j] = s[j + start];
	}
	size += j;
	delete [] str;
	str = new_s;
	return *this;
}

My_string & My_string::append(const char * s, size_t start, size_t count)
{
	My_string st(s);
	return append(st, start, count);
}

My_string & My_string::append(const My_string & s)
{
	return append(s, 0, s.length());
}

My_string & My_string::append(const char * s)
{
	My_string st(s);
	return append(st, 0, st.length());
}

size_t	My_string::length() const
{
	return size;
}

void	My_string::clear()
{
	delete [] str;
	str = new char[1];
	str[0] = 0;
	size = 0;
}

My_string & My_string::operator = (const My_string & s)
{
	if (this == &s)
		return *this;
	delete [] str;
	size = s.length();
	str = new char[size + 1];
	str[size] = 0;
	for (int i = 0; i < size; ++i)
	{
		str[i] = s[i];
	}
	return *this;
}

My_string & My_string::operator = (const char *s)
{
	if (!s)
		throw std::out_of_range("out_of_range");
	delete [] str;

	//strdup(cstring): str = strdup(s);

	for (size = 0; s[size]; ++size); //strlen

	str = new char[size + 1];
	str[size] = 0;
	for (int i = 0; i < size; ++i)
	{
		str[i] = s[i];
	}
	return *this;
}

My_string & My_string::operator += (const My_string & s)
{
	return append(s);
}

My_string & My_string::operator += (const char *s)
{
	return append(s);
}

My_string My_string::operator + (const My_string & s)
{
	My_string st(*this);
	return st.append(s);
}

My_string My_string::operator + (const char *s)
{
	My_string st(*this);
	return st.append(s);
}

char	*My_string::c_str() const
{
	char *s = new char[size + 1];
	s[size] = 0;
	for (int i = 0; i < size; ++i)
	{
		s[i] = str[i];
	}
	return s;
}

char	My_string::operator [] (int i) const
{
	return str[i];
}

char	& My_string::operator [] (int i)
{
	return str[i];
}

std::istream &operator>>(std::istream &is, My_string & s)
{
	char st[1000]; //wrong
	is >> st;
	s = st;
	return is;
}

std::ostream &operator<<(std::ostream &o, const My_string & s)
{
	o << s.c_str();
	return o;
}

void	My_string::swap(My_string & s)
{
	My_string st(*this);
	*this = s;
	s = st;
}

bool	My_string::operator == (const My_string & s) const
{
	return !compare(s);
}

bool	My_string::operator != (const My_string & s) const
{
	return !(*this == s);
}

int		My_string::compare(const My_string &s) const
{
	for (int i = 0; i < size; ++i)
	{
		if (str[i] != s[i])
			return str[i] - s[i];
	}
	if (size != s.length())
		return (size < s.length() ? -s[size] : str[s.length()]);
	return 0;
}
