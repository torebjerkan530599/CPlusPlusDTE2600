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
  Item item;

  //data for toString function
  item.category = "movie";
  item.name = "2001 A Space Odyssey (1968)";
  item.price = 50.254545;

  cout << toString(item) << endl;

  //test totalPrice function with 3 of the same item

  cout << "Total price: " << totalPrice(item,item,item) << endl;
  
  Person person = createRecord("Barry", "White", 1977);

  cout << "Records: " << person.name << ", age: " << person.age << endl;
  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects

  Person record1{ "Ola", 54 };
  Person record2{ "Jens", 55 };
  Person record3{ "Ulf", 34 };


  restrictFromBuying(item, record1, record2, record3);


  return 0;
}
