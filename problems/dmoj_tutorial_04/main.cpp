// Include needed standard library functions
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Read first datapoint containing the number of data elements
  int N;
  std::cin >> N;

  // Read each of the datapoints from standard in and print them successivly
  // back out to standard out with a trailing white space char ' '
  int element;
  for (auto i = 0; i < N; ++i) {
    std::cin >> element;
    std::cout << element << ' ';
  }

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}