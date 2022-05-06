#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
  // a = 5(00000101), b = 9(00001001)
    int a = 5, b = 9 , c = 1;
  

  // Call the signature function
    cout << "(a and b) or (not c) = " << bitEval01(a, b, c) << endl;
    cout << "a xor b = " << bitEval02(a,b) << endl;

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
