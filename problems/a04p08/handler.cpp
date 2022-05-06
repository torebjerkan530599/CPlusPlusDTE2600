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

  

  
  

  
  //IntVector v1({ 1, 2, 3, 4, 5 });
  //cout << v1 << endl; //print 1D vector


  //IntVector mector({});
  //cin >>  mector ; // read 1D vector
  //cout << mector << endl; //print 1d vector


  std::vector<std::vector<int>> vect2D1{ { 1, 2, 3},{4, 5, 6}};
  IntMatrix hector(vect2D1);
  cout << hector << endl; //print 2D vector

  std::vector<vector<int>> vect2D2(0, vector<int>(0, 0));
  IntMatrix matV2(vect2D2);
  cin >> matV2; //read 2D vector
  cout << matV2; // print 2D vector


  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
