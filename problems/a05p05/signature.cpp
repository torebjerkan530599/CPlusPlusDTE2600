// Include needed standard library functions (STL)
#include "header.h"
#include <cmath>

// The <signature> function definition
bool Less::operator()(int a, int b) const
{
	return std::less<int>()(a, b);
}

bool Greater::operator()(int a, int b) const
{
	return std::greater<int>()(a, b);
}

bool PowLessEq::operator()(int a, int b) const
{
	return std::less_equal<int>()(std::pow(a,m_exp), std::pow(b, m_exp));
}

size_t CountSmallAs::operator()(const std::string& str) const
{
	size_t count = 0;

	for (auto &c : str)
	{
		if(c == 'a')
			count++;
	}

	return count;
}
