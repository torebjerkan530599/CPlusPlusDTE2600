#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
  int param = 3;

  const forward_list<int> flist = { 1, 2, 3};
  //forward_list<int> flast{ 8, 9, 10, 14, 15 };
  std::list<int> flout;

  // Call the signature function
  //reverse(flist,flast);

  pyramidCopy(flist, flout);

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
