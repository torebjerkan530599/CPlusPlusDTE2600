// Include needed standard library functions
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Read first datapoint containing the number of data elements
  int the_number;
  std::cin >> the_number;

  // Write "odd" or "even" to standard out based on the_number.
  if(the_number % 2 == 1)
    std::cout << "odd";
  else
    std::cout << "even";

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
