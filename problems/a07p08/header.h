#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <unordered_set>
#include <set>
#include <forward_list>
#include <vector>

struct OrderedIntSetComparatorLessPow2 {
	bool operator()(int lhs, int rhs) const;
};

using OrderedSet = std::set<int, OrderedIntSetComparatorLessPow2>;
using UnorderedSet = std::unordered_set<int>;


OrderedSet   toOrderedSet(std::vector<int> const& ints);
UnorderedSet toSet(std::vector<int> const& ints);

std::vector<std::string> priorityQueueLogger(std::vector<int> const& input);

#endif // HEADER_H
