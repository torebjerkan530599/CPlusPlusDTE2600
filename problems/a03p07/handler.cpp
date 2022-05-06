#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{

	Record r = {"Tore", 44};

	string s = toString(r);


	std::vector<std::tuple<std::string, int>> vec;
	// legg til på slutten av vectoren
	vec.push_back(std::tuple{ "Donald", 108 });
	// legg til på slutten av vectoren men opprett objektet "in place"
	vec.emplace_back( "hmm", 75 );

	vec.emplace_back("allah", 92);
	
	auto const rec = getOldestAndAnonymizeInput(vec, "anonymouse");

	cout << "age: " << rec.age << " - name: " << rec.name << endl;

	//getOldestAndAnonymizeInput(vec , "navn");
  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
