#include "header.h"
#include <iostream>
#include <numbers>

// Include needed standard library functions (STL)
using namespace std;
// The <signature> function definition
void nameMeEspenAskeladd(std::string& name) {
	name = "Espen Askeladd";
}

int lengthOfName(std::string const& name) {
	return name.length();
}

int sumTheFactors(int a, int b) {
	return a + b;
}

std::pair<double, double> computeTheCircleCircumferenceAndArea(double radius) {
	double circumference = 2 * radius * numbers::pi;
	double area = radius * radius * numbers::pi; 
	return std::make_pair(circumference, area);
}
