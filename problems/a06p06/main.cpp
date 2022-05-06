// Include needed standard library functions
#include <string>
#include <vector>

#include <iostream>
#include <iomanip>

#include <ranges>
#include <numeric>
#include <algorithm>
#include <span>


namespace sv = std::views;
namespace sr = std::ranges;



/* Sub-task 1 */
void runSubTask01()
{
    int no_tests;
    std::cin >> no_tests;

    std::string input;
    std::string sub;
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Given the input string
        std::cin >> input >> sub;

        // 1) 
        // <-- complete the code
        auto found = sr::search(input, sub);

        const auto first = std::distance(input.begin(), found.begin());
        const auto last = std::distance(input.begin(), found.end());

        if(found)
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

    std::string input;
    std::string sub;
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Given the input string
        std::cin >> input >> sub;

        // 2)
        auto found = sr::find_end(input, sub);

        const auto pos = std::distance(input.begin(), found.begin());

        if (found)
            std::cout << pos << " " << pos + found.size() << std::endl;
        else
            std::cout << "nop";
    }
}


/* Sub-task 3 */
void runSubTask03()
{
    int no_tests;
    std::cin >> no_tests;

    std::string input;
    std::string needles;
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // Given the input string
        std::cin >> input >> needles;

        // 3)
        auto found1 = sr::find_first_of(input, needles);
        
        if (found1 != input.end())
        { 
            auto pos1 = std::distance(input.begin(), found1);
            std::cout << pos1 << std::endl;

            auto found2 = sr::find_first_of(found1 + 1, input.end(), needles.begin(), needles.end());

            if (found2 != input.end())
            {
                auto pos2 = std::distance(input.begin(), found2);
                std::cout << pos2 << std::endl;
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

       // auto print = [](const auto& n) { std::cout << ' ' << n; };

        //auto find_char = [&input](char c) 
        //{
        //    auto found = input.find_first_of(c); 
        //    
        //    if (found != std::string::npos)
        //        std::cout << found << std::endl;
        //    else
        //        std::cout << "nop" << std::endl;;
        //};

        //sr::for_each(needles, find_char);


        //auto find_sub = [&input, &needles](char c)
        //{
        //    auto found = sr::find_first_of(input, needles);;
        //    auto pos = std::distance(input.begin(), found);

        //    if (found != input.end())
        //        std::cout << pos << std::endl;
        //    else
        //        std::cout << "nop" << std::endl;


        //};

        //sr::for_each(needles, find_sub);
        

        //    std::string str("Please, replace the vowels in this sentence by asterisks.");
        //    std::size_t found = str.find_first_of("aeiou");
        //    while (found != std::string::npos)
        //    {
        //        str[found] = '*';
        //        found = str.find_first_of("aeiou", found + 1);
        //    }

        //    std::cout << str << '\n';


        //sr::for_each(input, [&input](auto const&) {
        //    Item in;
        //    std::cin >> in.name >> in.price;
        //    items.push_back(in);
        //})
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
    //    runSubTask01();
    //else if (sub_task == "search_end"sv)
        //runSubTask02();
    //else if (sub_task == "find_first_of"sv)
        runSubTask03();

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
