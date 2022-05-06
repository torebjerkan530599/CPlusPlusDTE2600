#include "header.h"

// The <signature> function definition
std::optional<char> gimmeChar(const char* char_ptr, int index) {

	// do something meaningfull
	if (index < 0 || char_ptr == NULL)
	{
		return std::nullopt;
	}

	return (*char_ptr + index);

}
