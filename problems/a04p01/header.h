#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <compare>

// Declarations
class Circle {
	double m_radius{ 0. };

public:
	Circle(double radius);
	double area() const;
	double perimeter() const;
};

class Rectangle {
	double m_width{ 0. };
	double m_height{ 0. };

public:
	Rectangle(double width, double height);
	double area() const;
	double perimeter() const;
};

class Triangle {
	double m_width{ 0. };
	double m_height{ 0. };

public:
	Triangle(double width, double height);
	double area() const;
	double perimeter() const;
};


// To String
std::string toString(Circle const& circle);
std::string toString(Rectangle const& rect);
std::string toString(Triangle const& triangle);


// Comparison
std::weak_ordering compareArea(Circle const& circle1, Circle const& cicle2);
std::weak_ordering compareArea(Circle const& circle, Rectangle const& rect);
std::weak_ordering compareArea(Circle const& circle, Triangle const& triangle);
std::weak_ordering compareArea(Rectangle const& rect1, Rectangle const& rect2);
std::weak_ordering compareArea(Rectangle const& rect, Circle const& circle);
std::weak_ordering compareArea(Rectangle const& rect, Triangle const& triangle);
std::weak_ordering compareArea(Triangle const& triangle1, Triangle const& triangle2);
std::weak_ordering compareArea(Triangle const& triangle, Circle const& circle);
std::weak_ordering compareArea(Triangle const& triangle, Rectangle const& rect);

std::weak_ordering comparePerimeter(Circle const& circle1, Circle const& cicle2);
std::weak_ordering comparePerimeter(Circle const& circle, Rectangle const& rect);
std::weak_ordering comparePerimeter(Circle const& circle, Triangle const& triangle);
std::weak_ordering comparePerimeter(Rectangle const& rect1, Rectangle const& rect2);
std::weak_ordering comparePerimeter(Rectangle const& rect, Circle const& circle);
std::weak_ordering comparePerimeter(Rectangle const& rect, Triangle const& triangle);
std::weak_ordering comparePerimeter(Triangle const& triangle1, Triangle const& triangle2);
std::weak_ordering comparePerimeter(Triangle const& triangle, Circle const& circle);
std::weak_ordering comparePerimeter(Triangle const& triangle, Rectangle const& rect);

std::weak_ordering compareAreaAndPerimeter(Circle const& circle1, Circle const& cicle2);
std::weak_ordering compareAreaAndPerimeter(Circle const& circle, Rectangle const& rect);
std::weak_ordering compareAreaAndPerimeter(Circle const& circle, Triangle const& triangle);
std::weak_ordering compareAreaAndPerimeter(Rectangle const& rect1, Rectangle const& rect2);
std::weak_ordering compareAreaAndPerimeter(Rectangle const& rect, Circle const& circle);
std::weak_ordering compareAreaAndPerimeter(Rectangle const& rect, Triangle const& triangle);
std::weak_ordering compareAreaAndPerimeter(Triangle const& triangle1, Triangle const& triangle2);
std::weak_ordering compareAreaAndPerimeter(Triangle const& triangle, Circle const& circle);
std::weak_ordering compareAreaAndPerimeter(Triangle const& triangle, Rectangle const& rect);

#endif // HEADER_H