#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
	Circle c(3.0);
	cout << "Circle: " << toString(c) << endl;
	Triangle t(2.0, 5.0);
	cout << toString(t) << endl;


  return 0;
}
