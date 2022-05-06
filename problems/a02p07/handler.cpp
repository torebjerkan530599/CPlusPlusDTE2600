#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
	forward_list<char> clist = { 's', 'w', 'e', 'e','t'};

  // Call the signature function
  cout << "my string is: " << buildTheString(clist);

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
