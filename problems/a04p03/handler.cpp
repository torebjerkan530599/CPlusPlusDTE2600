#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	Circle c(3.0);
	cout << toString(c) << endl;
	Triangle t(2.0, 5.0);
	cout << toString(t) << endl;
	Square s(2.0);
	cout << toString(s) << endl;
	Rectangle r(4.0, 3.0);
	cout << toString(r) << endl;

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
