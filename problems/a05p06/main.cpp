// Include needed standard library functions
#include <iostream>
#include <iomanip>

// Type-erased Generic Functor
template <typename = void>
struct Less {

    template <typename Type_T>
    bool operator()(Type_T const& obja, Type_T const& objb) const;

};

// Some Item
struct Item {
    std::string name;
    int         price = 0;

    bool               operator==(Item const& other) const = default;
    std::weak_ordering operator<=>(Item const& other) const;

    friend inline std::istream& operator>>(std::istream& stream, Item& item)
    {
        std::cin >> item.name >> item.price;
        return stream;
    }
};


std::weak_ordering Item::operator<=>(Item const& other) const
{
    // Complete the code comparator
    // Compare by price, then name

    if(price < other.price)
        return std::weak_ordering::less;

    if (price > other.price)
        return std::weak_ordering::greater;

    if(name < other.name)
        return std::weak_ordering::less;

    if (name > other.name)
        return std::weak_ordering::greater;

    return std::weak_ordering::equivalent;
    
}

template <>
template <typename Type_T>
bool Less<>::operator()(Type_T const& obja, Type_T const& objb) const
{
    // Complete the generic functor function-call operator
    // Implement the comparator

    return obja < objb;

    if (obja < objb)
    {
        return true;
    }
    else
    {
        return false;
    }

}


/********
 * main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    // Instantiate a type-erased Functor object
    auto const Fo = Less<>{};

    // Instantiate a lambda expression version of a greater functor
    auto const La = [](auto const& obja, auto const& objb)
    {
        return obja > objb;

        if (obja > objb)
            return true;
        else
            return false;

    };

    // Load the number of tests
    int N;
    std::cin >> N;

    for (auto i = 0; i < N; ++i) {

        // Read the tests value type
        std::string type;
        std::cin >> type;

        // int
        if (type == "int") {
            int value_a, value_b;
            std::cin >> value_a >> value_b;

            std::cout << Fo(value_a, value_b) << ' ';
            std::cout << La(value_a, value_b) << '\n';
        }
        // item
        else if (type == "item") {
            Item value_a, value_b;
            std::cin >> value_a >> value_b;

            std::cout << Fo(value_a, value_b) << ' ';
            std::cout << La(value_a, value_b) << '\n';
        }

    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
