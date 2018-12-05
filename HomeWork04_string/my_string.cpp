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
	if (start + count > s.length())
		count = s.length() - start;
	char *new_s = new char[size + count + 1];
	new_s[size + count] = 0;
	for (int i = 0; i < size; ++i)
	{
		new_s[i] = str[i];
	}
	for (int i = 0; i < count; ++i)
	{
		new_s[size + i] = s[i + start];
	}
	size += count;
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
	//memcpy
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
	for (int i = 0; i < s.length(); ++i)
	{
		o << s[i];
	}
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
	for (int i = 0; i <= size; ++i)
	{
		if (str[i] != s[i])
			return str[i] - s[i];
	}
	return 0;
}

void	My_string::resize(size_t n, char c)
{
	if (n == size)
		return ;
	char *s = new char[n + 1];
	s[n] = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i < size)
			s[i] = str[i];
		else
			s[i] = c;
	}
	delete [] str;
	str = s;
	size = n;
}

size_t	My_string::substr(const My_string &s) const
{
	size_t n = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (str[i] == s[0])
		{
			for (size_t j = 0; j < s.length(); ++j)
			{
				if (str[j + i] != s[j])
					break ;
				if (j + 1 == s.length())
					return i;
			}
		}
	}
	return -1;
}

size_t	My_string::substr(const char *s) const
{
	My_string st(s);
	return substr(st);
}

My_string & My_string::insert(size_t pos, const My_string &s)
{
	if (pos > size)
		throw std::out_of_range("out_of_range");
	char *st = new char[size + s.length() + 1];
	for (int i = 0; i < pos; ++i)
	{
		st[i] = str[i];
	}
	for (int i = 0; i < s.length(); ++i)
	{
		st[i + pos] = s[i];
	}
	for (int i = pos; i <= size; ++i)
	{
		st[i + s.length()] = str[i];
	}
	size += s.length();
	delete [] str;
	str = st;
	return *this;
}

My_string & My_string::insert(size_t pos, const char *s)
{
	My_string st(s);
	return insert(pos, st);
}

My_string & My_string::insert(size_t pos, const char c)
{
	if (pos > size)
		throw std::out_of_range("out_of_range");
	char *st = new char[size + 2];
	for (int i = 0; i < pos; ++i)
	{
		st[i] = str[i];
	}
	st[pos] = c;
	for (int i = pos; i <= size; ++i)
	{
		st[i + 1] = str[i];
	}
	size += 1;
	delete [] str;
	str = st;
	return *this;
}
