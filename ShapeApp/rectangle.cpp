#include "stdafx.h"
#include "rectangle.h"

Rectangle::Rectangle(Point topLeft, Point bottomRight, Color color) :
    Shape (color)
{
    m_topLeft = topLeft;
    m_bottomRight = bottomRight;
}

double Rectangle::calcArea()
{
    return (m_bottomRight.x - m_topLeft.x) * (m_bottomRight.y - m_topLeft.y);
}

Point Rectangle::topLeft() const
{
    return m_topLeft;
}

void Rectangle::setTopLeft(const Point &topLeft)
{
    m_topLeft = topLeft;
}

Point Rectangle::bottomRight() const
{
    return m_bottomRight;
}

void Rectangle::setBottomRight(const Point &bottomRight)
{
    m_bottomRight = bottomRight;
}
