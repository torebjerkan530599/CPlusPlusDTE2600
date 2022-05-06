#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <forward_list>
#include <list>

void reverse(std::forward_list<int> const& in, std::forward_list<int>& out);
void pyramidCopy(std::forward_list<int> const& in, std::list<int>& out);

#endif // HEADER_H
