#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <vector>
#include <string>

// Types
struct Person {
	std::string name;
	int         age;
};

// The <signature> function  declaration
void                  sortMyInts(std::vector<int>& ints);
std::pair<bool, bool> amISorted(std::vector<Person> const& people);
//std::vector<int>      generateOddNumbers(int low, int high);
//std::vector<int>      generateOddNumbersReversed(int low, int high);

#endif // HEADER_H
