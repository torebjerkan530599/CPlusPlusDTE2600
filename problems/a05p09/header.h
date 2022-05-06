#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <vector>
#include <forward_list>
#include <string>

// Types
struct Meta {
    size_t length;
    size_t no_es;
};

// The <signature> function  declaration
void transformOne(std::forward_list<int> const& list, std::vector<int>& output);
void transformTwo(std::forward_list<std::string> const& strings,
    std::vector<Meta>& meta);
std::vector<std::string>
transformThree(std::forward_list<std::string> const& first_names,
    std::forward_list<std::string> const& last_names,
    std::string const& glue);
int         transformReduceOne(std::forward_list<int> const& list1,
    std::forward_list<int> const& list2);
std::string transformReduceTwo(std::forward_list<int> const& list1,
    std::forward_list<int> const& list2);


#endif // HEADER_H
