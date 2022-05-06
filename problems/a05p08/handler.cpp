#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
  int param = 3;

  // Call the signature function
  [[maybe_unused]] vector<int> vec;
  
  vec.resize(20);

  forEachOne(vec);

  for (int e : vec)
  {
	  std::cout << e << endl;
  }

  vector<string> vec_str{ "Once upon","a time","there was a","very old king" };

  forEachString(vec_str);

  for (auto& s : vec_str)
  {
	  
  }

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
