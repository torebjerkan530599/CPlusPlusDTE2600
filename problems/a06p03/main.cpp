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


/* Sub-task 1 */
void runSubTask01()
{
    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    auto items = std::vector<Item>();

    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no. items and no. extra elements
        std::cin >> no_items;

        // read items
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
         });

        // <-- complete the code
        //bool isHeap = std::is_heap(items.begin(), items.end(), [](const Item& lhs, const Item& rhs) {
        //    return lhs.name < rhs.name;
        //    });

             //bool is_min_heap = std::ranges::is_heap(items.begin(), items.end(), {}, &Item::price); //same as previous statement
            //{} is Comparator, in this case the default template argument which is ranges::less. The last argument is the projection

            bool is_max_heap = std::ranges::is_heap(items, std::ranges::greater(), &Item::price);
            bool is_min_heap = std::ranges::is_heap(items, std::ranges::less(), &Item::price); //alternativt:  std::ranges::less() == {}

            std::cout << is_max_heap << std::endl;
            std::cout << is_min_heap << std::endl;
    }
}

struct Greater {
    bool operator()(Item& item1, Item& item2) const {
        return item1.price > item2.price;
    }
};
/* Sub-task 2 */
void runSubTask02()
{
    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    auto items = std::vector<Item>();

    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no. items and no. extra elements
        std::cin >> no_items;

        // read items
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });


        // 2)
        // <-- complete the code

        //make_heap
        std::ranges::make_heap(items, std::ranges::greater(), &Item::price);
        //std::make_heap(items.begin(), items.end(), Greater());
        //std::make_heap(items.begin(), items.end(), [](const Item& lhs, const Item& rhs) {
        //    return lhs.price > rhs.price;
        //    });
        
        
        for (auto const& e : items) std::cout << e.name << ' ';
        std::cout << '\n';
    }
}

/* Sub-task 3 */
void runSubTask03()
{

    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    auto items = std::vector<Item>();

    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no. items and no. extra elements
        std::cin >> no_items;

        // read items
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });

        // 3)
        std::ranges::make_heap(items, [](const Item& lhs, const Item& rhs) {
            return lhs.price > rhs.price;
         });

        for (auto const& e : items) std::cout << e.name << ' ';
        std::cout << '\n';
    }
}

/* Sub-task 4 */
void runSubTask04()
{
    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    auto items = std::vector<Item>();

    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no. items and no. extra elements
        std::cin >> no_items;

        // read items
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });

        // 4)
        // <-- complete the code
        std::ranges::make_heap(items, [](const Item& lhs, const Item& rhs) {
            return lhs.price > rhs.price;
         });

        auto const pred = [](Item const& p1, Item const& p2)
        {
            return p1.price > p2.price;
        };

        std::ranges::sort_heap(items, pred);

        for (auto const& e : items) std::cout << e.name << ' ';
        std::cout << '\n';
    }
}

/* Sub-task 5 */
void runSubTask05()
{

    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    int  no_extra;
    auto items = std::vector<Item>();
    auto extra = std::vector<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no. items and no. extra elements
        std::cin >> no_items >> no_extra;

        // read items
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });



        // read extra items
        extra.clear();
        sr::for_each(sv::iota(0, no_extra), [&extra](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            extra.push_back(in);
            });

        // 5)
        // <-- complete the code
        std::ranges::make_heap(items, [](const Item& lhs, const Item& rhs) {
            return lhs.price < rhs.price;
            });

        
        for(Item& it : extra)
        { 
            items.push_back(it);
            std::ranges::push_heap(items, std::ranges::less(), &Item::price);
        }

        for (auto const& e : items) std::cout << e.name << ' ';
        std::cout << '\n';
    }
}


/* Sub-task 6 */
void runSubTask06()
{

    int no_tests;
    std::cin >> no_tests;

    int  no_items;
    int  no_extra;
    auto items = std::vector<Item>();
    auto extra = std::vector<Item>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read no. items and no. extra elements
        std::cin >> no_items >> no_extra;

        // read items
        items.clear();
        sr::for_each(sv::iota(0, no_items), [&items](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });

        // read extra items
        extra.clear();
        sr::for_each(sv::iota(0, no_extra), [&extra](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            extra.push_back(in);
            });

        // 6)
        // <-- complete the code
        std::ranges::make_heap(items, [](const Item& lhs, const Item& rhs) {
            return lhs.price < rhs.price;
            });

        for (Item& it : extra)
        {
            items.push_back(it);
            std::ranges::push_heap(items, std::ranges::less(), &Item::price);
        }

        for (auto n{ std::ssize(items) }; n >= 0; --n)
        {
            std::ranges::pop_heap(items.begin(), items.begin() + n, std::ranges::less(), &Item::price);
        }


        for (auto const& e : items) std::cout << e.name << ' ';
        std::cout << '\n';

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

    //if (sub_task == "is_heap"sv)
        //runSubTask01();
    //else if (sub_task == "make_minheap"sv)
        //runSubTask02();
    //else if (sub_task == "make_maxheap"sv)
    //runSubTask03();
    //else if (sub_task == "make_sorted_heap"sv)
        //runSubTask04();
    //else if (sub_task == "push_heap"sv)
        //runSubTask05();
    //else if (sub_task == "sort_heap"sv)
        runSubTask06();

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
