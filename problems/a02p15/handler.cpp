#include "header.h"
#include <iostream>

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Parameter
    const size_t row = 3;
    const size_t col = 4;
    const char  a[row][col] = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'} };

    std::optional<char> ch = valueInCharTbl(*a, 3, 4, 2, 3);
    cout << "the character at [3][2] " << "is " << *ch << endl;
   
  return 0;
}
