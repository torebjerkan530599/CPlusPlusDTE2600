#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <initializer_list>
#include <memory>

// Container with internal raw pointer storage
class ContainerPtr {
	size_t m_size;
	char* m_data;

public:
	ContainerPtr(std::string const& data);
	ContainerPtr(std::initializer_list<char> data);
	~ContainerPtr();

	size_t      size() const;
	std::string toString() const;
};

// Container with internal unique pointer storage
class ContainerUnique {
	size_t                  m_size;
	std::unique_ptr<char[]> m_data;

public:
	ContainerUnique(std::string const& data);
	ContainerUnique(std::initializer_list<char> data);
	~ContainerUnique();

	size_t      size() const;
	std::string toString() const;
};

// Container with internal shared pointer storage
class ContainerShared {
	size_t                  m_size;
	std::shared_ptr<char[]> m_data;

public:
	ContainerShared(std::string const& data);
	ContainerShared(std::initializer_list<char> data);
	~ContainerShared();

	size_t                size() const;
	std::string           toString() const;
	std::weak_ptr<char[]> data() const;
};

std::string toString(std::weak_ptr<char[]> data, size_t size);

#endif // HEADER_H