#include "header.h"
#include <numbers>

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

// Comparison

//less if Object 1 < Object 2
//greater if Object 1 > Object 2
//equivalent if Object 1 == Object 2
std::weak_ordering compareArea(Shape const& shape_one, Shape const& shape_two)
{
	if (shape_one.area() == shape_two.area())
	{
		return std::weak_ordering::equivalent;

	}
	else if (shape_one.area() < shape_two.area())
	{
		return std::weak_ordering::less;
	}
	else
	{
		return std::weak_ordering::greater;
	}
}
std::weak_ordering comparePerimeter(Shape const& shape_one, Shape const& shape_two)
{
	if (shape_one.perimeter() == shape_two.perimeter())
	{
		return std::weak_ordering::equivalent;
		
	}
	else if (shape_one.perimeter() < shape_two.perimeter())
	{
		return std::weak_ordering::less;
	}
	else
	{
		return std::weak_ordering::greater;
	}
}