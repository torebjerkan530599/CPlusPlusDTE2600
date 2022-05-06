#include "header.h"
#include <cmath>

// The <signature> function definition(s)
namespace dte2600 {

	string::string()
	{
		
	}

	void string::appendChar(char c) {
		m_data.emplace_back(c);
	}
	size_t string::size() const
	{
		return  m_data.size();
	}
	string::CharVec const& string::data() const
	{
		return m_data;
	}

	std::optional<int> string::indexOfFirst(char c) const
	{
		return detail::findIndexOfFirst(m_data, c);
	}
} // namespace dte2600

std::string toStdString(dte2600::string const& str)
{
	std::string s_string;

	dte2600::string::CharVec v = str.data();

	for (char c : v)
	{
		s_string += c;
	}

	return s_string;
}
dte2600::string toDte2600String(std::string const& str)
{

	//char vector to string c++
	//std::vector<char> input({ 'a', 'b', 'c' });
	//std::string s(input.begin(), input.end());

	//vector to char array c++
	//std::vector<int> vec{ 1, 2, 3 };
	//const int* = vec.data();


	dte2600::string s;

	for (char const& c : str)
	{
		s.appendChar(c);
	}

	dte2600::string::CharVec my_data = s.data();

	return s;

}

int computeScoreFromString(dte2600::string const& str, char a, char b, char c)
{

	std::optional<int> index_a = str.indexOfFirst(a);
	std::optional<int> index_b = str.indexOfFirst(b);
	std::optional<int> index_c = str.indexOfFirst(c);


	if (!index_a.has_value() || index_a == std::nullopt) //kan forkortes til if (!index_a)
	{
		*index_a = -1;
		// index_a.value() = -1 ; er dette bedre?
	} 
	else
	{
		*index_a = abs(*index_a);
	}

	if (!index_b.has_value() || index_b == std::nullopt)
	{
		*index_b = -1;
	}
	else
	{
		*index_b = std::pow(*index_b, 2);
	}

	if (!index_c.has_value() || index_c == std::nullopt)
	{
		*index_c = -1;
	}
	else
	{
		*index_c = std::pow(*index_c, 3);
	}

	//int score_a = abs(*index_a) + std::pow(*index_b, 2) + std::pow(*index_c, 3); //score function x = |a| + b^2 + c^3
	int score_b = *index_a + *index_b + *index_c;
	return score_b;
}
