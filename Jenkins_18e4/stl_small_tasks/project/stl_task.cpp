#include "stl_task.h"
#include <unordered_set>
#include <algorithm>
#include <iostream>

void remove_elem_by_value(Map& m, int value)
{
	for (auto it = m.begin(); it != m.end();)
	{
		if (it->second == value)
			it = m.erase(it);
		else
			++it;
	}
}

bool	if_spece(char l, char r) {
	return l == r && std::isspace(l);
}

std::string remove_blanks(const std::string& s)
{
	std::string str(s);
	str.erase(unique(str.begin(), str.end(), if_spece), str.end());
	auto s_start = str.find_first_not_of(" \t\n");
	auto s_end = str.find_last_not_of(" \t\n");
	if (s_start >= s_end)
		return "";
	auto len = s_end - s_start + 1;
	return str.substr(s_start, len);
}

std::vector<std::string> find_keys_by_value(const MapSI& m, int value)
{
	std::vector<std::string> vs;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		if (it->second == value)
			vs.push_back(it->first);
	}
	return vs;
}

void remove_if_less(std::vector<int>& v, int n)
{
	for (auto it = v.begin(); it != v.end();)
	{
		if (*it < n)
			it = v.erase(it);
		else
			++it;
	}
}

std::vector<int> remove_duplicates(const std::vector<int>& v)
{
	std::vector<int> s = (v);
	s.erase(unique(s.begin(), s.end()), s.end());
	std::vector<int> vec(s.begin(), s.end());
	return vec;
}

void remove_duplicates_not_consequent(std::vector<int> &v)
{
	std::vector<int> s = (v);

	std::sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	for (auto it = v.begin(); it < v.end();)
	{
		if (std::binary_search(s.begin(), s.end(), *it)) {
			s.erase(std::remove(s.begin(), s.end(), *it), s.end());
			++it;
		} else
			it = v.erase(it);
	}
}

void insert_if_missed(DnsMap &dict, const DnsElem &e)
{
	if (dict.find(e.first) == dict.end())
		dict.insert(e);
}
