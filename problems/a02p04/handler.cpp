#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	pair<int, int> p = computeTheCircleCircumferenceAndArea(5);

	cout << "Values returned by Pair: ";
	cout << p.first << " " << p.second;

  return 0;
}
