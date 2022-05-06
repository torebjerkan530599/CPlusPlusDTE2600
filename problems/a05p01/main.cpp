// Include needed standard library functions
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Types
struct Item {
    std::string name;
    double      price;

    friend std::ostream& operator<<(std::ostream& stream, Item const& item);
};

using IntVector = std::vector<int>;
using DoubleVector = std::vector<double>;
using ItemVector = std::vector<Item>;

// Some convenience details
namespace detail
{
    void loadData(IntVector& ints, DoubleVector& doubles, ItemVector& items)
    {
        int         N;
        std::string type;

        int         in_int;
        double      in_double;
        std::string in_item_name;
        double      in_item_price;

        std::cin >> N;
        for (auto i = 0; i < N; ++i) {

            // read entry type
            std::cin >> type;
            if (type == "int") {
                std::cin >> in_int;
                ints.emplace_back(in_int);
            }
            else if (type == "double") {
                std::cin >> in_double;
                doubles.emplace_back(in_double);
            }
            else if (type == "item") {
                std::cin >> in_item_name >> in_item_price;
                items.emplace_back(in_item_name, in_item_price);
            }
        }
    }

}   // namespace detail


// Item output operator
std::ostream& operator<<(std::ostream& stream, Item const& item)
{
    // Complete the output operator
    // Output as follows:
    // [item] : [PRICE.XX]
    stream << item.name << " : " << item.price;

    //static_assert(false, "complete the code");

    return stream;
}

// Generic method for writing std::vector values to std out
template <typename Element_T>
void writeToStdOut(std::vector<Element_T> const& elements)
{
    // Complete the method:
    // Print each element to standard out and on separate lines.
    // Use the elements individual stream << operator.
    for (auto item : elements)
    {
        std::cout << item << "\n";
    }
    
    //static_assert(false, "complete the code");
}

template <>
void writeToStdOut(std::vector<double> const& elements)
{
    // Complete the method:
    // Print each double element to standard out and on separate lines.
    // Format the output using
    // std::fixed, std::showpoint and std::precision
    // on the format
    // [price.XX]

    for (auto item : elements)
    { 
        std::cout << std::fixed << std::showpoint << std::setprecision(2) << item << "\n";
    }

    /*static_assert(false, "complete the code");*/
}


/********
 * main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{

    // Data lists
    std::vector<int>    ints;
    std::vector<double> doubles;
    std::vector<Item>   items;

    // Load test data
    detail::loadData(ints, doubles, items);

    // Do stuff to ints
    writeToStdOut(ints);
    // Do stuff to doubles
    writeToStdOut(doubles);
    // Do stuff to items
    writeToStdOut(items);

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}