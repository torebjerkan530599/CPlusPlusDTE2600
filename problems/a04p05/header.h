#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <memory>

// Container with internal unique pointer storage
class Container {
	size_t                  m_size{ 0 };
	std::unique_ptr<char[]> m_data{ nullptr };

public:
	Container(std::string const& data);
	~Container() = default;

	Container(Container const& other);   // copy constructor
	Container(Container&& other) noexcept;        // move constructor

	Container& operator=(Container const& other);   // copy constructor
	Container& operator=(Container&& other) noexcept;        // move constructor

	std::string toString() const;
};

#endif // HEADER_H