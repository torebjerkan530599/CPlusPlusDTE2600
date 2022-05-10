#include "header.h"

// Include needed standard library functions (STL)
#include <ranges>
#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace sr = std::ranges;
namespace sv = std::views;

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{

    std::vector<std::ptrdiff_t> enc;
    std::vector<std::vector<char>> lookup_tbls;
    std::vector<char const*> lookup_tbl_tbl;

    // Read lookup table data
    int no_lookup_tbls;
    std::cin >> no_lookup_tbls;

    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_lookup_tbls)) {

        // Create table and get it
        lookup_tbls.resize(lookup_tbls.size() + 1);
        auto& curr_tbl = lookup_tbls.back();

        // Read in chars
        int no_chars_in_tbl;
        std::cin >> no_chars_in_tbl;
        sr::for_each(sv::iota(0, no_chars_in_tbl), [&](auto const&) {
            char in;
            std::cin >> in;
            curr_tbl.push_back(in);
            });
    }

    // Add tables to table table
    for (auto const& tbl : lookup_tbls)
        lookup_tbl_tbl.push_back(tbl.data());

    // Read "encoded" message
    int no_chars_in_msg;
    std::cin >> no_chars_in_msg;
    enc.push_back(no_chars_in_msg);
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_chars_in_msg)) {

        int tbl_idx;
        int char_idx;
        std::cin >> tbl_idx >> char_idx;
        enc.push_back(tbl_idx);
        enc.push_back(char_idx);
    }

    auto const message = decode(enc.data(), lookup_tbl_tbl.data());
    std::cout << message << '\n';

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
