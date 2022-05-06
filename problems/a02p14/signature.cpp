#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;

// The <signature> function definition
char const* addressOfChar(char const* char_array, size_t length, char c)
{

	if (!char_array || !*char_array || char_array == NULL) // The array does not exist at all or is empty 
	{ 
		return nullptr;
	}

	for (size_t n = 0; n < length; n++)
	{
		
		if (*char_array == c)
		{	
			
			cout << &char_array << " " << endl;
			/*cout << (void*)&first_char << " " << endl;*/
			return  char_array;

		}
		char_array++;
	}

	return nullptr;
}

