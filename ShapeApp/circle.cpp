#include "stdafx.h"
#include "circle.h"

Circle::Circle(double radius, Point centre, Color color) :
    Shape (color)
{
    m_radius = radius;
    m_centre = centre;
}

double Circle::calcArea()
{
    double PI = 3.1415926;

    return PI * m_radius * m_radius;
}

double Circle::radius() const
{
    return m_radius;
}

void Circle::setRadius(double radius)
{
    m_radius = radius;
}

Point Circle::centre() const
{
    return m_centre;
}

void Circle::setCentre(const Point &centre)
{
    m_centre = centre;
}
