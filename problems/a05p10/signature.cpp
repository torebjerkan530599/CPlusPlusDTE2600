// Include needed standard library functions (STL)
#include <algorithm>
#include <ranges>
#include "header.h"


void sortMyInts(std::vector<int>& ints)
{
    // <-- complete the code using std::ranges::sort
    std::ranges::sort(ints);
}

std::pair<bool, bool> amISorted(std::vector<Person> const& people) {

    auto const pred1 = [](auto const& p1, auto const& p2)
    {
        return p1.name < p2.name;
    };

    auto const pred2 = [](auto const& p1, auto const& p2)
    {
        return p1.age < p2.age;
    };

    auto const sorted_by_name = std::ranges::is_sorted(people, pred1);
    auto const sorted_by_age = std::ranges::is_sorted(people, pred2);
    return { sorted_by_name, sorted_by_age };
}

std::vector<int> generateOddNumbers(int low, int high)
{
    using namespace std::views;

    std::vector<int> ints;

    auto const filter_pred = [](int e)
    {
        return e %2 != 0;
    };

    
    for (int e : iota(low + 1, high + 1) | filter(filter_pred))
        ints.push_back(e);

    return ints;
}

std::vector<int> generateOddNumbersReversed(int low, int high)
{
    using namespace std::views;

    std::vector<int> evens;

    auto const filter_pred = [](int e)
    {
        return e % 2 == 0;
    };

    auto const trans_pred = [](auto const& e)
    {
        return e;
    };

        std::ranges::transform(iota(low, high) | filter(filter_pred) | reverse,
            std::back_inserter(evens), trans_pred);
    return evens;
}
