#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <vector>
#include <string>

// Types
struct Person {
	std::string name;
	int         year_of_birth;
};

enum class SortOrder { Asc, Dsc };
enum class SortBy { Name, YearOfBirth };

// The <signature> function  declaration
void                sortIntsOne(std::vector<int>& data);
void                sortIntsTwo(std::vector<int>& data);
void                sortIntsThree(std::vector<int>& data, int exp);
void                sortIntsFour(std::vector<int>& data, int& min, int& max);
std::pair<int, int> sortIntsMeanAndMedian(std::vector<int>& data);
void sortPeople(std::vector<Person>& people, SortOrder order, SortBy sort_by);

#endif // HEADER_H
