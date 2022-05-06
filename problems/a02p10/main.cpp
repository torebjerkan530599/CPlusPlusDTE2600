// Include needed standard library functions
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	std::string quote;
	std::getline(std::cin, quote);
	string title = "";

	if (quote == "Frankly, my dear, I don't give a damn")
	{
		title = "Gone with the Wind";
	}
	else if (quote == "I'm going to make him an offer he can't refuse")
	{
		title = "The Godfather";
	}

	else if (quote == "And shepherds we shall be")
	{
		title = "The Boondock Saints";
		
	}

	else
	{
		title = "nop !_!";;
	}
	std::transform(title.begin(), title.end(), title.begin(), ::tolower);
	std::cout << title << endl;




  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
