#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <compare>

// Abstract base class
class Shape {
public:
    // Defaulted copy&move constructors needed for pure virtual bases
    Shape() = default;
    Shape(const Shape&) = default;
    Shape(Shape&&) = default;
    Shape& operator=(const Shape&) = default;
    Shape& operator=(Shape&&) = default;
    virtual ~Shape() = default;

    // Pure virtual base functionality
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Derived classes
class Circle : public Shape {
    double m_radius{ 0. };

public:
    Circle(double radius);
    double area() const override;
    double perimeter() const override;
};

class Rectangle : public Shape {
    double m_width{ 0. };
    double m_height{ 0. };

public:
    Rectangle(double width, double height);
    double area() const override;
    double perimeter() const override;
};

class Triangle : public Shape {
    double m_width{ 0. };
    double m_height{ 0. };

public:
    Triangle(double width, double height);
    double area() const override;
    double perimeter() const override;
};

// Comparison
std::weak_ordering compareArea(Shape const& shape_one, Shape const& shape_two);
std::weak_ordering comparePerimeter(Shape const& shape_one,
    Shape const& shape_two);

#endif // HEADER_H