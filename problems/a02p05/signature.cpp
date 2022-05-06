#include "header.h"
#include <cmath>

// Compute the sum of the four floating-point numbers and return the result.
double sum(double a, double b, double c, double d) 
{
	return a + b + c + d;
}

//Compute the product of the six integral numbers and return the result.
int prod(int a, int b, int c, int d, int e, int f) 
{
	return a * b * c * d * e * f;
}

//Divide the floating-point numerator by the floating-point denominator and return the result.
double divByReal(double numerator, double denominator) 
{
	return numerator / denominator;
}

//Divide the floating-point numerator by the integeral denominator and return the result.
int divByInt(double numerator, int denominator)
{
	return numerator / denominator;
}

//Divide the floating-point numerator by the integeral denominator and return the reminder of the operation.
int divByIntRem(double numerator, int denominator)
{
	return std::fmod(numerator, denominator);
}