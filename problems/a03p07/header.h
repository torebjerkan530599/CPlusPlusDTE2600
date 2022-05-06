#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <optional>
#include <vector>
#include <tuple>

struct Record {
    std::string name;
    int         age;
};

// The <signature> declaration(s)
std::string toString(Record const& rec);
void resetAge(std::vector<Record>& records);
Record getOldestAndAnonymizeInput(std::vector<std::tuple<std::string, int>>& records, std::string const& p_name);


#endif // HEADER_H