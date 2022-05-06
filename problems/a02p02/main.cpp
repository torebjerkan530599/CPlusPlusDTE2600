// Include needed standard library functions
#include <iostream>
#include <iomanip>

auto consteval pi() {
    return 3.141592653589793238;
}

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    double circumference = pi() * 4;

    std::cout << std::fixed << std::setprecision(0) << circumference << std::endl;
    std::cout << std::showpoint << std::fixed << std::setprecision(4) << circumference << std::endl;
    std::cout << std::showpoint << std::fixed << std::setprecision(7) << circumference << std::endl;

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
