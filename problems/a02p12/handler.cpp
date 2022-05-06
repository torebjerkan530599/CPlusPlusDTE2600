#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	// Parameter
	int index = 3;

	char arr[] = {'a','b','c','d','e','f'};

	// Call the signature function
	std::optional<char> ch = gimmeChar(arr, index);

	cout << "the character at index " << index << "is " << *ch << endl;

	// Return the value Zero to the operating system
	// Indicating that your program terminated successfully without sideeffects
	return 0;
}
