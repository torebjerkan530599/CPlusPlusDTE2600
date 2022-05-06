// Include needed standard library functions
#include <string>
#include <vector>
#include <forward_list>

#include <iostream>
#include <iomanip>

#include <ranges>
#include <numeric>
#include <algorithm>
#include <span>


struct Item {
    int         id;
    std::string name;
    int         age;
};

namespace sv = std::views;
namespace sr = std::ranges;


// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int no_tests;
    std::cin >> no_tests;

    int         no_items;
    std::string secret_name;
    int secret_age_limit;
    int lookup_lo;
    int lookup_hi;
    auto item_list = std::forward_list<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no items and no
        std::cin >> no_items;

        // read items
        item_list.clear();
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.id >> in.name >> in.age;
            item_list.push_front(in);
        });

        // Read the given name
        std::cin >> secret_name >> secret_age_limit >> lookup_lo >> lookup_hi;

        /*const auto pred = [&secret_age_limit, &secret_name](Item &item) 
        { 
            bool is_anonymous = item.age > secret_age_limit;

            if(is_anonymous)
                item.name = secret_name;

            return is_anonymous;       
        };

        auto proj = [=](const Item &item)
        {
            if (item.age >= lookup_lo && item.age <= lookup_hi)
                return item;
        };

        auto vec = std::vector<Item>();

        sr::remove_copy_if(item_list, std::back_inserter(vec), pred, proj);*/

        for (auto& item : item_list)
            if (item.age > secret_age_limit)
                item.name = secret_name;

        auto vec = std::vector<Item>();

        auto pred = [=](const Item& item)
        {
            return (item.age >= lookup_lo) && (item.age <= lookup_hi);       
        };

        sr::copy_if(item_list, std::back_inserter(vec), pred);

        auto const result_order = [](const int id_1, const int id_2) {return id_1 < id_2; };

        sr::sort(vec, result_order, &Item::id);

        for (auto& res : vec)
            std::cout << res.id << " " << res.name << " " << res.age << std::endl;

    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
