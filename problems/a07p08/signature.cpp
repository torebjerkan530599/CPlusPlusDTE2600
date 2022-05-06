#include "header.h"
#include <queue>
#include <string>

bool OrderedIntSetComparatorLessPow2::operator()(int lhs, int rhs) const
{
	return (lhs*lhs) < (rhs*rhs);
}

OrderedSet toOrderedSet(std::vector<int> const& ints)
{
	OrderedSet set_of_ints;

	for (int i : ints)
		set_of_ints.insert(i);

	return set_of_ints;
}

UnorderedSet toSet(std::vector<int> const& ints)
{
	UnorderedSet uset_of_ints;

	for (int i : ints)
		uset_of_ints.insert(i);

	return uset_of_ints;

}

std::vector<std::string> priorityQueueLogger(std::vector<int> const& input)
{
	// Construct a log (vector of strings)
	std::vector<std::string> log;

	// Construct a priority queue of ints
	std::priority_queue<int> pq;
	std::priority_queue<int> pq_copy;
	
	// Add each element of the input vector range to the priority queue and log the priority queue

	for (auto &i : input)
	{
		std::string log_string = "";
		pq.push(i);
		pq_copy = pq;
		while (!pq_copy.empty())
		{
			log_string += std::to_string(pq_copy.top()) + " ";
			pq_copy.pop();
		}
		log.push_back(log_string);
	}

	// Return the log
	return log;
}
