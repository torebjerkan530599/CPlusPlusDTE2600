// Include needed standard library functions (STL)
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "header.h"
#include <iostream>


void transformOne(std::forward_list<int> const& list, std::vector<int>& output)
{
    auto pred = [](auto const& a)
    {
        return a;
    };
    std::transform(list.begin(), list.end(), std::back_inserter(output), pred);
}

void transformTwo(std::forward_list<std::string> const& strings,
    std::vector<Meta>& meta)
{
    auto const score = [](auto const& str) -> size_t
    {
        return std::count(str.begin(), str.end(), 'a');
    };
    auto const pred = [score](auto const& str) -> Meta
    {    
        return Meta{str.length(), score(str)};
    };

    std::transform(strings.begin(), strings.end(), std::back_inserter(meta),
        pred);
}

std::vector<std::string>
transformThree(std::forward_list<std::string> const& first_names,
    std::forward_list<std::string> const& last_names,
    std::string const& glue)
{
    auto const pred = [=](auto const& fn, auto const& ln)
    {
        return fn + glue + ln;
    };

    std::vector<std::string> full_names;
    std::transform(first_names.begin(), first_names.end(), last_names.begin(),
        std::back_inserter(full_names), pred);
    return full_names;
}

int transformReduceOne(std::forward_list<int> const& list1,
    std::forward_list<int> const& list2)
{
    auto const pred_reduce = [](auto const& init, auto const& e) -> int
    {
        return init + e;
    };

    auto const pred_trans = [](auto const& e1, auto const& e2) -> int
    {
        return pow(e1,2) + abs(e2);
    };

    return std::transform_reduce(list1.begin(), list1.end(), list2.begin(), 0,
        pred_reduce, pred_trans);

}

std::string transformReduceTwo(std::forward_list<int> const& list1,
    std::forward_list<int> const& list2)
{
    // auto const inner = ... <-- complete the code: use std::transform_reduce
    auto const pred_reduce = [](auto const& init, auto const& e) -> int
    {
       return init + e;

    };

    auto const pred_trans = [](auto const& e1, auto const& e2) -> int
    {
        return e1 * e2;
    };

    int sum = std::transform_reduce(list1.begin(), list1.end(), list2.begin(), 0,
        pred_reduce, pred_trans);

    return std::to_string(sum);
}
