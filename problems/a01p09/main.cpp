// Include needed standard library functions
#include <utility>

// Function signature
std::pair<size_t, size_t> noOddEvenInRange(int lo, int hi) {
    // Return data and convenience aliases
    auto data = std::pair<size_t, size_t>{ 0ul, 0ul };
    auto& no_odd = data.first;
    auto& no_even = data.second;

    // For loop
    for (auto i = lo; i < hi; ++i) {
        if (i % 2 == 0)
            no_even++;
        else
            no_odd++;
    }

    // Return result
    return data;
}
