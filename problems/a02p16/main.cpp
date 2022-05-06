// Include needed standard library functions
#include <iostream>
#include <string>
#include <algorithm>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	std::string line = "";
	while (std::getline(std::cin, line))
	{
		if (line == "EOI" && std::any_of(line.begin(), line.end(), isupper))
		{
			break;
		} 
		else
		{ 
			std::cout << line << '\n';
		}
	}

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
