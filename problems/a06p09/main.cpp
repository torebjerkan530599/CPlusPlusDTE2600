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
    int         year_of_birth;

    bool operator ==(const Person& p) const
    {
        return (this->name == p.name) && (this->year_of_birth == p.year_of_birth);
    }
};

namespace sv = std::views;
namespace sr = std::ranges;

/* Sub-task 1 */
void runSubTask01() {

    int no_tests;
    std::cin >> no_tests;

    int    no_items;
    Person some_dude;
    auto   items = std::vector<Person>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });

        // Read another person record
        std::cin >> some_dude.name >> some_dude.year_of_birth;


        // 1)
        // <-- complete the code

        auto const pred = [&some_dude](const int year_of_birth)
        {
            return some_dude.year_of_birth == year_of_birth;
        };

        if (sr::all_of(items, pred, &Person::year_of_birth))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
}

/* Sub-task 2 */
void runSubTask02() {
    int no_tests;
    std::cin >> no_tests;

    int    no_items;
    Person some_dude;
    auto   items = std::vector<Person>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });

        // Read another person record
        std::cin >> some_dude.name >> some_dude.year_of_birth;

        // 2)
        // <-- complete the code
        auto const pred = [&some_dude](const std::string name)
        {
            return some_dude.name == name;
        };

        if (sr::any_of(items, pred, &Person::name))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
}

/* Sub-task 3 */
void runSubTask03() {
    int no_tests;
    std::cin >> no_tests;

    int    no_items;
    Person some_dude;
    auto   items = std::vector<Person>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });

        // Read another person record
        std::cin >> some_dude.name >> some_dude.year_of_birth;

        // 3)
        // <-- complete the code
        auto const pred = [&some_dude](const Person &person)
        {
            return person == some_dude;
        };

        if (sr::none_of(items, pred))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
}

/* Sub-task 4 */
void runSubTask04() {

    int no_tests;
    std::cin >> no_tests;

    int    no_items;
    int    no_names;
    auto   items = std::vector<Person>();
    auto   names = std::vector<std::string>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });

        // Read no items
        std::cin >> no_names;

        // Read items
        names.clear();
        names.reserve(no_names);
        sr::for_each(sv::iota(0, no_names), [&](auto const&) {
            std::string in;
            std::cin >> in;
            names.push_back(in);
            });

        // 4)
        // <-- complete the code


        if (sr::equal(items, names, {}, &Person::name, [](const std::string& name) {return name; }))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
}

/* Sub-task 5 */
void runSubTask05() {

    int no_tests;
    std::cin >> no_tests;

    int    no_items;
    int    no_names;
    auto   items = std::vector<Person>();
    auto   names = std::vector<std::string>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });

        // Read no items
        std::cin >> no_names;

        // Read items
        names.clear();
        names.reserve(no_names);
        sr::for_each(sv::iota(0, no_names), [&](auto const&) {
            std::string in;
            std::cin >> in;
            names.push_back(in);
            });

        // 5)
        // <-- complete the code
        if (sr::is_permutation(items, names, {}, &Person::name, [](const std::string& name) {return name; }))
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }

}

/* Sub-task 6 */
void runSubTask06() {

    int no_tests;
    std::cin >> no_tests;

    int    no_items;
    Person some_dude;
    auto   items = std::vector<Person>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });

        // Read another person record
        std::cin >> some_dude.name >> some_dude.year_of_birth;

  /*      auto dude = std::vector<Person>(1);
        dude.push_back(some_dude);*/

        // 6)
        // <-- complete the code

        size_t counter = 0; //count the element names that are lexicographically smaller compared to the name of some_dude

        for(auto &person : items)
        {
            if (sr::lexicographical_compare(person.name, some_dude.name)) // std::ranges::less
                counter++;
        }

        if(counter > items.size() / 2 ) //Determine if the majority ... are smaller == more than half
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;

    }

}

/* Sub-task 7 */
void runSubTask07() {


    int no_tests;
    std::cin >> no_tests;

    int    no_items;
    int    no_names;
    auto   items = std::vector<Person>();
    auto   names = std::vector<std::string>();
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Read no items
        std::cin >> no_items;

        // Read items
        items.clear();
        items.reserve(no_items);
        sr::for_each(sv::iota(0, no_items), [&](auto const&) {
            Person in;
            std::cin >> in.name >> in.year_of_birth;
            items.push_back(in);
            });


        // Read no items
        std::cin >> no_names;

        // Read items
        names.clear();
        names.reserve(no_names);
        sr::for_each(sv::iota(0, no_names), [&](auto const&) {
            std::string in;
            std::cin >> in;
            names.push_back(in);
            });


        // 7)
        // <-- complete the code
        //std::pair<std::vector<int>::iterator, int*> mypair;

        const auto end = sr::mismatch(items, names, {}, &Person::name, [](const std::string& name) {return name; });

        if (end.in1 != items.end())
        {
            const std::size_t length = std::ranges::distance(items.begin(), end.in1);
            std::cout << length << std::endl;
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
 /*   using namespace std::literals;

    std::string sub_task;
    std::cin >> sub_task;*/

   // if (sub_task == "all"sv)
        //runSubTask01();
    //else if (sub_task == "any"sv)
        //runSubTask02();
    //else if (sub_task == "none"sv)
        //runSubTask03();
    //else if (sub_task == "equal"sv)
        //runSubTask04();
    //else if (sub_task == "perm"sv)
        //runSubTask05();
    //else if (sub_task == "lexi"sv)
        //runSubTask06();
    //else if (sub_task == "mis"sv)
        runSubTask07();

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
