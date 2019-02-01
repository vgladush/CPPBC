# Excercises on STL

Implement functions below:

1. "remove_blanks": removes consequent duplicate whitespaces, leading or trailing ones
```
std::string remove_blanks (const std::string& s);
```

2. "find_keys_by_value": returns all pairs keys that have value equal to given one
```
using MapSI = std::map<std::string, int>;
std::vector<std::string> find_keys_by_value(const MapSI& m, int value);
```

3. "remove_if_less": removes from vector elements that less than n
```
void remove_if_less(std::vector<int>& v, int n);
```

4. "remove_duplicates": return vector without consequent duplicated elements
Notes: v may have elements either in sorted or unsorted  order
```
std::vector<int> remove_duplicates(const std::vector<int>& v);
```

5. "remove_duplicates_not_consequent": removes any duplicates (not necessary consequent) in given container
Notes: container may have elements in any order
```
void remove_duplicates_not_consequent(std::vector<int>& v);
```

6. "insert_if_missed": inserts pair to map only if given key does not exist in map
```
using IpType = std::string;
using DomainType = std::string;
using DnsElem = std::pair<IpType, DomainType>;
using DnsMap = std::map<IpType, DomainType>;
void insert_if_missed(DnsMap& dict, const DnsElem& e);
```

The list of files which are allowed to be modified:
* project/stl_task.cpp
