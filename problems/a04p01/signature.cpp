#include "header.h"
#include <numbers>
#include <sstream>
#include <iomanip>
#include <iostream>
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

//return "Type: [Type] - Area : [AA.XX] - Perimeter : [PP.XX] ";
//std::cout << "Type: " + s + " - Area : " + s_area.str() + " - Perimeter : " + s_peri.str() + " ";

// skrive Circle der det står [Type] i tekst eller skal man programmere sånn at man får ut typen?

//using t = decltype(circle);

// To String
std::string toString(Circle const& circle)
{
	std::stringstream s_area;
	std::stringstream s_peri;

	s_area << std::showpoint << std::fixed << std::setprecision(2) << circle.area();
	s_peri << std::showpoint << std::fixed << std::setprecision(2) << circle.perimeter();

	//"Type: [Type] - Area : [AA.XX] - Perimeter : [PP.XX]";
	return "Type: Circle - Area : " + s_area.str() + " - Perimeter: " + s_peri.str();
}
std::string toString(Rectangle const& rect)
{
	std::stringstream s_area;
	std::stringstream s_peri;

	s_area << std::showpoint << std::fixed << std::setprecision(2) << rect.area();
	s_peri << std::showpoint << std::fixed << std::setprecision(2) << rect.perimeter();

	//"Type: [Type] - Area : [AA.XX] - Perimeter : [PP.XX]";
	return "Type: Rectangle - Area : " + s_area.str() + " - Perimeter: " + s_peri.str();

}
std::string toString(Triangle const& triangle)
{
	std::stringstream s_area;
	std::stringstream s_peri;

	s_area << std::showpoint << std::fixed << std::setprecision(2) << triangle.area();
	s_peri << std::showpoint << std::fixed << std::setprecision(2) << triangle.perimeter();

	//"Type: [Type] - Area : [AA.XX] - Perimeter : [PP.XX]";
	return "Type: Triangle - Area : " + s_area.str() + " - Perimeter: " + s_peri.str();
}

// Comparison
std::weak_ordering compareArea(Circle const& circle1, Circle const& circle2)
{
	/*less if Object 1 < Object 2
	greater if Object 1 > Object 2
	equivalent if Object 1 == Object 2*/

	if (circle1.area() < circle2.area())
	{
		return std::weak_ordering::less;
	}
	else if (circle1.area() > circle2.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (circle1.area() == circle2.area())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering compareArea(Circle const& circle, Rectangle const& rect)
{
	if (circle.area() < rect.area())
	{
		return std::weak_ordering::less;
	}
	else if (circle.area() > rect.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (circle.area() == rect.area())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering compareArea(Circle const& circle, Triangle const& triangle)
{
	if (circle.area() < triangle.area())
	{
		return std::weak_ordering::less;
	}
	else if (circle.area() > triangle.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (circle.area() == triangle.area())
	{
		return std::weak_ordering::equivalent;
	}

}
std::weak_ordering compareArea(Rectangle const& rect1, Rectangle const& rect2)
{
	if (rect1.area() < rect2.area())
	{
		return std::weak_ordering::less;
	}
	else if (rect1.area() > rect2.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (rect1.area() == rect2.area())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering compareArea(Rectangle const& rect, Circle const& circle)
{
	if (rect.area() < circle.area())
	{
		return std::weak_ordering::less;
	}
	else if (rect.area() > circle.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (rect.area() == circle.area())
	{
		return std::weak_ordering::equivalent;
	}

}
std::weak_ordering compareArea(Rectangle const& rect, Triangle const& triangle)
{
	if (rect.area() < triangle.area())
	{
		return std::weak_ordering::less;
	}
	else if (rect.area() > triangle.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (rect.area() == triangle.area())
	{
		return std::weak_ordering::equivalent;
	}


}
std::weak_ordering compareArea(Triangle const& triangle1, Triangle const& triangle2)
{

	if (triangle1.area() < triangle2.area())
	{
		return std::weak_ordering::less;
	}
	else if (triangle1.area() > triangle2.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (triangle1.area() == triangle2.area())
	{
		return std::weak_ordering::equivalent;
	}

}
std::weak_ordering compareArea(Triangle const& triangle, Circle const& circle)
{
	if (triangle.area() < circle.area())
	{
		return std::weak_ordering::less;
	}
	else if (triangle.area() > circle.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (triangle.area() == circle.area())
	{
		return std::weak_ordering::equivalent;
	}

}
std::weak_ordering compareArea(Triangle const& triangle, Rectangle const& rect)
{
	if (triangle.area() < rect.area())
	{
		return std::weak_ordering::less;
	}
	else if (triangle.area() > rect.area())
	{
		return std::weak_ordering::greater;
	}
	else //if (triangle.area() == rect.area())
	{
		return std::weak_ordering::equivalent;
	}

}

std::weak_ordering comparePerimeter(Circle const& circle1, Circle const& circle2)
{
	if (circle1.perimeter() < circle2.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (circle1.perimeter() > circle2.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (circle1.perimeter() == circle2.perimeter())
	{
		return std::weak_ordering::equivalent;
	}

}
std::weak_ordering comparePerimeter(Circle const& circle, Rectangle const& rect)
{

	if (circle.perimeter() < rect.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (circle.perimeter() > rect.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (circle.perimeter() == rect.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering comparePerimeter(Circle const& circle, Triangle const& triangle)
{
	if (circle.perimeter() < triangle.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (circle.perimeter() > triangle.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (circle.perimeter() == triangle.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering comparePerimeter(Rectangle const& rect1, Rectangle const& rect2)
{
	if (rect1.perimeter() < rect2.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (rect1.perimeter() > rect2.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (rect1.perimeter() == rect2.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering comparePerimeter(Rectangle const& rect, Circle const& circle)
{
	if (rect.perimeter() < circle.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (rect.perimeter() > circle.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (rect.perimeter() == circle.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering comparePerimeter(Rectangle const& rect, Triangle const& triangle)
{
	if (rect.perimeter() < triangle.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (rect.perimeter() > triangle.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (rect.perimeter() == triangle.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering comparePerimeter(Triangle const& triangle1, Triangle const& triangle2)
{
	if (triangle1.perimeter() < triangle2.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (triangle1.perimeter() > triangle2.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (triangle1.perimeter() == triangle2.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering comparePerimeter(Triangle const& triangle, Circle const& circle)
{
	if (triangle.perimeter() < circle.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (triangle.perimeter() > circle.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (triangle.perimeter() == circle.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}
std::weak_ordering comparePerimeter(Triangle const& triangle, Rectangle const& rect)
{
	if (triangle.perimeter() < rect.perimeter())
	{
		return std::weak_ordering::less;
	}
	else if (triangle.perimeter() > rect.perimeter())
	{
		return std::weak_ordering::greater;
	}
	else //if (triangle.perimeter() == rect.perimeter())
	{
		return std::weak_ordering::equivalent;
	}
}

std::weak_ordering compareAreaAndPerimeter(Circle const& circle1, Circle const& circle2)
{
	if (circle1.area() < circle2.area())
	{
		if (circle1.perimeter() < circle2.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (circle1.area() > circle2.area())
	{
		if (circle1.perimeter() > circle2.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}

	return std::weak_ordering::equivalent;

}

std::weak_ordering compareAreaAndPerimeter(Circle const& circle, Rectangle const& rect)
{
	if (circle.area() < rect.area())
	{
		if (circle.perimeter() < rect.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (circle.area() > rect.area())
	{
		if (circle.perimeter() > rect.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;

}

std::weak_ordering compareAreaAndPerimeter(Circle const& circle, Triangle const& triangle)
{
	if (circle.area() < triangle.area())
	{
		if (circle.perimeter() < triangle.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (circle.area() > triangle.area())
	{
		if (circle.perimeter() > triangle.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;


}
std::weak_ordering compareAreaAndPerimeter(Rectangle const& rect1, Rectangle const& rect2)
{

	if (rect1.area() < rect2.area())
	{
		if (rect1.perimeter() < rect2.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (rect1.area() > rect2.area())
	{
		if (rect1.perimeter() > rect2.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;
}
std::weak_ordering compareAreaAndPerimeter(Rectangle const& rect, Circle const& circle)
{

	if (rect.area() < circle.area())
	{
		if (rect.perimeter() < circle.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (rect.area() > circle.area())
	{
		if (rect.perimeter() > circle.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;
}
std::weak_ordering compareAreaAndPerimeter(Rectangle const& rect, Triangle const& triangle)
{
	if (rect.area() < triangle.area())
	{
		if (rect.perimeter() < triangle.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (rect.area() > triangle.area())
	{
		if (rect.perimeter() > triangle.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;

}
std::weak_ordering compareAreaAndPerimeter(Triangle const& triangle1, Triangle const& triangle2)
{
	if (triangle1.area() < triangle2.area())
	{
		if (triangle1.perimeter() < triangle2.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (triangle1.area() > triangle2.area())
	{
		if (triangle1.perimeter() > triangle2.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;

}
std::weak_ordering compareAreaAndPerimeter(Triangle const& triangle, Circle const& circle)
{
	if (triangle.area() < circle.area())
	{
		if (triangle.perimeter() < circle.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (triangle.area() > circle.area())
	{
		if (triangle.perimeter() > circle.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;

}
std::weak_ordering compareAreaAndPerimeter(Triangle const& triangle, Rectangle const& rect)
{
	if (triangle.area() < rect.area())
	{
		if (triangle.perimeter() < rect.perimeter())
		{
			return std::weak_ordering::less;
		}
	}
	else if (triangle.area() > rect.area())
	{
		if (triangle.perimeter() > rect.perimeter())
		{
			return std::weak_ordering::greater;
		}
	}
	
	return std::weak_ordering::equivalent;

}