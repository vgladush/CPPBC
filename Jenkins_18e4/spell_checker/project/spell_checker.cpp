#include "spell_checker.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using vec_str = std::vector<std::string>; // == typedef std::vector<std::string> vec_str - alias
using set_str = std::set<std::string>;
using uns_str = std::unordered_set<std::string>;

template<class Container>
class SpellChecker_temp : public SpellChecker_Impl
{
	Container diction;

public:

	void load(const std::string& dictionary);

	bool check(const std::string& word) const;

	void add(const std::string& word);

	size_t size(void) const;

};

template<class Container>
void SpellChecker_temp<Container>::load(const std::string& dictionary) {
	std::ifstream fl(dictionary);
	if (!fl.is_open())
		throw SpellChecker_InvalidDictFile();
	std::string s;
	while (fl >> s)
		diction.insert(diction.end(), s); // or -- add(s); -- if Notes from README.md are violated
}

template<class Container>
bool SpellChecker_temp<Container>::check(const std::string& word) const {
	return diction.find(word) != diction.end();
}

template<>
bool SpellChecker_temp<vec_str>::check(const std::string& word) const {
	return std::binary_search(diction.begin(), diction.end(), word);
}

template<class Container>
void SpellChecker_temp<Container>::add(const std::string& word) {
	diction.insert(diction.end(), word);
}

template<>
void SpellChecker_temp<vec_str>::add(const std::string& word) {
	if (!check(word))
		diction.insert(std::upper_bound(diction.begin(), diction.end(), word), word);
}

template<class Container>
size_t SpellChecker_temp<Container>::size(void) const { return diction.size(); }


SpellChecker::SpellChecker (const ContainerType type)
{
	if (type == ContainerType::Set)
		impl_ = std::make_unique<SpellChecker_temp<set_str>>();
	else if (type == ContainerType::Unordered_Set)
		impl_ = std::make_unique<SpellChecker_temp<uns_str>>();
	else
		impl_ = std::make_unique<SpellChecker_temp<vec_str>>();
}

void SpellChecker::load(const std::string& dictionary)
{
	return impl_->load(dictionary);
} 

bool SpellChecker::check(const std::string& word) const
{
	std::string low;
	for (int i = 0; i < word.size(); ++i) {
		low += tolower(word[i]);
	}
	return impl_->check(low);
}

void SpellChecker::add(const std::string& word)
{
	impl_->add(word);
}

size_t SpellChecker::size(void) const
{
	return impl_->size();
}

bool SpellChecker::is_valid(const std::string& word)
{
	if (word.length() > 45 || word[0] == '\'')
		return false;

	for(int i = 0; i < word.length(); ++i)
	{
		if (!std::isalpha(word[i]) && word[i] != '\'')
			return false;
	}

	return true;
}
