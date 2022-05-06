// Include needed standard library functions
#include <iostream>
#include <vector>

#include <ranges>
#include <algorithm>
#include <string>
#include <cmath>

namespace sr = std::ranges;
namespace sv = std::views;

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int no_tests;
    std::cin >> no_tests;

    int a;
    int b;
    int c;
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_tests)) {

        // read coefficients
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        if(((b*b) - 4 * a * c) < 0 ) //no real roots
        {
            std::cout << "complex";
        }
        else
        {
            auto const x = (-b + std::sqrt(std::pow(b, 2) - 4 * a * c)) / (2 * a);
            auto const y = (-b - std::sqrt(std::pow(b, 2) - 4 * a * c)) / (2 * a);
            x == y ? std::cout << x : std::cout << x << " " << y;
        }

        std::cout << "\n";

    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
