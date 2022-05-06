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
void runSubTask01() {

    // Get individual no. test cases
    int no_test_cases;
    std::cin >> no_test_cases;

    // Cache Vars
    int  no_items;
    int  middle_index;
    auto items = std::vector<Item>();

    // Run test-cases
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_test_cases)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
        });

        // Read
        std::cin >> middle_index;

        // partial sort wrt. name

        // 1)
        // <-- complete the code
        //auto const pred = [](Item const& item1, Item const& item2)
        //{
        //    return item1.name < item2.name;
        //};

        std::partial_sort(items.begin(), items.end()-middle_index, items.end(), [](const Item& lhs, const Item& rhs) {
            return lhs.name < rhs.name;
            });

        // print result
        for (auto const& e : std::span(items.begin(), middle_index))
            std::cout << e.name << '\n';
    }
}


/* Sub-task 2 */
void runSubTask02() {

    // Get individual no. test cases
    int no_test_cases;
    std::cin >> no_test_cases;

    // Cache Vars
    int  no_items;
    int  middle_index;
    auto items = std::vector<Item>();

    // Run test-cases
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_test_cases)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Item in;
            std::cin >> in.name >> in.price;
            items.push_back(in);
            });

        // Read
        std::cin >> middle_index;

        // 2)
        std::ranges::partial_sort(items.begin(), items.end() - middle_index, items.end(), [](const Item& lhs, const Item& rhs) {
            return lhs.price < rhs.price;
            });

        // print result
        for (auto const& e : std::span(items.begin(), middle_index))
            std::cout << e.name << '\n';
    }
}


/********
 * Main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    using namespace std::literals;

    std::string sub_task;
    std::cin >> sub_task;

    if (sub_task == "partial_sort_name"sv)
        runSubTask01();
    else if (sub_task == "partial_sort_price"sv)
        runSubTask02();

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
