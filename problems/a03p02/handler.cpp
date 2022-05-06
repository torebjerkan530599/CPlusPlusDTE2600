#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{

	Item item;
	item.category = "movie";
	item.name = "2001 A Space Odyssey (1968)";
	item.price = 50.254545;
	item.age_limit = 20;

	priceOfItem(&item);
	raiseAgeLimitBy(item, '3');

	Person person { "Barry", 19 };
	void* ptr = &person;

	setAge(&person, 77);
  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
