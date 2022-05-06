#include "header.h"
#include <iostream>

// BitsetInt8
BitsetInt8::BitsetInt8(int number)
{
	m_brep= std::bitset<8>(number);

}
int BitsetInt8::toInt() const
{
	std::string s  = m_brep.to_string();
	std::string k(s.rbegin(), s.rend());
	std::bitset<8>reverse_set(k);       
	
	int num = 0;

	for (size_t i = 0; i < m_brep.size(); i++)
	{
		num <<= 1;
		num |= reverse_set[i];
	}

	return num;

	//return static_cast<int>(m_brep.to_ulong());

}

// Comparison operators
bool BitsetInt8::operator==(BitsetInt8 const& other) const
{
	return toInt() == other.toInt();

}
bool BitsetInt8::operator!=(BitsetInt8 const& other) const
{
	return toInt() != other.toInt();
}
bool BitsetInt8::operator<(BitsetInt8 const& other) const
{
	
	return toInt() < other.toInt();

}
bool BitsetInt8::operator<=(BitsetInt8 const& other) const
{
	return toInt() <= other.toInt();

}
bool BitsetInt8::operator>(BitsetInt8 const& other) const
{

	return toInt() > other.toInt();
}
bool BitsetInt8::operator>=(BitsetInt8 const& other) const
{
	return toInt() >= other.toInt();

}

bool BitsetInt8::operator==(int other) const
{
	return (int)(m_brep.to_ulong()) == other;
}
bool BitsetInt8::operator!=(int other) const
{
	return (int)(m_brep.to_ulong()) != other;
}
bool BitsetInt8::operator<(int other) const
{
	return (int)(m_brep.to_ulong()) < other;
}
bool BitsetInt8::operator<=(int other) const
{
	return (int)(m_brep.to_ulong()) <= other;
}
bool BitsetInt8::operator>(int other) const
{
	return (int)(m_brep.to_ulong()) > other;
}
bool BitsetInt8::operator>=(int other) const
{
	return (int)(m_brep.to_ulong()) >= other;
}


// BitsetInt16
BitsetInt16::BitsetInt16(int number)
{
	m_brep = std::bitset<16>(number);
}
int BitsetInt16::toInt() const
{
	return static_cast<int>(m_brep.to_ulong());
}

// Comparison operators
bool BitsetInt16::operator==(BitsetInt16 const& other) const
{
	return m_brep == other.m_brep;
}

std::weak_ordering BitsetInt16::operator<=>(BitsetInt16 const& other) const
{
	if(toInt() < other.toInt())
	{ 
		return std::weak_ordering::less;
	}
	if (toInt() > other.toInt())
	{ 
		return std::weak_ordering::greater;
	}
	
	if(toInt() == other.toInt())
	{ 
		return std::weak_ordering::equivalent;
	}
}

bool BitsetInt16::operator==(int other) const
{
	return toInt() == other;
}
std::weak_ordering BitsetInt16::operator<=>(int other) const
{
	if(toInt() < other)
	{ 
		return std::weak_ordering::less;
	}

	if (toInt() > other)
	{
		return std::weak_ordering::greater;
	}
	
	if (toInt() == other)
	{
		return std::weak_ordering::equivalent;
	}
}
