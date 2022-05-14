#include "header.h"
#include <cmath>  

std::optional<unsigned> leftShift(unsigned number, unsigned shift) noexcept
{

	if(shift >= sizeof(unsigned) * 8)
		return std::nullopt;

	return { number << shift }; //debugged, changed to left
	

}

//unsigned test = number * pow(2, shift);// % (UINT_MAX + 1);
	//auto res = test % (UINT_MAX);
// return res; 	//https://pvs-studio.com/en/blog/posts/cpp/0142/

//
//Important Points :
//
//The left shiftand right shift operators should not be used for negative numbers.The result of is undefined behaviour if any of the operands is a negative number.For example results of both 1 >> -1 and 1 << -1 is undefined.
//If the number is shifted more than the size of integer, the behaviour is undefined.For example, 1 << 33 is undefined if integers are stored using 32 bits.For bit shift of larger values 1ULL << 62  ULL is used for Unsigned Long Long which is defined using 64 bits which can store large values.
//The left - shift by 1 and right - shift by 1 are equivalent to the product of first term and 2 to the power given element(1 << 3 = 1 * pow(2, 3)) and division of first term and second term raised to power 2 (1 >> 3 = 1 / pow(2, 3)) respectively.
//As mentioned in point 1, it works only if numbers are positive.

//return number * pow(2,shift);

//
//if (number < 0 || shift < 0 || shift >= number || unsigned < shift) //avoid undefined behavior
//	return std::nullopt;