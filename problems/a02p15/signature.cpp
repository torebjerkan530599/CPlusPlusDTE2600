#include "header.h"

// Include needed standard library functions (STL)
using namespace std;

// The <signature> function definition
optional<char> valueInCharTbl(char const* char_tbl, size_t rows, size_t cols, size_t row_nr, size_t col_nr)
{
	if(row_nr >= rows || col_nr >= cols || char_tbl == nullptr || !char_tbl || !*char_tbl)
		return nullopt;


	/*On how to convert a one - dimensional index to a two - dimensional index for a row - major matrix:

	The row number can be found by integer division, dividing the one - dimensional index by the row length(no.columns).
	The column number is the remainder of the integer division.*/

	//[rad 1[col1, col2, ...]][rad 2[col 1, col 2, ...]][...]

	//a11 a21 a31   a12 a22 a32   a13 a23 a33  //<--- this is the row major 
	//---col 1---   ---col 2---   ---col 3---
	
	const char  c = char_tbl[row_nr * cols + col_nr];

	return c;
}
