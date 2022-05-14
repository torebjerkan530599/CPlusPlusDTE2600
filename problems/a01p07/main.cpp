// Include needed standard library functions
#include <vector>
#include <algorithm>
#include <functional>

// The main function is the entry point for any program written in C++
std::vector<int> sortDesc(std::vector<int> const& p_data)
{
	auto data = std::vector<int>(std::begin(p_data), std::end(p_data));

	std::ranges::sort(data, std::ranges::greater());

	return data;
}
