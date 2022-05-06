#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++



void testExceptions()
{
	try {
		auto const str = dte2600::string("Hello World ^^");
		//str.getCharAtEx(-1);
		//str.getCharAtEx(42);
		str.getCharAtOpt(7);
	}
	catch (std::out_of_range const& err)
	{
		std::cout << "Ex: " << err.what() << '\n';
	}
}


int main(int /*argc*/, char** /*argv*/)
{

	// Call the signature function
	testExceptions();

	// Return the value Zero to the operating system
	// Indicating that your program terminated successfully without sideeffects
	return 0;
}