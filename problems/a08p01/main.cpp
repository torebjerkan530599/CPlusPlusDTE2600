// Include needed standard library functions
#include <iostream>
#include <vector>

#include <ranges>
#include <algorithm>
#include <string>

namespace sr = std::ranges;
namespace sv = std::views;


// Global constant initialized integer variable
auto const constinit y = 10;


// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int no_tests;
    std::cin >> no_tests;

    auto items = std::vector<int>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read items
        int no_items;
        std::cin >> no_items;

        items.clear();
        //items.reserve(no_items);

        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            int in;
            std::cin >> in ;
            items.push_back(in);
        });

        // For each input compute: f := x + y and write to standard out
        for (auto i = items.begin(); i < items.end(); ++i) {
            auto const x = *i;
            auto const f = x + y;
            std::cout << std::to_string(f) << ' ';
        }
        std::cout << "\n";
    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
