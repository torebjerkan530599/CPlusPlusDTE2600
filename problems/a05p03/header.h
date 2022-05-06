#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <array>
#include <string>
#include <memory>
#include <iterator>
#include <iostream>

// The <signature> function  declaration
struct Name {
    std::string first;
    std::string last;

    friend inline std::istream& operator>>(std::istream& stream, Name& name)
    {
        stream >> name.first >> name.last;
        return stream;
    }
    friend inline std::ostream& operator<<(std::ostream& stream, Name const& name)
    {
        stream << name.first << ' ' << name.last;
        return stream;
    }
};


class TinyForwardList 
{
    public:
        static constexpr size_t capacity = 4ul;
        using NamesArray = std::array<Name, capacity>;

        // TinyForwardList internals
    private:
    
        struct Node 
        {
            Node* next{ nullptr };
            Name  value;
        };

        using NodePtr = std::unique_ptr<Node>;
        using NodeArray = std::array<NodePtr, capacity>;
        NodeArray m_nodes;

    // TinyForwardList public API
    public:
    
        TinyForwardList(NamesArray const& names);

    // Iterator
    friend class MinimalIterator;
    class MinimalIterator 
    {
        Node* m_current_node{ nullptr };

    public:
        MinimalIterator() noexcept;
        MinimalIterator(Node* node) noexcept;

        MinimalIterator& operator++() noexcept;
        bool             operator!=(MinimalIterator const& other) const noexcept;
        Name             operator*() const noexcept;
    };


        MinimalIterator begin() { return MinimalIterator(m_nodes[0].get()); }
        MinimalIterator end() { return MinimalIterator(); }
};

inline TinyForwardList::TinyForwardList(TinyForwardList::NamesArray const& names)
{
    m_nodes[capacity - 1ul]
        = std::make_unique<Node>(nullptr, names[capacity - 1ul]);

    // Reverse indexing
    for (auto i = 1ul; i < capacity; ++i) {
        auto const  prev_idx = capacity - i;
        auto const  curr_idx = capacity - i - 1ul;
        auto const& name = names[curr_idx];
        auto* prev_node = m_nodes[prev_idx].get();
        m_nodes[curr_idx] = std::make_unique<Node>(prev_node, name);
    }
}

template <typename Iterator_T, typename Sentinel_T>
void printToStdOut(Iterator_T begin, Sentinel_T end)
{
    for (auto itr = begin; itr != end; ++itr) {
        auto const name = *itr;
        std::cout << "name: " << name.first << ' ' << name.last << '\n';
    }
}

#endif // HEADER_H
