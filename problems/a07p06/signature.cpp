#include "header.h"
#include <algorithm>
#include <iostream>


void reverse(std::forward_list<int> const& in, std::forward_list<int>& out)
{
	out.assign(in.begin(), in.end());
	out.reverse();

	for (auto o : out)
		std::cout << o << std::endl;
	//for(auto i = std::begin(in); i != std::end(in); i++)
	//std::ranges::reverse_copy(in, out.begin());
}
void pyramidCopy(std::forward_list<int> const& in, std::list<int>& out)
{
	size_t new_size = std::ranges::distance(in.begin(),in.end());

	std::ranges::copy(in, std::front_inserter(out));
	out.resize(new_size);
	std::ranges::copy(in, std::back_inserter(out));

	
}
