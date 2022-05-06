#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <memory>

// "Rule of Three" Wrapper
class HeapAllocatedInt {
	int* m_int{ nullptr };

public:
	HeapAllocatedInt(int p_int);

	// "Rule of three"
	~HeapAllocatedInt();
	HeapAllocatedInt(HeapAllocatedInt const& other);
	HeapAllocatedInt& operator=(HeapAllocatedInt const& other);

	// Members
	int value() const;
};


// "Rule of Five" Wrapper
class MovableHeapAllocatedInt {
	int* m_int{ nullptr };

public:
	MovableHeapAllocatedInt(int p_int);

	// "Rule of Five"
	~MovableHeapAllocatedInt();
	MovableHeapAllocatedInt(MovableHeapAllocatedInt const& other);
	MovableHeapAllocatedInt(MovableHeapAllocatedInt&& other) noexcept;
	MovableHeapAllocatedInt& operator=(MovableHeapAllocatedInt const& other);
	MovableHeapAllocatedInt& operator=(MovableHeapAllocatedInt&& other) noexcept;

	// Members
	int value() const;
};


// "Rule of Zero" Wrapper
class StringableInt {
	int m_int;

public:
	StringableInt(int p_int);
	std::string toString() const;
};

#endif // HEADER_H
