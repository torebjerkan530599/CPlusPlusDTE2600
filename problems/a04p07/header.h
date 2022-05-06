#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <bitset>
#include <compare>


// The <signature>  declaration
class BitsetInt8 {
	std::bitset<8> m_brep;

public:
	BitsetInt8(int number);
	int toInt() const;

	// Comparison operators
	bool operator==(BitsetInt8 const& other) const;
	bool operator!=(BitsetInt8 const& other) const;
	bool operator<(BitsetInt8 const& other) const;
	bool operator<=(BitsetInt8 const& other) const;
	bool operator>(BitsetInt8 const& other) const;
	bool operator>=(BitsetInt8 const& other) const;


	bool operator==(int other) const;
	bool operator!=(int other) const;
	bool operator<(int other) const;
	bool operator<=(int other) const;
	bool operator>(int other) const;
	bool operator>=(int other) const;
};

class BitsetInt16 {
	std::bitset<16> m_brep;

public:
	BitsetInt16(int number);
	int toInt() const;

	// Comparison operators
	bool               operator==(BitsetInt16 const& other) const;
	std::weak_ordering operator<=>(BitsetInt16 const& other) const;

	bool               operator==(int other) const;
	std::weak_ordering operator<=>(int other) const;
};

#endif // HEADER_H
