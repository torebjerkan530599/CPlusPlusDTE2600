#include <string>
#include <ranges>
#include <iostream>
namespace sv = std::views;

// The <signature> function definition
std::string decode(std::ptrdiff_t* enc, char const** lookup)
{
    std::string message;

    auto const no_chars = *enc;
    
    for (auto i = 0ul; i < no_chars; ++i) {
        enc++;
        auto const tbl_idx = enc[i];
        auto const char_idx = enc[i+ 1];
        //std::cout << "tbl_idx: " << tbl_idx << " | " << "char_idx: " << char_idx << "\n";
        char const* tbl = *(lookup+tbl_idx);
        
        //std::cout << "table address: " << (void*)tbl << " | " << "value: " << *tbl << "\n";
        //std::cout << "char address: " << (void*)tbl[char_idx] << " | " << "value: " << *(tbl + char_idx) << "\n";
        //auto const* tbl = nullptr; //original
        message += *(tbl + char_idx);
    }

    return message;
}
