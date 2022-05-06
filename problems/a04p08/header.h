#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <vector>
#include <istream>
#include <ostream>

// The <signature> function  declaration
class IntVector {
public:
	using SV1D = std::vector<int>;
	IntVector(SV1D const& data1d);

	SV1D const& data() const;

	friend std::istream& operator>>(std::istream& stream, IntVector& vec);
	friend std::ostream& operator<<(std::ostream& stream, IntVector const& vec);

private:
	SV1D m_data;
};

std::istream& operator>>(std::istream& stream, IntVector& vec);
std::ostream& operator<<(std::ostream& stream, IntVector const& vec);


class IntMatrix {
public:
	using SV2D = std::vector<std::vector<int>>;
	IntMatrix(SV2D const& data2d);

	SV2D const& data() const;

	friend std::istream& operator>>(std::istream& stream, IntMatrix& mat);
	friend std::ostream& operator<<(std::ostream& stream, IntMatrix const& mat);

private:
	SV2D m_data;
};

std::istream& operator>>(std::istream& stream, IntMatrix& mat);
std::ostream& operator<<(std::ostream& stream, IntMatrix const& mat);

#endif // HEADER_H
