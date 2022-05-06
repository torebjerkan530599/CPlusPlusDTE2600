#include "header.h"
#include <iostream>
#include <utility>
// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
  ;

  // Call the signature function
  //test 1: [[maybe_unused]] auto const result = toCharArray("testing89 testest et ww");



  //std::cout << "test 2: " << std::endl;
  //std::cout << "\n\n";
  //
  ////using CharArray = std::array<char, 10ul>;
  //
  //CharArray a = {"test1"};
  //CharArray b = {"test2"};
  //CharArray c = {"test3"};
  //
  ////using StringVector = std::vector<CharArray>;
  //StringVector v { a, b, c };
  //
  //CharArray str = { "HappyDay" };
  //
  //appendReversed(v, str);


  //Test 3:
  pair<int, string> PAIR1(4, "upon");;
  pair<int, string> PAIR2(1, "Once");
  pair<int, string> PAIR3(8, "time");;
  auto PAIR4 = make_pair(5, "a");

  std::vector<std::pair<int, std::string>> v{PAIR1,PAIR2,PAIR3,PAIR4};

  stableSort(v);

  for (auto i : v)
	  std::cout << i.first << " " << i.second << std::endl;



  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
