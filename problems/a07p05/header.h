#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <vector>
#include <array>
#include <string>

using CharArray = std::array<char, 10ul>;
using StringVector = std::vector<CharArray>;

CharArray toCharArray(std::string const& name);
void      appendReversed(StringVector& vec, CharArray const& string);
void      stableSort(std::vector<std::pair<int, std::string>>& vec);

#endif // HEADER_H
