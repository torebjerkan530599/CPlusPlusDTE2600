// Include needed standard library functions
#include <iostream>
#include <vector>

#include <ranges>
#include <algorithm>
#include <string>
#include <iterator>
#include <numeric>


/************************************
 * Types, declarations and prototypes
 */

namespace sr = std::ranges;
namespace sv = std::views;

void printReverseFrom(std::ostream& stream, std::vector<int> const& numbers,
    size_t I);


/******
 * Main
 */

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    // Read N
    int N;
    std::cin >> N;

    // Read I
    int I;
    std::cin >> I;

    // Compute Fibionacchi
    std::vector<int> fib(N);
    fib[0] = 0;
    fib[1] = 1;
    std::adjacent_difference(std::begin(fib) + 1, std::prev(std::end(fib)),
        std::next(std::begin(fib) + 1), std::plus<>{});

    // Print fib to standard out
    std::cout << "Sequence ";
    sr::copy(fib, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::cout << "Reverse ";
    sr::reverse_copy(fib, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::cout << "Reverse (from " << I << ") ";
    sr::reverse_copy(std::cbegin(fib), std::cbegin(fib)+I+1, std::ostream_iterator<int>(std::cout, " "));
    //printReverseFrom(std::cout, fib, size_t(I));
    std::cout << '\n';

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}


/*****************
 * Implementations
 */

void printReverseFrom(std::ostream& stream, std::vector<int> const& numbers,
    size_t I)
{
    for (auto i = numbers.cbegin() + I; i >= std::cbegin(numbers); --i)
    {
        stream << *i << " ";
        if (*i == 0)
            break;
    }

    auto print = [&stream](const auto& n) { stream << ' ' << n; };
    sr::for_each(numbers.rbegin(), numbers.rend() , print);
}