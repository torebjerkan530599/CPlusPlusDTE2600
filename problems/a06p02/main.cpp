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
    std::string name;
    double      price;
};

namespace sv = std::views;
namespace sr = std::ranges;

bool comp_lesser(Item item_1, Item item_2) { return item_1.price < item_2.price; }
bool comp_greater(Item item_1, Item item_2) { return item_1.price > item_2.price; }

struct Greater { //Functor, hvordan kan jeg bruke den i std::ranges::nth_element?
    bool operator()(Item& a, Item& b) const;
};

bool Greater::operator()(Item& a, Item& b) const
{
    return std::greater<int>()(a.price, b.price);
}

/* Sub-task 1 */




void runSubTask01() {

    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    int  no_indices;
    auto items = std::vector<Item>();
    auto indices = std::vector<int>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read items
        std::cin >> no_items;
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });

        // Read indices
        std::cin >> no_indices;
        indices.clear();
        sr::for_each(sv::iota(0, no_indices), [&indices](auto const&) {
            int index;
            std::cin >> index;
            indices.push_back(index);
            });

        
        // Print in in ascending-order
        for (auto const& ei : indices) {
            auto const& e = items.at(ei);

            // 1)
            // <-- complete the code
            std::nth_element(items.begin(), items.begin()+int(ei), items.end(), comp_lesser);  //[e](const Item& lhs, const Item& rhs) {     return lhs.price < rhs.price;});

            std::cout << e.name << '\n';
        }
    }
}

/* Sub-task 2 */
void runSubTask02() {

    int no_tests;
    std::cin >> no_tests;


    int  no_items;
    int  no_indices;
    auto items = std::vector<Item>();
    auto indices = std::vector<int>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no. items and no. index nrs.

        // Read items
        std::cin >> no_items;
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });

        // Read indices
        std::cin >> no_indices;
        indices.clear();
        sr::for_each(sv::iota(0, no_indices), [&indices](auto const&) {
            int index;
            std::cin >> index;
            indices.push_back(index);
        });

        // 2)
        // <-- complete the code
        // Print in in ascending-order
        for (auto const& ei : indices) { //take each indice and at each indice get the object at that indice
            auto const& e = items.at(ei);
            // 1)
            // <-- complete the code
            std::ranges::nth_element(items, items.begin() + ei, Greater());
            std::cout << e.name << '\n';
        }}}







/********
 * Main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    //using namespace std::literals;

    //std::string sub_task;
    //std::cin >> sub_task;

    //if (sub_task == "nth_lt"sv)
    //    runSubTask01();
    //else if (sub_task == "nth_gt"sv)
        runSubTask02();

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
