#include "header.h"
#include <iostream>
#include <string>

// Container with internal raw pointer storage
ContainerPtr::ContainerPtr(std::string const& data)
{
	m_size = data.length();
	m_data = new char[m_size];

	for (int i = 0; i < int(m_size); i++)
	{
		m_data[i] = data[i];
		//std::cout << m_data[i];
	}

}
ContainerPtr::ContainerPtr(std::initializer_list<char> data) 
{
	m_size = data.size();
	m_data = new char[m_size];
	int count{0};
	
	for (auto element : data)
	{
		m_data[count] = element;
		++count;
	}
	
}
ContainerPtr::~ContainerPtr()
{
	delete m_data;
}

size_t      ContainerPtr::size() const
{
	return m_size;
}
std::string ContainerPtr::toString() const
{
	int size = int(m_size);
	std::string s = "";
	for (int i = 0; i < size; i++) {
		s = s + m_data[i];
	}
	return s;
}

// Container with internal unique pointer storage
ContainerUnique::ContainerUnique(std::string const& data)
{

	m_size = data.length();
	m_data = std::make_unique<char[]>(m_size);

	int count = 0;
	for (auto element : data)
	{
		m_data[count] = element;
		count++;
	}
}
ContainerUnique::ContainerUnique(std::initializer_list<char> data)
{
	m_size = data.size();
	m_data = std::make_unique<char[]>(m_size);
	auto it = data.begin();

	for (int i = 0; it != data.end(); i++)
	{
		m_data[i] = *it;
		++it;
	}
}
ContainerUnique::~ContainerUnique()
{
	m_data.reset();
}

size_t      ContainerUnique::size() const
{
	return m_size;
}
std::string ContainerUnique::toString() const
{
	int size = int(m_size);
	std::string s = "";
	for (int i = 0; i < size; i++) {
		s = s + m_data[i];
	}
	return s;
}

// Container with internal shared pointer storage
ContainerShared::ContainerShared(std::string const& data)
{
	m_size = data.length();
	m_data = std::shared_ptr<char[]>(new char[m_size]);

	int count = 0;
	for (auto element : data)
	{
		m_data[count] = element;
		count++;
	}
}
ContainerShared::ContainerShared(std::initializer_list<char> data)
{
	m_size = data.size();
	m_data = std::shared_ptr<char[]>(new char[m_size]);
	auto it = data.begin();

	for (int i = 0; it != data.end(); i++)
	{
		m_data[i] = *it;
		++it;
	}
}
ContainerShared::~ContainerShared()
{
	m_data.reset();
}

size_t ContainerShared::size() const
{
	return m_size;
}
std::string ContainerShared::toString() const
{
	int size = int(m_size);
	std::string s = "";
	for (int i = 0; i < size; i++) {
		s = s + m_data[i];
	}
	return s;
}
std::weak_ptr<char[]> ContainerShared::data() const
{
	std::weak_ptr wp = std::shared_ptr<char[]>(m_data);
	
	return wp;
}

// Utility
std::string toString(std::weak_ptr<char[]> data, size_t size)
{
	std::shared_ptr<char[]> sp = std::shared_ptr<char[]>(data);
	int length = int(size);
	std::string s = "";
	for (int i = 0; i < length; i++) {
		s = s + sp[i];
	}
	return s;
}