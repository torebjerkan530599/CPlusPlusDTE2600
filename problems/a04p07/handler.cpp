#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{


	BitsetInt8 bset(125);
	int check = bset.toInt();

	cout << "result of bitset to int: " << check;


  return 0;
}
