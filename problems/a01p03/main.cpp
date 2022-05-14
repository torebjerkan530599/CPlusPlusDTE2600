// Include needed standard library functions
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Read first datapoint containing the number of data elements
  int N;
  std::cin >> N;

  // write *hugs and kisses* back out to standard out.
  for( auto i = 0; i < N; ++i ) 
  {
    std::cout << "XO";
  }

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}