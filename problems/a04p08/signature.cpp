#include "header.h"

// Vector class
IntVector::IntVector(IntVector::SV1D const& data1d)
{
	for (auto& elem : data1d)
	{
		m_data.push_back(elem);
	}
}
IntVector::SV1D const& IntVector::data() const
{
	return m_data;
}

// Matrix class
IntMatrix::IntMatrix(IntMatrix::SV2D const& data2d)
{
	std::copy(data2d.begin(), data2d.end(), back_inserter(m_data));
}
IntMatrix::SV2D const& IntMatrix::data() const
{
	return m_data;
}

// Stream operators
std::istream& operator>>(std::istream& stream, IntVector& vec) //cin op.
{
	size_t numberOfElements;

	stream >> numberOfElements;

	vec.m_data.resize(numberOfElements);

	for (size_t i = 0; i < numberOfElements; i++)
	{
		stream >> vec.m_data.at(i);
	}

	return stream;
}
std::ostream& operator<<(std::ostream& stream, IntVector const& vec) //cout op.
{
	stream << vec.m_data.size() << "\n";

	for (size_t i = 0; i < vec.m_data.size(); i++)
	{
		stream << vec.m_data.at(i) << " ";
	}

	return stream;

}
std::istream& operator>>(std::istream& stream, IntMatrix& mat)
{
	size_t row;
	size_t column;

	stream >> row >> column;

	//mat.m_data.resize(row, std::vector<int>(column));
	mat.m_data.resize(row);

	for (size_t x = 0; x < row; x++)
	{
		for (size_t y = 0; y < column; y++)
		{
			mat.m_data[x].resize(column);
			stream >> mat.m_data[x][y];
		}
	}

	return stream;
}
std::ostream& operator<<(std::ostream& stream, IntMatrix const& mat)
{
	size_t rows = mat.m_data.size();
	size_t columns = mat.m_data[0].size(); // [0] virker fordi matrisen har samme ant. elementer i hver kolonne

	stream << rows << " " << columns << "\n";

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			stream << mat.m_data[i][j] << ' ' ;
		}

		stream << "\n";
	}
	return stream;
}
