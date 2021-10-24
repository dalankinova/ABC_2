#include "stdafx.h"
#include "triangle.h"
#include <cmath>

Triangle::Triangle(Point first, Point second, Point third, Color color) :
    Shape (color)
{
    m_first = first;
    m_second = second;
    m_third = third;
}

double Triangle::calcArea()
{
    return 0.5 * fabs( (second().x - first().x) * (third().y - first().y) -
                       (third().x - first().x) * (second().y - first().y));
}

Point Triangle::first() const
{
    return m_first;
}

void Triangle::setFirst(const Point &first)
{
    m_first = first;
}

Point Triangle::second() const
{
    return m_second;
}

void Triangle::setSecond(const Point &second)
{
    m_second = second;
}

Point Triangle::third() const
{
    return m_third;
}

void Triangle::setThird(const Point &third)
{
    m_third = third;
}
