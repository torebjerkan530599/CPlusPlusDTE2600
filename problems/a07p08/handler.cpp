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
  [[maybe_unused]] 

  std::vector<int> ints{ -1, 8 , -4 };
  auto const result = priorityQueueLogger(ints);

  for (auto& res : result)
	  cout << res << "\n";

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
