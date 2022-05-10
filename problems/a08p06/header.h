#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <cstddef>
#include <string>

// The <signature> function  declaration
std::string decode(std::ptrdiff_t* enc, const char** lookup);

#endif   // HEADER_H
