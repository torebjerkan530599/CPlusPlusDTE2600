// Include needed standard library functions (STL)
#include <algorithm>
#include <ranges>
#include <iostream>
#include "header.h"

// The <signature> function definition

void forEachOne(std::vector<int>& data) {

    int next = 0;
    auto       pred = [&next](auto& ele)
    {
        (next % 2 == 0) ? ele = next : ele = 42;
        next++;
    };

    std::for_each(data.begin(), data.end(), pred);
}

void forEachString(std::vector<std::string> const& data)
{
    auto pred = [](auto const& str)
    {
        std::cout << str << std::endl;
    };

    std::for_each(data.begin(), data.end(), pred);
}
