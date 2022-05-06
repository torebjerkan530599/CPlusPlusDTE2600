#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <unordered_map>
#include <map>
#include <forward_list>
#include <string>

struct Info {
    int age;
};

class Name {
    std::string m_name;

    friend class NameHasher;

public:
    // Constructor
    Name(std::string p_name) : m_name{ p_name } {}

    // Comparison
    auto operator <=> (Name const& other) const = default;

    // Access
    std::string const& toString() const { return m_name; }
};

using OrderedNameMap = std::map<Name, int>;

struct NameHasher {
    std::size_t operator()(Name const& name) const noexcept;
};
using UnorderedNameMap = std::unordered_map<Name, int, NameHasher>;
using NameInfoMap = std::unordered_map<std::string, Info>;

OrderedNameMap   countNames01(std::forward_list<Name> const& names);
UnorderedNameMap countNames02(std::forward_list<Name> const& names);
std::string      idToString(size_t id, std::vector<Name> const& names,
    NameInfoMap const& info);

#endif // HEADER_H
