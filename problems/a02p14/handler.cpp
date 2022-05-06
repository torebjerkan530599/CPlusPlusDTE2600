#include "header.h"
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
  int length = 5;
  char arr[] = "abcde";
  

  // Call the signature function
  char const* result = addressOfChar(arr, length, 'c');

  std::cout << "address of 'c':" << (void *)result << std::endl;

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
