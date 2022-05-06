// Include needed standard library functions
#include <string>
#include <vector>

#include <iostream>
#include <iomanip>

#include <ranges>
#include <numeric>
#include <algorithm>
#include <span>


struct Person {
    std::string name;
    int year_of_birth;
};

namespace sv = std::views;
namespace rng = std::ranges;

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    int  current_year;
    auto items = std::vector<Person>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read the current year
        std::cin >> current_year;

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        rng::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });

        // <-- complete the code

        //auto const comp_order = [](auto const& a, auto const& b) {
        //    if (a == b)
        //        return std::weak_ordering::equivalent;
        //    else if (a < b)
        //        return std::weak_ordering::less;
        //    else
        //        return std::weak_ordering::greater;
        //};

        //auto const pred = [&current_year](const Person& p1, const Person& p2)
        //{
        //    if(p1.year_of_birth == p1.year_of_birth)
        //        return std::weak_ordering::equivalent;
        //    else if ((current_year - p1.year_of_birth) < (current_year - p2.year_of_birth))
        //        return std::weak_ordering::less;
        //    else
        //        return std::weak_ordering::greater;
        //};

        const auto [min, max] = rng::minmax_element(items, std::ranges::greater(), &Person::year_of_birth);

        if (min != items.end() && max != items.end())
        {
            const auto pos_min = rng::distance(items.begin(), min);
            const auto pos_max = rng::distance(items.begin(), max);

            const auto age_min = current_year - items.at(pos_min).year_of_birth;
            const auto age_max = current_year - items.at(pos_max).year_of_birth;;

            std::cout << min->name << " " << age_min << std::endl;
            std::cout << max->name << " " << age_max << std::endl;
        }
        else
            std::cout << "nop" << std::endl;
    }


    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
