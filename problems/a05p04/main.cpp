// Include needed standard library functions (STL)
#include <array>
#include <string>
#include <memory>
#include <iterator>
#include <iostream>
#include <iomanip>

// The <signature> function  declaration
// The <signature> function  declaration
struct Item {
    std::string name;
    double      price = 0.0;

    friend inline std::istream& operator>>(std::istream& stream, Item& item)
    {
        stream >> item.name >> item.price;
        return stream;
    }
    friend inline std::ostream& operator<<(std::ostream& stream, Item const& item)
    {
        stream << item.name << ' ' << item.price;
        return stream;
    }
};

template <typename Value_T>
class TinyForwardList {
public:
    // STL compatible types
    using value_type = Value_T;
    using size_type = size_t;

    static constexpr size_type capacity = 4ul;
    using ValueArray = std::array<value_type, capacity>;

    // TinyForwardList internals
private:
    struct Node {
        Node* next{ nullptr };
        value_type value;
    };

    using NodePtr = std::unique_ptr<Node>;
    using NodeArray = std::array<NodePtr, capacity>;
    NodeArray m_nodes;

    // TinyForwardList public API
public:
    TinyForwardList(ValueArray const& values);

    // Iterator
    friend class MinimalIterator;
    class MinimalIterator {
        Node* m_current_node{ nullptr };

    public:
        MinimalIterator() noexcept;
        MinimalIterator(Node* node) noexcept;

        MinimalIterator& operator++() noexcept;
        bool             operator!=(MinimalIterator const& other) const noexcept;
        value_type       operator*() const noexcept;
    };


    MinimalIterator begin() const { return MinimalIterator(m_nodes[0].get()); }
    MinimalIterator end() const { return MinimalIterator(); }
};

template <typename Value_T>
inline TinyForwardList<Value_T>::TinyForwardList(
    TinyForwardList<Value_T>::ValueArray const& values)
{
    m_nodes[capacity - 1ul]
        = std::make_unique<Node>(nullptr, values[capacity - 1ul]);

    // Reverse indexing
    for (auto i = 1ul; i < capacity; ++i) {
        auto const  prev_idx = capacity - i;
        auto const  curr_idx = capacity - i - 1ul;
        auto const& value = values[curr_idx];
        auto* prev_node = m_nodes[prev_idx].get();
        m_nodes[curr_idx] = std::make_unique<Node>(prev_node, value);
    }
}

namespace detail {

    template <typename ForwardList_T>
    void printToStdOut(ForwardList_T const& list)
    {
        for (auto itr = list.begin(); itr != list.end(); ++itr) {
            auto const value = *itr;
            std::cout << "value: " << value << '\n';
        }
    }

    template <typename Value_T>
    TinyForwardList<Value_T> loadData()
    {
        using List = TinyForwardList<Value_T>;
        using ValueArray = List::ValueArray;

        // read entry
        ValueArray in_data;
        for (auto i = 0ul; i < List::capacity; ++i)
            std::cin >> in_data[i];

        return in_data;
    }
}   // namespace detail


template <typename Value_T>
TinyForwardList<Value_T>::MinimalIterator::MinimalIterator() noexcept //Default constructor : used to make the end iterator.
{

}

template <typename Value_T>
TinyForwardList<Value_T>::MinimalIterator::MinimalIterator( //Constructor specifying a node: used to make the begin iterator.
    TinyForwardList<Value_T>::Node* node) noexcept
{
    m_current_node= node;
}

template <typename Value_T>
TinyForwardList<Value_T>::MinimalIterator&
TinyForwardList<Value_T>::MinimalIterator::operator++() noexcept //Pre incremental operator (operator++) : used for the act of iterating one forward.
{
    if(m_current_node)
    { 
        m_current_node = m_current_node->next;
    }
    return *this;
}

template <typename Value_T>
bool TinyForwardList<Value_T>::MinimalIterator::operator!=(  //The not equals operator: used for comparing objects by most algorithms.
    const MinimalIterator& other) const noexcept
{
    return other.m_current_node != m_current_node;
}

template <typename Value_T>
TinyForwardList<Value_T>::value_type
TinyForwardList<Value_T>::MinimalIterator::operator*() const noexcept //Dereference operator: used for accessing the internal element value.
{
    return m_current_node->value;
}


/********
 * main *
 ********/

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int         N;
    std::cin >> N;

    for (auto i = 0ul; i < N; ++i) {

        // Read value type
        std::string type;
        std::cin >> type;

        if (type == "int") {
            auto const forward_list = detail::loadData<int>();
            detail::printToStdOut(forward_list);
        }
        else if (type == "double") {
            auto const forward_list = detail::loadData<double>();
            detail::printToStdOut(forward_list);
        }
        else if (type == "item") {
            auto const forward_list = detail::loadData<Item>();
            detail::printToStdOut(forward_list);
        }

    }

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
