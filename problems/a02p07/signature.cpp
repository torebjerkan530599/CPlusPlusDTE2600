#include "header.h"
#include <iostream>

using namespace std;
// The <signature> function definition
std::string buildTheString(std::forward_list<char> const& char_list) {

  // do something meaningfull
	auto itr = char_list.cbegin();
	auto eitr = char_list.cend();
	string theString = "";


	while (itr != eitr)
	{
		theString += *itr;
		itr++;
	}

  // return the result
  return theString; 
}
