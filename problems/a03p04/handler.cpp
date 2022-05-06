#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
  //string param = "nop";

  //// Call the signature function
  //auto test = toAny(param);

  //try {
	 // cout << std::any_cast<int>(test) << endl;
	 // std::cout << "it is an integer" << endl;
  //}
  //catch (const std::bad_any_cast& e) {
	 // std::cout << e.what() << '\n';
	 // std::cout << "it is not an int" << endl;
  //}

  //try {
	 // cout << std::any_cast<float>(test) << endl;
	 // std::cout << "it is a float" << endl;
  //}
  //catch (const std::bad_any_cast& e) {
  //    std::cout << e.what() << '\n';
	 // std::cout << "it is not a float" << endl;
  //}

  //try {
	 // cout << std::any_cast<string>(test) << endl;
	 // std::cout << "it is a string" << endl;
  //}
  //catch (const std::bad_any_cast& e) {
	 // std::cout << e.what() << '\n';
	 // std::cout << "it is not a string" << endl;
  //}

  //try {
	 // cout << std::any_cast<double>(test) << endl;
	 // std::cout << "it is a double" << endl;
  //}
  //catch (const std::bad_any_cast& e) {
	 // std::cout << e.what() << '\n';
	 //
  //}
  	  
	//variant<float,int> res = solve(201);

	//if (std::holds_alternative<int>(res))
	//{
	//	cout << std::get<int>(res);
	//}
	//else
	//{
	//	cout << std::get<float>(res);
	//}

	//optional<int> x = division(-2, -2, -2);

	//if(x)
	//{ 
	//	cout << *x << endl;
	//}
	// 

	cout << toString(54.456f, 2) << endl;
	cout << toString(3, 2) << endl;
  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
