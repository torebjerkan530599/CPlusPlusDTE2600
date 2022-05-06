#include "header.h"

// "Rule of Three" Wrapper
HeapAllocatedInt::HeapAllocatedInt(int p_int)
{
	m_int = new int(p_int);
}

// "Rule of three"
HeapAllocatedInt::~HeapAllocatedInt()
{
	delete m_int; //delete pointer
}

HeapAllocatedInt::HeapAllocatedInt(HeapAllocatedInt const& other)
{
	if (this != &other)
	{
		delete m_int;
		m_int = other.m_int;
	}
} //copy constructor

HeapAllocatedInt& HeapAllocatedInt::operator=(HeapAllocatedInt const& other)
{
	if (this != &other)
	{
		delete m_int;
		m_int = other.m_int;
	}
	return *this;

} //copy assign constructor

// Members
int HeapAllocatedInt::value() const
{
	return *m_int;

}


// "Rule of Five" Wrapper
MovableHeapAllocatedInt::MovableHeapAllocatedInt(int p_int)
{
	m_int = new int(p_int);
}

// "Rule of Five"
MovableHeapAllocatedInt::~MovableHeapAllocatedInt()
{
	delete m_int;
}
MovableHeapAllocatedInt::MovableHeapAllocatedInt(MovableHeapAllocatedInt const& other)
{
	if (this != &other)
	{
		delete m_int;
		m_int = other.m_int;
	}
}
MovableHeapAllocatedInt::MovableHeapAllocatedInt(MovableHeapAllocatedInt&& other) noexcept
{
	if (this != &other)
	{
		delete m_int;
		m_int = std::move(other.m_int);
		other.m_int = nullptr;
	}
}
MovableHeapAllocatedInt& MovableHeapAllocatedInt::operator=(MovableHeapAllocatedInt const& other)
{
	if (this != &other)
	{
		delete m_int;
		m_int = other.m_int;
	}
	return *this;
}
MovableHeapAllocatedInt& MovableHeapAllocatedInt::operator=(MovableHeapAllocatedInt&& other) noexcept
{
	if (this != &other)
	{
		delete m_int;
		m_int = std::move(other.m_int);
		other.m_int = nullptr;
	}
	return *this;
}

// "Rule of Five" Wrapper Members
int MovableHeapAllocatedInt::value() const
{
	return *m_int;
}


// "Rule of Zero" Wrapper
StringableInt::StringableInt(int p_int)
{
	m_int = p_int;
}

//spesifisert i signature.cpp på nett, men virker ikke
//std::string StringableInttoString() const
//{
//	return std::to_string(m_int);
//}

//virker
std::string StringableInt::toString() const
{
	return std::to_string(m_int);
}