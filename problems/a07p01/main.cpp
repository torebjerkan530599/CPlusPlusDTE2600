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
};

namespace sv = std::views;
namespace sr = std::ranges;

/* Sub-task 1 */
void runSubTask01()
{
	int no_tests;
	std::cin >> no_tests;

	int         no_items;
	std::string some_name;
	auto        items = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// read no items and middle _index
		std::cin >> no_items;

		// read items
		items.clear();
		items.reserve(no_items);
		sr::for_each(sv::iota(0, no_items), [&](auto const&) {
			Item in;
			std::cin >> in.name;
			items.push_back(in);
			});

		std::cin >> some_name;

		// 1)

		//int iteration = 0;

		//for (auto &item : items)
		//{ 
		//    std::cout << iteration;
		//    for (auto& item : items)
		//    {
		//        std::cout << " " << item.name << ", ";
		//    }
		//    std::cout << "\n";
		//    

		//    if (item.name == some_name)
		//    {
		//        //sr::rotate(items, items.begin() + 1);
		//        sr::rotate(items, items.begin() + iteration);
		//        break;
		//    }

		//    iteration++;
		//    sr::rotate(items, items.begin());
		//}

		//
		//   //std::cout << std::endl;
		//   std::cout << "Result: " << iteration << " " << std::endl;
		////sr::rotate(items, items.begin() + iteration);
		//   for (auto& item : items)
		//        std::cout << item.name << ", ";

		   //static_assert(false, "Complete the code");
	}

	if (auto itr = sr::find(items, some_name, &Item::name); sr::rotate(items, itr))
	{
		for (auto& item : items)
			std::cout << item.name << std::endl;
	}
	else
	{
		for (auto& item : items)
			std::cout << item.name << std::endl;
	}

}

/* Sub-task 2 */
void runSubTask02()
{
	int no_tests;
	std::cin >> no_tests;

	int         no_items;
	std::string name;
	int         hi, lo;
	auto        items = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// read no items and middle _index
		std::cin >> no_items;

		// read items
		items.clear();
		items.reserve(no_items);
		sr::for_each(sv::iota(0, no_items), [&](auto const&) {
			Item in;
			std::cin >> in.name;
			items.push_back(in);
			});

		std::cin >> lo >> hi >> name;

		// 2)

		//auto pred = [&name](const std::string& other_name) { return other_name == name; };
		//auto itr = find(items.begin() + lo, items.begin() + hi, name, &Item::name);

	/*	int iteration = 0;*/

		//auto lower = items.begin() + lo;
		//auto higher = items.begin() + hi;
		//
		//for (auto lower = items.begin() + lo; lower != items.begin() + hi; ++lower)
		//{
		//	auto i = std::distance(items.begin(), lower);
			//std::cout << iteration;
			//for (auto& item : items)
			//{
			//	std::cout << " " << item.name << ", ";
			//}
			//std::cout << "\n";

			//if (lower[0].name == name)
			//{
			//	sr::rotate(items.begin() + lo, items.begin() + hi, items.end());
			//	break;
			//}

			//iteration++;
			
		//}

		//for (auto& item : items)
		//	std::cout << item.name << std::endl;

		/*int iteration = 0;*/

		//auto low = items.begin() + lo;
		//auto high = items.begin() + hi;

		//auto pred = [&name](const std::string& other_name) { return other_name == name; };

		//auto found = sr::find_if(items.begin() + lo, items.begin() + hi, pred, &Item::name);
		//
		//if (found != items.begin() + hi)
		//{
		//	sr::rotate(items.begin() + lo, items.begin() + hi, items.end());
		//}


		//auto pred = [&name](const std::string& other_name) { return other_name == name; };
		//auto found = sr::find_if(items.begin() + lo, items.begin() + hi, pred, &Item::name);

		//if (auto itr = sr::find_if(items.begin() + lo, items.begin() + hi, pred, &Item::name); itr != items.begin() + hi)
		//	sr::rotate(items.begin() + lo, found, items.begin() + hi);

		if (auto itr = sr::find(items.begin() + lo, items.begin() + hi, name, &Item::name); itr != items.begin() + hi)
			sr::rotate(items.begin() + lo, itr, items.begin() + hi);

		for (auto& item : items)
			std::cout << item.name << std::endl;

		/*for (auto lower = items.begin() + lo; lower != items.begin() + hi; ++lower)
		{
			std::cout << iteration;
			for (auto& item : items)
			{
				std::cout << " " << item.name << ", ";
			}
			std::cout << "\n";

			
			if (lower[0].name == name)
			{
				break;
			}

			iteration++;
			sr::rotate(items.begin() + lo, items.begin() + hi, items.end());
			
			
		}


		std::cout << std::endl;
		std::cout << "Result: " << iteration << ": " ;

		for (auto& item : items)
			std::cout << item.name << ", ";*/



	}
}

/* Sub-task 3 */
void runSubTask03()
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
			std::cin >> in.name;
			items.push_back(in);
			});

		// 3)
		//static_assert(false, "Complete the code");

		sr::reverse(items);

		for(auto &item : items)
		{
			sr::reverse(item.name);
			std::cout << item.name << std::endl;
		}
		
	}
}

/* Sub-task 4 */
void runSubTask04()
{
	int no_tests;
	std::cin >> no_tests;

	//  std::cout << "no tests: " << no_tests << '\n';

	std::string in_string;
	int in_offset;
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// read no items and middle _index
		std::cin >> in_string >> in_offset;

		// 4)

		
		
		std::string orig_str = in_string;

		for (int i = 0; i < in_offset ; i++)
			sr::next_permutation(in_string);
		
		std::cout << in_string << std::endl;

		in_string = orig_str;

		for (int i = 0; i < 5; i++)
			sr::next_permutation(in_string);

		std::cout << in_string << std::endl;

		in_string = orig_str;

		sr::prev_permutation(in_string);
		sr::prev_permutation(in_string);
		sr::prev_permutation(in_string);

		std::cout << in_string << std::endl;

		//sr::prev_permutation(in_string);

		/*int counter = 0;
		while (sr::next_permutation(in_string).found)
		{
			if (counter == (in_offset -1 ))
				std::cout << in_string << std::endl;

			if (counter == 4)
				std::cout << in_string << std::endl;

			last_perm = in_string;
			counter++;
		}

		std::cout << "in_string before neg. perm:" << last_perm << std::endl;
		counter = 0;

		while (sr::prev_permutation(last_perm).found)
		{
			if (counter == 1)
				std::cout << last_perm << std::endl;
			counter++;
		}*/

	}
}




/********
 * Main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	//using namespace std::literals;
	//
	//std::string sub_task;
	//std::cin >> sub_task;

	//if (sub_task == "rotate"sv)
	/*runSubTask01();*/
	//else if (sub_task == "rotatesub"sv)
	    //runSubTask02();
	//else if (sub_task == "reverse"sv)
	    //runSubTask03();
	//else if (sub_task == "permutation"sv)
	    runSubTask04();

	// Return the value Zero to the operating system
	// Indicating that your program terminated successfully without sideeffects
	return 0;
}
