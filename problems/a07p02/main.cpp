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
};

namespace sv = std::views;
namespace sr = std::ranges;


// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int no_tests;
    std::cin >> no_tests;

    int         no_items;
    std::string name;
    auto items = std::vector<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no items and no
        std::cin >> no_items;

        // read items
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.id >> in.name;
            items.push_back(in);
            });

        // Read some name
        std::cin >> name;

        auto pred = [&name](const std::string other_name) {return name == other_name;};

        // <-- complete the code
        sr::stable_partition(items, pred, &Item::name);

        for (auto& item : items)
            std::cout << item.id << " " << item.name << std::endl;
 
    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
