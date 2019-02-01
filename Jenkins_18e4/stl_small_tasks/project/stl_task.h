#pragma once
#include <vector>
#include <map>
#include <string>
#include <array>
#include <utility>

using Map = std::map<int, int>;
void remove_elem_by_value(Map &m, int value);

// removes consequent duplicate whitespaces,
// leading or trailing ones
std::string remove_blanks(const std::string &s);

using MapSI = std::map<std::string, int>;
std::vector<std::string> find_keys_by_value(const MapSI &m, int value);

// removes from vector elements that less than n
void remove_if_less(std::vector<int> &v, int n);

// v may have elements either in sorted or unsorted  order
// eliminates only consequent duplicates
std::vector<int> remove_duplicates(const std::vector<int> &v);

// v may have elements in any order
// removes all duplicates (either consequent or not consequent)
void remove_duplicates_not_consequent(std::vector<int> &v);

using IpType = std::string;
using DomainType = std::string;
using DnsElem = std::pair<IpType, DomainType>;
using DnsMap = std::map<IpType, DomainType>;

void insert_if_missed(DnsMap &dict, const DnsElem &e);
