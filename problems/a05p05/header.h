#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>

// The <signature> function  declaration
struct Less {
	bool operator()(int a, int b) const;
};

struct Greater {
	bool operator()(int a, int b) const;
};

struct PowLessEq {
	int  m_exp;
	bool operator()(int a, int b) const;
};

struct CountSmallAs {
	size_t operator()(std::string const& str) const;
};

#endif // HEADER_H
