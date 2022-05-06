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
	int         age;
};

namespace sv = std::views;
namespace sr = std::ranges;


/* Sub-task 1 */
void runSubTask01()
{
	int no_tests;
	std::cin >> no_tests;

	//  std::cout << "no tests " << no_tests << '\n';

	int  no_items;
	auto items = std::vector<Item>();
	auto A = std::vector<Item>();
	auto B = std::vector<Item>();
	auto result = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// reset
		items.clear();
		A.clear();
		B.clear();
		result.clear();

		// read no items and middle _index
		std::cin >> no_items;

		// read items
		sr::for_each(sv::iota(0, no_items), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			items.push_back(in);
			});

		auto const pred_A = [](const Item& item) { return item.age >= 10 && item.age < 60; };
		auto const pred_B = [](const Item& item) { return item.age >= 30 && item.age < 70; };

		sr::copy_if(items, std::back_inserter(A), pred_A);
		sr::copy_if(items, std::back_inserter(B), pred_B);

		auto const pred = [](const Item& item1, const Item& item2) {
			if (item1.age != item2.age)
				return item1.age < item2.age;
			return item1.name < item2.name;
		};

		sr::sort(A, pred);
		sr::sort(B, pred);

		sr::set_difference(A, B, std::back_inserter(result), pred);

		auto const result_order = [](const int id_1, const int id_2) {return id_1 < id_2; };

		sr::sort(result, result_order, &Item::id);

		std::cout << std::endl;

		for (auto& res : result)
			std::cout << res.id << " " << res.name << " " << res.age << std::endl;

	}
}

/* Sub-task 2 */
void runSubTask02()
{
	int no_tests;
	std::cin >> no_tests;

	int  no_items;
	auto items = std::vector<Item>();
	auto A = std::vector<Item>();
	auto B = std::vector<Item>();
	auto result = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// reset
		items.clear();
		A.clear();
		B.clear();
		result.clear();

		// read no items and middle _index
		std::cin >> no_items;

		// read items
		sr::for_each(sv::iota(0, no_items), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			items.push_back(in);
			});

		// 2)
		auto const pred_A = [](const Item& item) { return item.age >= 10 && item.age < 60; };
		auto const pred_B = [](const Item& item) { return item.age >= 30 && item.age < 70; };

		sr::copy_if(items, std::back_inserter(A), pred_A);
		sr::copy_if(items, std::back_inserter(B), pred_B);

		auto const pred = [](const Item& item1, const Item& item2) {
			if (item1.age != item2.age)
				return item1.age < item2.age;
			return item1.name < item2.name;
		};

		sr::sort(A, pred);
		sr::sort(B, pred);

		sr::set_intersection(A, B, std::back_inserter(result), pred);

		auto const result_order = [](const int id_1, const int id_2) {return id_1 < id_2; };

		sr::sort(result, result_order, &Item::id);

		std::cout << std::endl;

		for (auto& res : result)
			std::cout << res.id << " " << res.name << " " << res.age << std::endl;

	}
}

/* Sub-task 3 */
void runSubTask03()
{
	int no_tests;
	std::cin >> no_tests;

	int  no_items;
	auto items = std::vector<Item>();
	auto A = std::vector<Item>();
	auto B = std::vector<Item>();
	auto result = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// reset
		items.clear();
		A.clear();
		B.clear();
		result.clear();

		// read no items and middle _index
		std::cin >> no_items;

		// read items
		sr::for_each(sv::iota(0, no_items), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			items.push_back(in);
			});

		// 3)
		auto const pred_A = [](const Item& item) { return item.age >= 10 && item.age < 60; };
		auto const pred_B = [](const Item& item) { return item.age >= 30 && item.age < 70; };

		sr::copy_if(items, std::back_inserter(A), pred_A);
		sr::copy_if(items, std::back_inserter(B), pred_B);

		auto const pred = [](const Item& item1, const Item& item2) {
			if (item1.age != item2.age)
				return item1.age < item2.age;
			return item1.name < item2.name;
		};

		sr::sort(A, pred);
		sr::sort(B, pred);

		sr::set_union(A, B, std::back_inserter(result), pred);

		auto const result_order = [](const int id_1, const int id_2) {return id_1 < id_2; };

		sr::sort(result, result_order, &Item::id);

		std::cout << std::endl;

		for (auto& res : result)
			std::cout << res.id << " " << res.name << " " << res.age << std::endl;
	}
}

/* Sub-task 4 */
void runSubTask04()
{
	int no_tests;
	std::cin >> no_tests;

	int  no_items;
	auto items = std::vector<Item>();
	auto A = std::vector<Item>();
	auto B = std::vector<Item>();
	auto result = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// reset
		items.clear();
		A.clear();
		B.clear();
		result.clear();

		// read no items and middle _index
		std::cin >> no_items;

		// read items
		sr::for_each(sv::iota(0, no_items), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			items.push_back(in);
			});

		// 4)
		auto const pred_A = [](const Item& item) { return item.age >= 10 && item.age < 60; };
		auto const pred_B = [](const Item& item) { return item.age >= 30 && item.age < 70; };

		sr::copy_if(items, std::back_inserter(A), pred_A);
		sr::copy_if(items, std::back_inserter(B), pred_B);

		auto const pred = [](const Item& item1, const Item& item2) {
			if (item1.age != item2.age)
				return item1.age < item2.age;
			return item1.name < item2.name;
		};

		sr::sort(A, pred);
		sr::sort(B, pred);

		sr::set_symmetric_difference(A, B, std::back_inserter(result), pred);

		auto const result_order = [](const int id_1, const int id_2) {return id_1 < id_2; };

		sr::sort(result, result_order, &Item::id);

		std::cout << std::endl;

		for (auto& res : result)
			std::cout << res.id << " " << res.name << " " << res.age << std::endl;
	}
}

/* Sub-task 5 */
void runSubTask05()
{
	int no_tests;
	std::cin >> no_tests;

	int  no_items_A;
	int  no_items_B;
	auto A = std::vector<Item>();
	auto B = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// reset
		A.clear();
		B.clear();

		// read no items and middle _index
		std::cin >> no_items_A >> no_items_B;

		// read items
		sr::for_each(sv::iota(0, no_items_A), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			A.push_back(in);
			});

		// read items
		sr::for_each(sv::iota(0, no_items_B), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			B.push_back(in);
			});

		// 5)

		auto const pred = [](const Item& item1, const Item& item2) {
			if (item1.age != item2.age)
				return item1.age < item2.age;
			return item1.name < item2.name;
		};

		sr::sort(A, pred);
		sr::sort(B, pred);

		sr::includes(A, B, pred) ? std::cout << "yes" : std::cout << "no" << std::endl;
	}
}

/* Sub-task 6 */
void runSubTask06()
{
	int no_tests;
	std::cin >> no_tests;

	int  no_items_A;
	int  no_items_B;
	auto A = std::vector<Item>();
	auto B = std::vector<Item>();
	auto result = std::vector<Item>();
	for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

		// reset
		A.clear();
		B.clear();
		result.clear();

		// read no items and middle _index
		std::cin >> no_items_A >> no_items_B;

		// read items
		sr::for_each(sv::iota(0, no_items_A), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			A.push_back(in);
			});

		// read items
		sr::for_each(sv::iota(0, no_items_B), [&](auto const&) {
			Item in;
			std::cin >> in.id >> in.name >> in.age;
			B.push_back(in);
			});

		// 6)
		auto const pred = [](const Item& item1, const Item& item2) {
			if (item1.age != item2.age)
				return item1.age < item2.age;
			return item1.name < item2.name;
		};

		sr::sort(A, pred);
		sr::sort(B, pred);

		sr::merge(A, B, std::back_inserter(result), pred);
		
		//std::cout << std::endl;
		//std::cout << "Before order by id:" << std::endl;
		//std::cout << std::endl;
		
		//for (auto& res : result)
		//	std::cout << res.id << " " << res.name << " " << res.age << std::endl;

		//std::cout << std::endl;
		//std::cout << std::endl;

		auto const result_order = [](const int id_1, const int id_2) {return id_1 < id_2; };

		sr::sort(result, result_order, &Item::id);

		//std::cout << "After order by id:" << std::endl;
		//std::cout << std::endl;

		for (auto& res : result)
			std::cout << res.id << " " << res.name << " " << res.age << std::endl;

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

	//if (sub_task == "set_difference"sv)
	//runSubTask01();
	//else if (sub_task == "set_intersection"sv)
	    //runSubTask02();
	//else if (sub_task == "set_union"sv)
	//    runSubTask03();
	//else if (sub_task == "set_symmetric_difference"sv)
	//    runSubTask04();
	//else if (sub_task == "set_includes"sv)
	    //runSubTask05();
	//else if (sub_task == "set_merge"sv)
	    runSubTask06();

	// Return the value Zero to the operating system
	// Indicating that your program terminated successfully without sideeffects
	return 0;
}
