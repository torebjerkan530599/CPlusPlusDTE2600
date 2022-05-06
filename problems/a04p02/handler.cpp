#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	Circle c(3.0);
	Triangle t(2.0, 5.0);
	Rectangle r(4.0, 4.0);

	std::weak_ordering value = compareArea(t, r);

	if (value == 0)
		std::cout << "equal\n";
	else if (value < 0)
		std::cout << "less\n";
	else
		std::cout << "greater\n";


  return 0;
}
