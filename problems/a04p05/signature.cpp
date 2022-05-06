#include "header.h"

// Container with unique_ptr storage
Container::Container(std::string const& data)
{
	m_size = data.length();
	m_data = std::make_unique<char[]>(m_size);

	int num_elem = int(m_size);
	for (int i = 0; i != num_elem; ++i) // copy elements
	{
		m_data[i] = data[i];
	}
}

// Copy & move constructors
Container::Container(Container const& other)
{
	int num_elem = int(other.m_size);

	for (int i = 0; i != num_elem; ++i) // copy elements
	{
		m_data[i] = other.m_data[i];
	}
}   // copy constructor

Container::Container(Container&& other) noexcept
{

	if (this != &other)
	{
		this->m_data.reset();
		this->m_data = std::move(other.m_data);
		m_size = other.m_size;
		other.m_data = nullptr;
		other.m_size = 0;
	}

} // move constructor

// Copy & move assignment operators  
Container& Container::operator=(Container const& other)
{

	if (this != &other)
	{
		m_size = other.m_size;
		m_data.reset(new char[other.m_size]);

		std::copy(&other.m_data[0],
			&other.m_data[0] + m_size,
			&m_data[0]);
	}
	return *this;

}     // copy assign operator
Container& Container::operator=(Container&& other) noexcept
{
	if (this != &other)
	{
		this->m_data.reset();
		this->m_data = std::move(other.m_data);
		m_size = other.m_size;
		other.m_data = nullptr;
		other.m_size = 0;
	}

	return *this;

} // move assign operator

// Member functions
std::string Container::toString() const
{
	int size = int(m_size);
	std::string s = "";
	for (int i = 0; i < size; i++) {
		s = s + m_data[i];
	}
	return s;

}