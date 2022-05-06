// Include needed standard library functions
#include <iostream>
#include <compare>
#include <vector>
#include <algorithm>
#include <concepts>
#include <iomanip>

// Types
struct Item {
    std::string name;
    std::string category;
    int         price;

    bool               operator==(Item const& other) const;
    std::weak_ordering operator<=>(Item const& other) const;

    friend std::istream& operator>>(std::istream& stream, Item& item);
    friend std::ostream& operator<<(std::ostream& stream, Item const& item);
};

template <typename Element_T>
class Vector {

public:
    // STL compatible API
    using value_type = Element_T;

private:
    std::vector<value_type> m_data;
    void append(value_type const& value);

public:
    void loadElementFromStdIn();

    void sort() { std::sort(m_data.begin(), m_data.end()); }
    std::vector<value_type> const& data() const { return m_data; }
};

// Vector class append member-function
template <typename Element_T>
void Vector<Element_T>::append(Element_T const& element)
{
    // Complete the function
    m_data.push_back(element);
}

template <>
void Vector<int>::loadElementFromStdIn()
{
    // Member-Function specialized int example
    int in;
    std::cin >> in;
    append(in);
    // Example END
}

template <>
void Vector<double>::loadElementFromStdIn()
{
    // Complete the function
    double in;
    std::cin >> in;
    append(in);
}

template <>
void Vector<Item>::loadElementFromStdIn()
{
    // Complete the function
    using namespace std;
    Item in;
    cin >> in.name >> in.category >> in.price;
    append(in);
}


using IntVector = Vector<int>;
using DoubleVector = Vector<double>;
using ItemVector = Vector<Item>;


// Some convenience details
namespace detail
{

    void loadData(IntVector& ints, DoubleVector& doubles, ItemVector& items)
    {
        int         N;
        std::string type;

        std::cin >> N;
        for (auto i = 0; i < N; ++i) {

            // read entry type
            std::cin >> type;
            if (type == "int") {
                ints.loadElementFromStdIn();
            }
            else if (type == "double") {
                doubles.loadElementFromStdIn();
            }
            else if (type == "item") {
                items.loadElementFromStdIn();
            }
        }
    }

}   // namespace detail



// Item comparison operators
bool Item::operator==(Item const& other) const
{
    // Complete the operator:
    // compare with respect to price, name and category

    if (price == other.price && name == other.name && category == other.category)
    {
        return true;
    }
    else
    {
        return false;
    }

}

std::weak_ordering Item::operator<=>(Item const& other) const
{
    // Complete the operator:
    // compare with respect to price, then name, and then category

    auto const comp_order = [](auto const& a, auto const& b) {
        if (a == b)
            return std::weak_ordering::equivalent;
        else if (a < b)
            return std::weak_ordering::less;
        else
            return std::weak_ordering::greater;
    };

    // useage example on the order field
    auto price_order = comp_order(price, other.price);
    auto name_order = comp_order(name, other.name);
    auto category_order = comp_order(category, other.category);

    if (price_order == name_order )
    {
        return price_order;
    } 
    else if(name_order == category_order)
    {
        return name_order;
    }
    else 
    { 
        return category_order;
    }
    
    return std::weak_ordering::equivalent;


    // operative code below!
    if (price < other.price)
        return std::weak_ordering::less;

    if (price > other.price)
        return std::weak_ordering::greater;

    if (name < other.name)
        return std::weak_ordering::less;

    if (name > other.name)
        return std::weak_ordering::greater;

    if (category < other.category)
        return std::weak_ordering::less;

    if (category > other.category)
        return std::weak_ordering::greater;

    return std::weak_ordering::equivalent;
  
}

// Item I/O stream operators
std::istream& operator>>(std::istream& stream, Item& item)
{
    // Complete the input stream operator

    stream >> item.name >> item.price >> item.category;

    return stream;
}

std::ostream& operator<<(std::ostream& stream, Item const& item)
{
    // Complete the output stream operator

    stream << item.name <<  '-' << item.category <<  " : " << item.price;

    return stream;
}

// Generic method for writing elements to std out
template <typename Element_T>
void writeToStdOut(Vector<Element_T> const& elements)
{
    // Complete the method:
    // Print each element to standard out and on separate lines.
    // Use the elements individual stream << operator.

    for (auto item : elements.data())
    {
        std::cout << item << "\n";
    }

}

template <>
void writeToStdOut(Vector<double> const& elements)
{
    // Complete the method:
    // Print each double element to standard out and on separate lines.
    // Format the output using
    // std::fixed, std::showpoint and std::precision

    for (auto item : elements.data())
    {
        std::cout << std::fixed << std::showpoint << std::setprecision(2) << item << "\n";
    }
    
}


/********
 * main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    // Data lists
    Vector<int>    ints;
    Vector<double> doubles;
    Vector<Item>   items;

    // Load test data
    detail::loadData(ints, doubles, items);

    // Sort vectors
    ints.sort();
    doubles.sort();
    items.sort();

    // Write ints to standard out
    writeToStdOut(ints);
    // Write doubles to standard out
    writeToStdOut(doubles);
    // Write items to standard out
    writeToStdOut(items);

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
