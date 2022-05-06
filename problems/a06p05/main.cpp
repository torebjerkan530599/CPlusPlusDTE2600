// Include needed standard library functions
#include <string>
#include <vector>

#include <iostream>
#include <iomanip>

#include <ranges>
#include <numeric>
#include <algorithm>
#include <span>


struct Item {
    int         id;
    std::string name;
    auto        operator<=>(Item const& other) const = default;
};

namespace sv = std::views;
namespace sr = std::ranges;

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    int  no_needles;
    auto items = std::vector<Item>();
    //  auto items   = std::vector<int>();
    auto needles = std::vector<int>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no items and no
        std::cin >> no_items >> no_needles;

        // read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.id >> in.name;
            items.push_back(in);
            });

        // read needles
        needles.clear();
        needles.reserve(no_needles);
        sr::for_each(sv::iota(0, no_needles), [&](auto const&) {
            int in;
            std::cin >> in;
            needles.push_back(in);
            });

        // <-- complete the code
        sr::sort(items);

        for(int const &needle : needles)
        {
            sr::binary_search(items, needle, std::ranges::less(), &Item::id)
                ? std::cout << "found" << std::endl
                : std::cout << "nop"<< std::endl;
        }
    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
