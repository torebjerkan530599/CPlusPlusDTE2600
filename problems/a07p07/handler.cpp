#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
	std::forward_list<Name> ls;
	Name name_class1("A");
	Name name_class2("B");
	Name name_class3("A");
	Name name_class4("D");
	Name name_class5("E");
	Name name_class6("D");
	Name name_class7("D");
	ls.push_front(name_class1);
	ls.push_front(name_class2);
	ls.push_front(name_class3);
	ls.push_front(name_class4);
	ls.push_front(name_class5);
	ls.push_front(name_class6);
	ls.push_front(name_class7);

  // Call the signature function
  /*[[maybe_unused]] auto test = countNames02(ls);

  for (auto& [key, value] : test) {
	  std::cout << key.toString() << " has value " << value << std::endl;
  }*/

	std::vector<Name> my_names { name_class1, name_class2, name_class3,name_class4 };

	NameInfoMap info_map;

	Info info1{};
	Info info2{};
	Info info3{};
	Info info4{};

	info1.age = 44;
	info2.age = 21;
	info3.age = 65;
	info4.age = 11;

	std::vector<Info> my_ages{info1,info2,info3,info4};

	info_map.insert(std::pair<std::string, Info>("A", info1));
	info_map.insert(std::pair<std::string, Info>("B", info2));
	info_map.insert(std::pair<std::string, Info>("C", info3));
	info_map.insert(std::pair<std::string, Info>("D", info4));

	std::string str = idToString(7, my_names, info_map);

	std::cout << str;

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
