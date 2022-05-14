#include "header.h"

// Include needed standard library functions (STL)
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	using namespace std::literals;

	unsigned number;
	unsigned shift;
	std::cin >> number >> shift;

	

	auto const result = leftShift(number, shift);
	/* test result */

	if (result)
		std::cout << result.value();
	else
		std::cout << "nullopt";

	// Return the value Zero to the operating system
	// Indicating that your program terminated successfully without sideeffects
	return 0;
}
