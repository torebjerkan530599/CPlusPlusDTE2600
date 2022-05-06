#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	// Parameter
	vector<Person> folks {{ "Amir",33 }, { "Peter", 10 }, { "Sam", 65 } };
	
	pair p = amISorted(folks);


  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
