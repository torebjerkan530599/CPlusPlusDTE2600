#include "header.h"
#include <numbers>
#include <sstream>
#include <iomanip>

// Classes
Circle::Circle(double radius)
{
	m_radius = radius;
}
double Circle::area() const
{
	return std::numbers::pi * m_radius * m_radius;
}
double Circle::perimeter() const
{
	return std::numbers::pi * m_radius * 2.0;
}

Rectangle::Rectangle(double width, double height)
{
	m_width = width;
	m_height = height;
}
double Rectangle::area() const
{
	return m_width * m_height;
}
double Rectangle::perimeter() const
{
	return m_width * 2.0 + m_height * 2.0;
}

Square::Square(double side_length)
	:
	Rectangle(side_length, side_length)
{

}

Triangle::Triangle(double width, double height)
{
	m_width = width;
	m_height = height;
}
double Triangle::area() const
{
	return m_width * m_height / 2.0;
}
double Triangle::perimeter() const
{
	return m_width * 3.0;
}

std::string pickShape(std::stringstream& s_area, std::stringstream& s_peri, Shape const& shape)
{
	try
	{
		//const Triangle& triangle =  dynamic_cast<Triangle const&>(shape);
		s_area << dynamic_cast<Triangle const&>(shape).area();
		s_peri << dynamic_cast<Triangle const&>(shape).perimeter();
		return "Type: Triangle - Area: " + s_area.str() + " - Perimeter: " + s_peri.str();
	}
	catch (std::out_of_range&)
	{

	}

	try
	{
		s_area << dynamic_cast<Square const&>(shape).area();
		s_peri << dynamic_cast<Square const&>(shape).perimeter();
		return "Type: Square - Area: " + s_area.str() + " - Perimeter: " + s_peri.str();
	}
	catch (std::out_of_range&)
	{

	}

	try
	{
		s_area << dynamic_cast<Rectangle const&>(shape).area();
		s_peri << dynamic_cast<Rectangle const&>(shape).perimeter();
		return "Type: Rectangle - Area: " + s_area.str() + " - Perimeter: " + s_peri.str();
	}
	catch (std::out_of_range&)
	{

	}

	try
	{
		//const Triangle& triangle =  dynamic_cast<Triangle const&>(shape);
		s_area << dynamic_cast<Circle const&>(shape).area();
		s_peri << dynamic_cast<Circle const&>(shape).perimeter();
		return "Type: Circle - Area: " + s_area.str() + " - Perimeter: " + s_peri.str();
	}
	catch (std::out_of_range&)
	{


	}

	return "";
}



std::string toString(Shape const& shape)
{
	std::stringstream s_area;
	std::stringstream s_peri;


	s_area << std::showpoint << std::fixed << std::setprecision(2);
	s_peri << std::showpoint << std::fixed << std::setprecision(2);

	return pickShape(s_area, s_peri, shape);
}

std::weak_ordering compareAreaAndPerimeter(Shape const& shape_one, Shape const& shape_two)
{
	if (shape_one.area() < shape_two.area())
	{
		return std::weak_ordering::less;
	}

	if (shape_one.area() > shape_two.area())
	{
		return std::weak_ordering::greater;
	}
	
	if (shape_one.perimeter() < shape_two.perimeter())
	{
		return std::weak_ordering::less;
	}

	if (shape_one.perimeter() > shape_two.perimeter())
	{
		return std::weak_ordering::greater;
	}

	if (shape_one.area() == shape_two.area())
	{
		return std::weak_ordering::equivalent;
	}
}

