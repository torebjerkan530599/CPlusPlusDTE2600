#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>

// Types and declarations
enum class ColorName {
    Red,
    Green,
    Blue,
    LightYellow,
    Brown,
    Pink,
    Orange,
    Purple,
    White,
    Black
};

struct Color {
    int r{ 0 };
    int g{ 0 };
    int b{ 0 };

    bool operator == (Color const& other) const {
        return
            r == other.r and
            g == other.g and
            b == other.b;
    }
};

std::string toHtmlHex(ColorName color_name);
Color toColor(ColorName);

enum class Flag : short {
    Flag1 = 1 << 0, // 1
    Flag2 = 1 << 1, // 2
    Flag3 = 1 << 2, // 4
    Flag4 = 1 << 3, // 8
    Flag5 = 1 << 4, // 16
    Flag6 = 1 << 5, // 32
    Flag7 = 1 << 6, // 64
    Flag8 = 1 << 7  // 128
};
using Flags = short;
std::string toString(Flags flags);

#endif // HEADER_H