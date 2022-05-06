#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;

// The <signature> function definition
std::optional<char> gimmeChar(const char char_array[], int index) {

  // do something meaningfull
	if (index < 0 || char_array == nullptr)
	{
		return std::nullopt;
	}

  // return the result
  return char_array[index];
}
