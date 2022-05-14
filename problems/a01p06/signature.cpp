// Include needed standard library functions
#include <vector>
#include <algorithm>
#include <functional>

// The main function is the entry point for any program written in C++
void sortDesc( std::vector<int>& data )
{
  std::ranges::sort(data, std::ranges::greater());
}