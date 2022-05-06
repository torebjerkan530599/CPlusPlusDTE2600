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
  ContainerPtr test1("GeeksForGeeks");
  ContainerPtr test2 { 'A','B','C' };

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
