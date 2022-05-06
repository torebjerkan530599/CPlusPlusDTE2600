#include "header.h"

// Include needed standard library functions (STL)
using namespace std;

// The <signature> function definition

std::string gimmeString(char const char_array[], int length) {

	string s = "";

	if (length == 0)
	{
		return s;
	}

	for (int i = 0; i < length; i++)
	{
		s = s + char_array[i];
	}

	return s;

}
