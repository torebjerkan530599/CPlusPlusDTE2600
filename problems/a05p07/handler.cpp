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
  vector<int> vec = { 701, 54, 13, 46, 58, 69, 72 };
  
  int x = 300;
  int y = 9999;

  sortIntsFour(vec, x, y);
  sortIntsMeanAndMedian(vec);

 
  vector<Person> persons = {
	  Person("Tor", 820),
	  Person("Odin", 757),
	  Person("Freya", 800),
	  Person("Loke", 825)
  };

  sortPeople(persons, SortOrder::Asc, SortBy::YearOfBirth);



  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
