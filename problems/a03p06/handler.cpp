#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
	

	//dte2600::string test;

	//string mock = "one";

	//for(char c: mock)
	//{ 
	//	test.appendChar(c);
	//}

	//std::string aString = toStdString(test);

	//dte2600::string bString = toDte2600String("two");

	int i = computeScoreFromString(toDte2600String("two"), 't', 'w', 'o');

	cout << "result: " << i << endl;
  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
