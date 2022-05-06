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
  vector<Meta> vec_str(4);
  std::forward_list<std::string> f_list{ "Once upon", "a time", "there was a", "an animal called aardvark" };
  transformTwo(f_list, vec_str);

  std::forward_list<int> int_list1{1,2};
  std::forward_list<int> int_list2{1,-2};

  // 1^2 + abs 1 = 2
  // 2^2 + abs -2 = 6

int result = transformReduceOne(int_list1, int_list2);
 
std::cout << result << std::endl;

string result_str = transformReduceTwo(int_list1, int_list2);
std::cout << result_str << std::endl;

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
