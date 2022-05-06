#include "header.h"
#include <iostream>
#include <algorithm>

CharArray toCharArray(std::string const& name)
{
	CharArray arr{};

	std::fill(arr.begin(), arr.end(), '_');

	if (name.length() <= arr.size())
	{ 
		std::copy(name.begin(), name.end(), arr.begin());
		//std::fill(arr.begin() + name.length(), arr.end(), '_');
	}
	else
		std::copy(name.begin(), name.begin() + arr.size(), arr.begin());
	
	for (auto& i : arr)
		std::cout << i << std::endl;

	return arr;
}


//using CharArray = std::array<char, 10ul>;
//using StringVector = std::vector<CharArray>;
void appendReversed(StringVector& vec, CharArray const& str)
{
	CharArray reversed_str{};
	std::ranges::reverse_copy(str, reversed_str.begin());
	vec.push_back(reversed_str);
}

void stableSort(std::vector<std::pair<int, std::string>>& vec)
{
	std::ranges::stable_sort(vec, [](const auto& p1, const auto& p2) {return p1.first < p2.first; });
	//static_assert(false, "Complete the code");
}
