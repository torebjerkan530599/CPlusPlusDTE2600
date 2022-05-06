#include "header.h"
#include <sstream>
#include <iomanip>
#include <math.h>

// The <signature> function definition(s)
std::any toAny(std::string const& input)
{
	std::string first_token = input.substr(0, input.find(" "));
	std::string second_token = input.substr(input.find(" ") + 1);

	if (first_token == "int")
	{
		int value = std::stoi(second_token);
		return std::any_cast<int>(value);

	}
	else if (first_token == "double")
	{
		double value = std::stod(second_token);
		return std::any_cast<double>(value);
	}
	else if (first_token == "string")
	{
		return std::any_cast<std::string>(second_token);;
	}
	else if (first_token == "float")
	{
		float value = std::stof(second_token);
		return std::any_cast<float>(value);
	}

	return {};
}
std::variant<float, int> solve(int a) {
	std::stringstream stream;
	float calc = a / 10.0f;

	if (ceilf(calc) == calc)
	{
		return int(calc);
	}
	else
	{
		stream << std::fixed << std::setprecision(1) << calc;
		std::string s = stream.str();
		return stof(s);
	}
}
std::optional<int> division(int a, int b, int c) {

	if (c == 0)
	{
		return std::nullopt;
	}

	int x1 = (a - b) / c;
	int x2 = -((a - b) / c);

	if (x1 != x2)
	{
		return std::max(x1, x2);
	}

	return std::nullopt;
}
std::string toString(std::variant<int, float> const& num, std::optional<int> const& precision)
{
	std::stringstream stream;

	if (std::holds_alternative<int>(num))
	{
		stream << std::showpoint << std::fixed << std::setprecision(*precision) << std::get<int>(num);
	}
	else
	{
		stream << std::showpoint << std::fixed << std::setprecision(*precision) << std::get<float>(num);
	}

	return stream.str();

}