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
    std::string category;
    std::string name;
};

namespace sv = std::views;
namespace sr = std::ranges;

/* Sub-task 1 */
void runSubTask01()
{
    int no_tests;
    std::cin >> no_tests;

    int         no_items;
    std::string category;
    auto        items = std::vector<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no items and middle _index
        std::cin >> no_items;

        // read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.category >> in.name;
            items.push_back(in);
            });



        std::cin >> category;
        // 1)
        std::string result = category;
        auto const is_category = [&category](Item& item) { return item.category == category; }; 
        
        if (auto p1 = sr::find_if(sr::begin(items), sr::end(items), is_category); p1 != items.end())
        {

            result += " " + p1->name;

            if(auto p2 = sr::find_if(p1 + 1, sr::end(items), is_category); p2 !=items.end())
                result += " " + p2->name;
        }


        std::cout << result << std::endl;
        
        
        //for (auto& it : items)
        //{
        //    if (it.category == category)
        //    {
        //        result += " " + it.name;
        //    }
        //}
        //std::cout << result << std::endl;
    }
}

/* Sub-task 2 */
void runSubTask02()
{
    int no_tests;
    std::cin >> no_tests;

    int         no_items;
    auto        items = std::vector<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no items and middle _index
        std::cin >> no_items;

        // read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.category >> in.name;
            items.push_back(in);
            });

        // 2)
        // <-- complete the code
        sr::stable_sort(items,std::ranges::less(), &Item::category);
        auto iter = sr::adjacent_find(items, std::ranges::equal_to(), &Item::category);
     
        if (iter != items.end()) 
        { 
            std::cout << iter->category << " " + iter->name << 
            " " << (iter + 1)->name << std::endl;
        }
        else
        {
            std::cout << "nop" << std::endl;
        }
    }
}

/* Sub-task 3 */
void runSubTask03()
{
    int no_tests;
    std::cin >> no_tests;

    int         no_items;
    std::string category;
    auto        items = std::vector<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no items and middle _index
        std::cin >> no_items;

        // read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.category >> in.name;
            items.push_back(in);
            });
        std::cin >> category;

        // 3)
        // <-- complete the code

        sr::stable_sort(items, std::ranges::less(), &Item::name);
        sr::stable_sort(items, std::ranges::less(), &Item::category);
        
        std::cout << std::endl;

        std::cout << "After sort:" << std::endl;
        for (auto& i : items)
            std::cout << i.category << " " << i.name << std::endl;

        std::cout << std::endl;

        auto iter_lower = sr::lower_bound(items, category, std::ranges::less(), &Item::category);
        auto iter_upper = sr::upper_bound(items, category, std::ranges::less(), &Item::category);

        if (iter_lower != items.end())
            std::cout << iter_lower->category << " " << iter_lower->name << std::endl;
        else
            std::cout << "nop" << std::endl;

        if (iter_upper != items.end())
            std::cout << iter_upper->category << " " << iter_upper->name << std::endl;
        else
            std::cout << "nop" << std::endl;
    }
}


/* Sub-task 4 */
void runSubTask04()
{

    int no_tests;
    std::cin >> no_tests;

    int         no_items;
    auto        items = std::vector<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no items and middle _index
        std::cin >> no_items;

        // read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.category >> in.name;
            items.push_back(in);
        });


        // 4)
        // <-- complete the code
        sr::stable_sort(items, std::ranges::less(), &Item::name);
        sr::stable_sort(items, std::ranges::less(), &Item::category);

        std::cout << std::endl;

        std::cout << "After sort:" << std::endl;
        for (auto& i : items)
            std::cout << i.category << " " << i.name << std::endl;

        std::cout << std::endl;

        auto ret = sr::unique(items, [](Item& i1, Item& i2) { return i1.category == i2.category && i1.name == i2.name; });
        //auto ret = sr::unique(items, {}, &Item::category);
        
        items.erase(ret.begin(), ret.end());

        std::cout << "After call to ranges::unique:" << std::endl;

        for (auto it = items.begin(); it != items.end(); ++it)
        {
            auto i = std::distance(items.begin(), it);
            std::cout << i << " " << it->category << " " << it->name << std::endl;
        }

        int enumer = 0;
        for (auto& it : items)
        {
            std::cout << enumer << " " << it.category << " " << it.name << std::endl;
            enumer++;
        }

            //std::for_each(items.begin(), items.end(), [](const Item& elem) {
            //    // if the current index is needed:
            //    auto i = &elem - &items[0];

            //    // cannot continue, break or return out of the loop
            //});


            //td::map <int, int> MAP({ {1, 1}, {2, 2}, {3, 3} });
            //for (auto i : MAP)
            //    std::cout << '{' << i.first << ", "
            //    << i.second << "}\n";

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

    //if (sub_task == "find"sv)
        //runSubTask01();
    //else if (sub_task == "stable_sort"sv)
        //runSubTask02();
    //else if (sub_task == "bounds"sv)
        //runSubTask03();
    //else if (sub_task == "unique"sv)
        runSubTask04();

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
