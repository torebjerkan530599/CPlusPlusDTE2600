// Include needed standard library functions
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cout << "C++ is fun ~_*" << std::endl;
	}

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
