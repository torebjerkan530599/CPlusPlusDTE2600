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


/* Sub-task 1 */
void runSubTask01()
{
    int no_tests;
    std::cin >> no_tests;

    int no_items;
    int no_sub;

    std::vector<Item> items;
    std::vector<int>  sub;
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Given the input string
        std::cin >> no_items >> no_sub;

        // read items
        items.clear();
        items.reserve(no_items);
        std::ranges::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.id >> in.name;
            items.push_back(in);
            });

        // read sub
        sub.clear();
        sub.reserve(no_sub);
        std::ranges::for_each(sv::iota(0, no_sub), [&](auto const&) {
            int in;
            std::cin >> in;
            sub.push_back(in);
            });

        // 1) 
        // <-- complete the code

        auto const pred = [](const int val1, const int val2) {
            return val1 == val2;
        };

        auto found = sr::search(items, sub, pred , &Item::id, [](const int& iValue) {return iValue; });

        const auto first = std::distance(items.begin(), found.begin());
        const auto last = std::distance(items.begin(), found.end());

        if (found)
            std::cout << first << " " << last << std::endl;
        else
           std::cout << "nop";

    }
}

/* Sub-task 2 */
void runSubTask02()
{
    int no_tests;
    std::cin >> no_tests;

    int no_items;
    int no_sub;

    std::vector<Item> items;
    std::vector<int>  sub;
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Given the input string
        std::cin >> no_items >> no_sub;

        // read items
        items.clear();
        items.reserve(no_items);
        std::ranges::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.id >> in.name;
            items.push_back(in);
            });

        // read sub
        sub.clear();
        sub.reserve(no_sub);
        std::ranges::for_each(sv::iota(0, no_sub), [&](auto const&) {
            int in;
            std::cin >> in;
            sub.push_back(in);
            });


        // 2)
        // <-- complete the code
        auto found = sr::find_end(items, sub, {}, &Item::id, [](const int& iValue) {return iValue; });

        const auto first = std::distance(items.begin(), found.begin());
        const auto last = std::distance(items.begin(), found.end());

        if (found)
            std::cout << first << " " << last << std::endl;
        else
            std::cout << "nop";
    }
}

/* Sub-task 3 */
void runSubTask03()
{
    int no_tests;
    std::cin >> no_tests;

    int no_items;
    int no_needles;

    std::vector<Item> items;
    std::vector<int>  needles;
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Given the input string
        std::cin >> no_items >> no_needles;

        // read items
        items.clear();
        items.reserve(no_items);
        std::ranges::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.id >> in.name;
            items.push_back(in);
            });

        // read needles
        needles.clear();
        needles.reserve(no_needles);
        std::ranges::for_each(sv::iota(0, no_needles), [&](auto const&) {
            int in;
            std::cin >> in;
            needles.push_back(in);
            });

        // 3) 
        // <-- complete the code

        auto found1 = sr::find_first_of(items, needles, 
               {}, &Item::id, [](const int& iValue) {return iValue; });

        if (found1 != items.end())
        {
            auto pos1 = std::distance(items.begin(), found1);
            std::cout << pos1 << " " << items.at(pos1).name << std::endl;

            auto found2 = sr::find_first_of(found1 + 1, items.end(), needles.begin(), needles.end(), 
                {}, &Item::id, [](const int& iValue) {return iValue; });

            if (found2 != items.end())
            {
                auto pos2 = std::distance(items.begin(), found2);
                std::cout << pos2 << " " << items.at(pos2).name << std::endl;
            }
            else
            {
                std::cout << "nop" << std::endl;
            }
        }
        else
        {
            std::cout << "nop" << std::endl;
        }
    }
}




/********
 * Main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    //using namespace std::literals;

    //std::string sub_task;
    //std::cin >> sub_task;

    //if (sub_task == "search_beg"sv)
        runSubTask01();
    //else if (sub_task == "search_end"sv)
        //runSubTask02();
    //else if (sub_task == "find_first_of"sv)
        //runSubTask03();

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
