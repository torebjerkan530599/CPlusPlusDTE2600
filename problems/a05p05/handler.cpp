#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	Less const less_comparator{};
	auto const less_res = less_comparator(4, 5);

	Greater const greater_comparator{};
	auto const greater_res = greater_comparator(4, 5);

	PowLessEq const pow_comparator{};
	auto const pow_res = pow_comparator(2,5);

	CountSmallAs const count_char{};
	auto const count_res = count_char("what's app?");

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
