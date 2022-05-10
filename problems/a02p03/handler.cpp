#include "header.h"

// stl
#include <iostream>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{

    // Get type sizes
    auto const type_sizes = getTypeSizes();

    // Get type size components as individual variables
    auto const& [bool_size, char_size, int_size, float_size, double_size] = type_sizes;

    // Print the type sizes to standard out
    std::cout << "bool size:   " << bool_size << '\n'
        << "char size:   " << char_size << '\n'
        << "int size:    " << int_size << '\n'
        << "float size:  " << float_size << '\n'
        << "double size: " << double_size << '\n';

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
